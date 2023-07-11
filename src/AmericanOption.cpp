#include <math.h>
#include <vector>
#include <algorithm>

#include "Option.h"
#include "AmericanOption.h"
#include "Stock.h"

AmericanOption::AmericanOption(float K, int T, Stock S, float r, int N): Option(K, T, S, r, N) {
    dt = T/(float)N;
}

void AmericanOption::assignTree(BiTree *root) {
    Option::fillTree(root);
    tree = root;
}

float AmericanOption::updateValue(BiTree *node) {
    return std::max(deriveValue(node->sVal) , exp((-stock.getR() + stock.getContYield()) * dt) * ((stock.getPU() * node->up->cVal) + (stock.getPD() * node->down->cVal)));
};