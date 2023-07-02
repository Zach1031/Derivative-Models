#ifndef OPTION
#define OPTION

#include "Stock.h"

class Option {
    protected:
        float K; // strike price
        int T; // time until expiration
        float S; // Underlying stock price
        float r; // risk-free interest rate
        int N; // binomial steps until expiration 

        float dt; // change in time per step

        float disc; // value of risk-free rate compounded continuously 
 
        float p; // risk-neutral probability

        Stock stock; // associated stock
        BiTree *tree; // binomial tree of stock prices and associated option prices

    public:
        Option(float K, int T, Stock S, float r, int N);
        
        
        float calculateValue();

        void fillTree(BiTree *root); // helper function for calculate value
        virtual float deriveValue(float price) = 0; // determine value of the option (i.e. whether option is call or put)
        virtual float updateValue(BiTree *node) = 0; // helps calculate the current option value based on option type rules

        //getters
        BiTree *getTree();

        // the greeks
        float delta(); // delta is calculated one step ahead by default
        float delta(int n); // calculate delta n steps ahead
        float gamma();
        float vega();
        float rho();
};
#endif