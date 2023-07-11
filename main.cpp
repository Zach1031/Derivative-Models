#include <stdio.h>

#include "src/Stock.h"
#include "src/BiTree.h"

#include "src/EuropeanOption.h"
#include "src/EuropeanCall.h"

#include "src/Simulation.h"


int main() {
    Stock stock(100, 0.06, 0.2);

    // stock.useJRVals(0.33);

    stock.setContYield(0.03);
    
    

    EuropeanCall call(100, 1, stock, 0.06, 10);

    Simulation sim(stock, 1, 10);

    printf("%.2f\n", sim.runSimulationAntithetic(&call, 600000));

}