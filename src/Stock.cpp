#include <math.h>

#include "Stock.h"
#include "BiTree.h"

Stock::Stock() {

}

// calculate u and d given drift and volatility.
// since it is dependent on time steps, 
// the probs of u and d cannot be calculated yet
Stock::Stock(float price, float r, float sigma): price(price), r(r), sigma(sigma) {}
Stock::Stock(float price, float r, float sigma, float contYield): price(price), r(r), sigma(sigma), contYield(contYield) {}
Stock::Stock(float price, float r, float sigma, float discYield, int discYieldTime): price(price), r(r), sigma(sigma), discYield(discYield), discYieldTime(discYieldTime) {}

// getters and setters
float Stock::getPrice() { return price; }
float Stock::getU() { return u;}
float Stock::getD() { return d; }
float Stock::getPU() { return pu; }
float Stock::getPD() { return pd; }
float Stock::getR() { return r; }
float Stock::getSigma() { return sigma; }
float Stock::getContYield() { return contYield; }

void Stock::setPrice(float price) { this->price = price; }
void Stock::setU(float u) { this->u = u;}
void Stock::setD(float d) { this->d = d; }
void Stock::setPU(float pu) { this->pu = pu;}
void Stock::setPD(float pd) { this->pd = pd; }
void Stock::setR(float r) { this->r = r; }
void Stock::setSigma(float sigma) {this->sigma = sigma; }
void Stock::setContYield(float contYield) {this->contYield = contYield; }



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
    node->sVal = val;
    if (N > 0) {
        node->down = createRoots(N - 1, val * d * pow(1 - discYield, discYieldTime / N));
        node->up = createRoots(N - 1, val * u * pow(1 - discYield, discYieldTime / N));
    }
    

    return node;

}