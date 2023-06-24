#ifndef MATH
    #include <math.h>
    #define MATH
#endif

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Stock.h"

class EuropeanCall {
    private:
        float K; // strike price
        int T; // time until expiration
        float S; // Underlying stock price
        float r; // risk-free interest rate
        int N; // binomial steps until expiration 

        float u; // average increase
        float d; // average decrease

        float dt; // change in time per step

        float disc; // value of risk-free rate compounded continuously 
 
        float p; // risk-neutral probability

        Stock stock;
    
    public:
        EuropeanCall(float K, int T, Stock S, float r, int N): K(K), T(T), stock(S), r(r), N(N), u(u), d(d) {
            dt = T/(float)N;

            p = (exp(r * dt) - stock.getD()) / (stock.getU() - stock.getD());
            disc = exp(-r * dt);
        };
        
        // empty initializer
        // EuropeanCall();

        // amount of shares needed in underlying security to earn risk free rate
        // float risklessShares() {

        // }

        // T: time until expiration
        // N: number of branches in binomial model
        float calculateValue() {
            float stockPrice = stock.getPrice();

            float highestValue = stockPrice * (pow(stock.getU(), N));

            // associated a stock price with a option to avoid calculating twice
            // std::unordered_map<float, float> prices;

            // // every possible value replaces an instance of an increase with a decrease
            // // default price can be -1 since the smallest possible value of an option is zero
            // for (int i = 1; i < N + 1; i++) {
            //     prices[highestValue * (pow(d, i) / (pow(u, i)))] = -1;
            // }


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
};

int main() {
    Stock stock = Stock(100, 1.1, 1 / 1.1);

    EuropeanCall call = EuropeanCall(100, 1, stock, 0.06, 3);

    printf("The value of this call is: %.2f\n", call.calculateValue());
}