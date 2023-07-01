#include <math.h>
#include <vector>

#include "Option.h"
#include "Stock.h"

Option::Option(float K, int T, Stock S, float r, int N): K(K), T(T), stock(S), r(r), N(N) {
    dt = T/(float)N;

    p = (exp(r * dt) - stock.getD()) / (stock.getU() - stock.getD());
    disc = exp(-r * dt);
}

float Option::delta() {
    float c_1 = tree->up->cVal; // value of option after one increase
    float c_0 = tree->down->cVal; // value of option after zero increases (a decrease)

    float s_1 = tree->up->sVal; // value of stock after one increase
    float s_0 = tree->down->sVal; // value of stock after zero increases (a decrease)

    return (c_1 - c_0) / (s_1 - s_0);
}

// TODO: delta for multiple time steps
float Option::delta(int n) {
    return 0.0;
}

// naming convention is the same as delta but for time 2
// same formula for the next three greeks as the book, although it doesn't appear to be right
// gamma should be high at the money
float Option::gamma() {
    float c_2 = tree->up->up->cVal; 
    float c_1 = tree->up->down->cVal; 
    float c_0 = tree->down->down->cVal; 

    float s_2 = tree->up->up->sVal; 
    float s_1 = tree->up->down->sVal; 
    float s_0 = tree->down->down->sVal; 

    return (((c_2 - c_1) / (s_2 - s_1)) -  ((c_1 - c_0) / (s_1 - s_0))) / (0.5 * (s_2 - s_0));
}

// both vega and rho use JR for testing, flexibility needs to be added
float Option::vega() {
    const float deltaSigma = 0.01 * stock.getSigma(); // change in stock volatility being tested
    Stock currentStock = stock;

    // new stock values and trees based to test change
    Stock increasedSigma = Stock(stock.getPrice(), stock.getR(), stock.getSigma() + deltaSigma); 
    increasedSigma.useJRVals((float)T / N);
    
    Stock decreasedSigma = Stock(stock.getPrice(), stock.getR(), stock.getSigma() - deltaSigma);
    decreasedSigma.useJRVals((float)T / N);

    BiTree *upTree = increasedSigma.createTree(N);
    BiTree *downTree = decreasedSigma.createTree(N);

    this->stock = increasedSigma;
    fillTree(upTree);
    float upValue = upTree->cVal;

    this->stock = decreasedSigma;
    fillTree(downTree);
    float downValue = downTree->cVal;

    this->stock = currentStock;
    return (upValue - downValue) / (2 * deltaSigma * 100);
}

// same process as vega but with interest rate instead of volatility
float Option::rho() {
    const float deltaR = 0.001 * stock.getR(); // change in interest being tested
    Stock currentStock = stock;

    // new stock values and trees based to test change
    Stock increasedR = Stock(stock.getPrice(), stock.getR() + deltaR, stock.getSigma()); 
    increasedR.useJRVals((float)T / N);

    Stock decreasedR = Stock(stock.getPrice(), stock.getR() - deltaR, stock.getSigma());
    decreasedR.useJRVals((float)T / N);

    BiTree *upTree = increasedR.createTree(N);
    BiTree *downTree = decreasedR.createTree(N);

    this->stock = increasedR;
    fillTree(upTree);
    float upValue = upTree->cVal;

    this->stock = decreasedR;
    fillTree(downTree);
    float downValue = downTree->cVal;

    this->stock = currentStock;
    return (upValue - downValue) / (2 * deltaR * 100);
}

BiTree *Option::getTree() {return tree;}