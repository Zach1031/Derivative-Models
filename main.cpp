#include <stdio.h>

#include "src/Stock.h"
#include "src/BiTree.h"

#include "src/EuropeanOption.h"
#include "src/EuropeanCall.h"


int main() {
    Stock stock(100, 0.06, 0.2);

    // stock.useJRVals(0.33);

    stock.setPU(0.5820);
    stock.setPD(1 - 0.5820);
    stock.setU(1.1);
    stock.setD(1 / 1.1);


    printf ("u: %.2f    d: %.2f\n", stock.getU(), stock.getD());

    BiTree *tree = stock.createTree(3);

    

    EuropeanCall call(100, 1, stock, 0.06, 3);

    call.assignTree(tree);

    BiTree::printTree(tree, 0);

}