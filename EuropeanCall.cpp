#include <math.h>
#include <vector>

#include "EuropeanCall.h"
#include "Stock.h"

EuropeanCall::EuropeanCall(float K, int T, Stock S, float r, int N): K(K), T(T), stock(S), r(r), N(N) {
    dt = T/(float)N;

    p = (exp(r * dt) - stock.getD()) / (stock.getU() - stock.getD());
    disc = exp(-r * dt);
}

float EuropeanCall::calculateValue() {
    float stockPrice = stock.getPrice();
    float highestValue = stockPrice * (pow(stock.getU(), N));

    std::vector<float> stockPrices;

    // every possible value replaces an instance of an increase with a decrease
    for (int i = 0; i < N + 1; i++) {
        stockPrices.push_back(highestValue * (pow(stock.getD(), i) / (pow(stock.getU(), i))));
    }

    std::vector<float> optionPrices;

    for (int i = 0; i < N + 1; i++) {
        optionPrices.push_back(stockPrices[i] - K > 0 ? stockPrices[i] - K : 0);
    }

    // compress each pair of points by taking the weighted average of the two future prices
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            optionPrices[j] = disc * ((p * optionPrices[j]) + ((1 - p) * optionPrices[j + 1]));
        }
    }
    
    return optionPrices[0];
}