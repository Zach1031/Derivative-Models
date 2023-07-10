#ifndef SIMULATION
#define SIMULATION

#include "Stock.h"
#include "Option.h"

class Simulation {
    private:
        Stock S;
        int T;
        int N;
    
    public:
        Simulation(Stock S, int N, int T);

        float runSimulation(Option *O, int simulations);
        float runSimulationAntithetic(Option *O, int simulations);
        
};

#endif