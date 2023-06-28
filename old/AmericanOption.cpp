#include <math.h>
#include <vector>

#include "Option.h"
#include "AmericanOption.h"
#include "Stock.h"

AmericanOption::AmericanOption(float K, int T, Stock S, float r, int N): Option(K, T, S, r, N) {
    dt = T/(float)N;

    p = (exp(r * dt) - stock.getD()) / (stock.getU() - stock.getD());
    disc = exp(-r * dt);
}

float AmericanOption::calculateValue() {
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

    printf("U: %.2f D: %.2f\n", u, d);

    // compress each pair of points by taking the weighted average of the two future prices
    // early exercise also needs to be considered, so stock prices need to be adjusted
    for (int i = N - 1; i >= 0; i--) {
        // although this isn't the most accurate, is the most convenient way to price the greeks
        if (i == 0) {
            delta = (optionPrices[0] - optionPrices[1]) / (stockPrices[0] - stockPrices[1]);

            for (int k = 0; k < stockPrices.size(); k++) {
                printf("%d: %.2f\n", k, stockPrices[k]);
            }
        }
        
        if (i == 1) {
            gamma = (((optionPrices[0] - optionPrices[1]) / (stockPrices[0] - stockPrices[1])) 
            - ((optionPrices[1] - optionPrices[2]) / (stockPrices[1] - stockPrices[2]))) 
                    / (0.5 * (stockPrices[0] - stockPrices[2]));
        }
        for (int j = 0; j <= i; j++) {
            optionPrices[j] = disc * ((pu * optionPrices[j]) + (pd * optionPrices[j + 1]));
            stockPrices[j] = stockPrices[j] / u;

            optionPrices[j] = (optionPrices[j] > (K - stockPrices[j])) ? optionPrices[j] : (K - stockPrices[j]);
        }
    }

    return optionPrices[0];
}