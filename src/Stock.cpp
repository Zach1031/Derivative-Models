#include <math.h>

#include "Stock.h"
#include "BiTree.h"

Stock::Stock() {

}

// calculate u and d given drift and volatility.
// since it is dependent on time steps, 
// the probs of u and d cannot be calculated yet
Stock::Stock(float price, float r, float sigma): price(price), r(r), sigma(sigma) {}

// getters and setters
float Stock::getPrice() { return price; }
float Stock::getU() { return u;}
float Stock::getD() { return d; }
float Stock::getPU() { return pu; }
float Stock::getPD() { return pd; }


// initializes values of u, d, and p based on Jarrow and Rudd paper
// probaility of shifts are equal, by the step sizes vary
void Stock::useJRVals(float deltaT) {
    u = exp(sigma * sqrt(deltaT));
    d = exp(-sigma * sqrt(deltaT));

    pu = 0.5 + (((r - (0.5*pow(sigma, 2)))/(2 * sigma)) * sqrt(deltaT));
    pd = 1 - pu;
}

// initializes values of u, d, and p based on Cox, Ross, and Rubinstein paper
// probaility of shifts are equal, by the step sizes vary
void Stock::useCRRVals(float deltaT) {
    pu = pd = 0.5;

    u = exp(((r - (0.5*pow(sigma, 2))) * deltaT ) + (sigma * sqrt(deltaT)));
    d = exp(((r - (0.5*pow(sigma, 2))) * deltaT ) - (sigma * sqrt(deltaT)));
}

// sets the values of u and d based on volatility and drift
// then returns the risk-neutral probability of increases/decreases
// float Stock::calculateProb(float deltaT) {
//     float nu = r - (0.5 * (pow(sigma, 2)));

//     float dxu = sqrt((pow(sigma, 2) * deltaT + pow((nu * deltaT), 2)));
//     float dxd = -dxu;

//     pu = 0.5 + 0.5 * (nu * deltaT / dxu);
//     pd = 1 - pu;
// }

BiTree *Stock::createTree(float N) {
    return createRoots(N, price);
}

BiTree *Stock::createRoots(float N, float val) {
    

    BiTree *node = new BiTree;
    node->val = val;
    if (N > 0) {
        node->down = createRoots(N - 1, val * d);
        node->up = createRoots(N - 1, val * u);
    }
    

    return node;

}