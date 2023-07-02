#include <math.h>
#include <vector>

#include "Option.h"
#include "EuropeanOption.h"
#include "Stock.h"

EuropeanOption::EuropeanOption(float K, int T, Stock S, float r, int N): Option(K, T, S, r, N) {
    dt = T/(float)N;
}

void EuropeanOption::assignTree(BiTree *root) {
    Option::fillTree(root);
    tree = root;
}

float EuropeanOption::updateValue(BiTree *node) {
    return exp((-stock.getR() + stock.getContYield()) * dt) * ((stock.getPU() * node->up->cVal) + (stock.getPD() * node->down->cVal));
};