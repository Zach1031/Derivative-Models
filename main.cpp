#include <stdio.h>

#include "binomial/Stock.h"
#include "binomial/BiTree.h"

#include "binomial/EuropeanOption.h"
#include "binomial/EuropeanCall.h"

#include "monte_carlo/Simulation.h"


int main() {
    Stock stock(100, 0.06, 0.2);

    // stock.useJRVals(0.33);

    stock.setPU(0.5820);
    stock.setPD(1 - 0.5820);
    stock.setU(1.1);
    stock.setD(1 / 1.1);
    

    EuropeanCall call(100, 1, stock, 0.06, 3);

    Simulation sim(stock, 1, 10);

    printf("%.2f\n", sim.runSimulation(&call, 100));

}