#include <math.h>
#include <vector>

#include "AmericanOption.h"
#include "Stock.h"

AmericanOption::AmericanOption(float K, int T, Stock S, float r, int N): K(K), T(T), stock(S), r(r), N(N) {
    dt = T/(float)N;

    p = (exp(r * dt) - stock.getD()) / (stock.getU() - stock.getD());
    disc = exp(-r * dt);
}

float AmericanOption::calculateValue() {
    float stockPrice = stock.getPrice();
    float highestValue = stockPrice * (pow(stock.getU(), N));

    std::vector<float> stockPrices;

    // every possible value replaces an instance of an increase with a decrease
    for (int i = 0; i < N + 1; i++) {
        stockPrices.push_back(highestValue * (pow(stock.getD(), i) / (pow(stock.getU(), i))));
    }

    std::vector<float> optionPrices;

    for (int i = 0; i < N + 1; i++) {
        optionPrices.push_back(deriveValue(stockPrices[i]));
    }

    // compress each pair of points by taking the weighted average of the two future prices
    // early exercise also needs to be considered, so stock prices need to be adjusted
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            optionPrices[j] = disc * ((p * optionPrices[j]) + ((1 - p) * optionPrices[j + 1]));
            stockPrices[j] = stockPrices[j] / stock.getU();

            optionPrices[j] = (optionPrices[j] > (K - stockPrices[j])) ? optionPrices[j] : (K - stockPrices[j]);
        }
    }
    
    return optionPrices[0];
}