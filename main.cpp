#include <stdio.h>

#include "src/Stock.h"
#include "src/BiTree.h"


int main() {
    Stock stock = Stock(100, 0.06, 0.2);

    stock.useJRVals(0.33);

    printf ("u: %.2f    d: %.2f\n", stock.getU(), stock.getD());

    BiTree *tree = stock.createTree(3);

    BiTree::printTree(tree, 0);
}