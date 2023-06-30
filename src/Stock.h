#ifndef STOCK
#define STOCK

#include "BiTree.h"

class Stock {
    private:
        BiTree *createRoots(float N, float val); // helper function for createTree

    protected:
        float price; // current price of the stock
        float u; // percent change during up shift
        float d; // percent change during down shift
        
        float pu; // percent change of stock moving up
        float pd; // percent change of stock moving down

        float r; // risk free interest rate
        float sigma; // volatility

    public:
        Stock();
        Stock(float price, float r, float sigma);
        
        float getPrice();
        float getU();
        float getD();
        float getPU();
        float getPD();

        float getR();
        float getSigma();

        void useCRRVals(float deltaT);
        void useJRVals(float deltaT);

        float calculateProb(float deltaT);

        BiTree *createTree(float N);

        

};
#endif