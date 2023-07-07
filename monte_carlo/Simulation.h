#ifndef SIMULATION
#define SIMULATION

#include "../binomial/Stock.h"
#include "../binomial/Option.h"

class Simulation {
    private:
        Stock S;
        int T;
        int N;
    
    public:
        Simulation(Stock S, int N, int T);

        float runSimulation(Option *O, int simulations);
        
};

#endif