#ifndef AMERICANOPTION
#define AMERICANOPTION

#include "Option.h"
#include "Stock.h"

class AmericanOption: public Option {
    protected:
        // float K; // strike price
        // int T; // time until expiration
        // float S; // Underlying stock price
        // float r; // risk-free interest rate
        // int N; // binomial steps until expiration 

        // float u; // average increase
        // float d; // average decrease

        // float dt; // change in time per step

        // float disc; // value of risk-free rate compounded continuously 
 
        // float p; // risk-neutral probability

        // Stock stock; // associated stock
    
    public:
        AmericanOption(float K, int T, Stock S, float r, int N);
        
        float calculateValue();

        virtual float deriveValue(float price) = 0;
};
#endif