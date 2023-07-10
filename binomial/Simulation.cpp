#include <algorithm>
#include <random>
#include <iostream>
#include <math.h>
#include <thread>

#include "Simulation.h"
#include "Option.h"

std::mutex lock; // lock variable to avoid data race

Simulation::Simulation(Stock S, int T, int N): S(S), T(T), N(N) {}

void simulate(int sims, int N, float initPrice, float nudt, float sigsdt, float &sumCT, Option *O) {
        // set up generators for random numbers
        std::random_device seed;
        std::default_random_engine generator(seed());
        std::normal_distribution<double> distribution(0,1);
        
        for (int i = 0; i < sims; i++) {
            // simulate value for stock
            float logPrice = initPrice;
            for (int j = 0; j < N; j++) {
                float epsilon = distribution(generator);
                logPrice += nudt + (sigsdt * epsilon);
            }
            lock.lock();
                sumCT += std::max(O->deriveValue(exp(logPrice)), 0.0f);
            lock.unlock();
        }
}

float Simulation::runSimulation(Option *O, int simulations) {
    float dt = O->getDT();

    float nudt = (S.getR() - S.getContYield() - (0.5 * pow(S.getSigma(), 2))) * dt;
    float sigsdt = S.getSigma() * sqrt(dt);

    // log of the price is used since the dist of S
    // is assumed to log normal
    float initLogPrice = std::log(S.getPrice());

    float sumCT = 0;

    std::vector<std::thread> threads;

    // threads set to 10 for testing
    const int THREADS = 10;
    for (int i = 0; i < THREADS; i++) {
        threads.push_back(std::thread(simulate, simulations / THREADS, N, initLogPrice, nudt, sigsdt, std::ref(sumCT), O));
    }

    for (int i = 0; i < THREADS; i++) {
        threads[i].join();
    }
    
    return sumCT / simulations * exp(-S.getR() * T);
}

void simulateAntithetic(int sims, int N, float initPrice, float nudt, float sigsdt, float &sumCT, Option *O) {
        // set up generators for random numbers
        std::random_device seed;
        std::default_random_engine generator(seed());
        std::normal_distribution<double> distribution(0,1);
        
        for (int i = 0; i < sims; i++) {
            // simulate value for stock
            float logPrice1 = initPrice;
            float logPrice2 = initPrice;
            for (int j = 0; j < N; j++) {
                float epsilon = distribution(generator);
                logPrice1 += nudt + (sigsdt * epsilon);
                logPrice2 += nudt + (sigsdt * -epsilon);
            }
            lock.lock();
                sumCT += 0.5 * (std::max(O->deriveValue(exp(logPrice1)), 0.0f), std::max(O->deriveValue(exp(logPrice2)), 0.0f));
            lock.unlock();
        }
}

float Simulation::runSimulationAntithetic(Option *O, int simulations) {
    float dt = O->getDT();

    float nudt = (S.getR() - S.getContYield() - (0.5 * pow(S.getSigma(), 2))) * dt;
    float sigsdt = S.getSigma() * sqrt(dt);

    // log of the price is used since the dist of S
    // is assumed to log normal
    float initLogPrice = std::log(S.getPrice());

    float sumCT = 0;

    std::vector<std::thread> threads;

    // threads set to 10 for testing
    const int THREADS = 10;
    for (int i = 0; i < THREADS; i++) {
        threads.push_back(std::thread(simulate, simulations / THREADS, N, initLogPrice, nudt, sigsdt, std::ref(sumCT), O));
    }

    for (int i = 0; i < THREADS; i++) {
        threads[i].join();
    }
    
    return sumCT / simulations * exp(-S.getR() * T);
}
