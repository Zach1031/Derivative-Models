#include <stdio.h>

#include "src/Stock.h"
#include "src/BiTree.h"

#include "src/EuropeanOption.h"
#include "src/EuropeanCall.h"


int main() {
    Stock stock = Stock(100, 0.06, 0.2);

    stock.useJRVals(0.33);

    // intentional assignment for testing


    printf ("u: %.2f    d: %.2f\n", stock.getU(), stock.getD());

    BiTree *tree = stock.createTree(3);

    EuropeanCall option = EuropeanCall(100, 1, stock, 0.06, 3);

    option.assignTree(tree);

    BiTree::printTree(option.getTree(), 0);

    printf("delta: %.2f\n", option.delta());
    printf("gamma: %.2f\n", option.gamma());
    printf("vega: %.2f\n", option.vega());
    printf("rho: %.2f\n", option.rho());
}