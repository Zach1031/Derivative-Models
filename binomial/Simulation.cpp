#include <algorithm>
#include <random>
#include <iostream>
#include <math.h>

#include "Simulation.h"
#include "Option.h"

Simulation::Simulation(Stock S, int T, int N): S(S), T(T), N(N) {}

float Simulation::runSimulation(Option *O, int simulations) {
    float dt = O->getDT();

    float nudt = (S.getR() - S.getContYield() - (0.5 * pow(S.getSigma(), 2))) * dt;
    float sigsdt = S.getSigma() * sqrt(dt);

    // log of the price is used since the dist of S
    // is assumed to log normal
    float initLogPrice = std::log(S.getPrice());

    float sumCT = 0;
    float sumCT2 = 0;

    // set up generators for random numbers
    std::random_device seed;
    std::default_random_engine generator(seed());
    std::normal_distribution<double> distribution(0,1);

    for (int i = 0; i < simulations; i++) {
        // simulate value for stock
        float logPrice = initLogPrice;
        for (int j = 0; j < N; j++) {
            float epsilon = distribution(generator);
            logPrice += nudt + (sigsdt * epsilon);
        }

        sumCT += std::max(exp(logPrice) - O->getK(), 0.0f);
        sumCT2 += pow(exp(logPrice) - O->getK(), 2);
    }

    return sumCT / simulations;
}