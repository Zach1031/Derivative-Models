#include <math.h>
#include <vector>

#include "Option.h"
#include "EuropeanOption.h"
#include "Stock.h"

EuropeanOption::EuropeanOption(float K, int T, Stock S, float r, int N): Option(K, T, S, r, N) {
    dt = T/(float)N;

    p = (exp(r * dt) - stock.getD()) / (stock.getU() - stock.getD());
    disc = exp(-r * dt);
}

float EuropeanOption::calculateValue() {
    float stockPrice = stock.getPrice();
    float highestValue = stockPrice * (pow(stock.getU(), N));

    std::vector<float> stockPrices;

    float u = stock.getU();
    float d = stock.getD();
    float pu = stock.getPU();
    float pd = stock.getPD();

    // every possible value replaces an instance of an increase with a decrease
    for (int i = 0; i < N + 1; i++) {
        stockPrices.push_back(highestValue * (pow(d, i) / (pow(u, i))));
    }

    std::vector<float> optionPrices;

    for (int i = 0; i < N + 1; i++) {
        optionPrices.push_back(deriveValue(stockPrices[i]));
    }

    // compress each pair of points by taking the weighted average of the two future prices
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            optionPrices[j] = disc * ((pu * optionPrices[j]) + (pd * optionPrices[j + 1]));
        }
    }
    
    return optionPrices[0];
}