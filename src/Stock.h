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

        float contYield; // continuous dividend yield

        float discYield; // discrete dividend yield
        int discYieldTime; // when the discrete dividend is payed out

    public:
        Stock();
        Stock(float price, float r, float sigma);
        Stock(float price, float r, float sigma, float contYield);
        Stock(float price, float r, float sigma, float discYield, int discYieldTime);
        
        float getPrice();
        float getU();
        float getD();
        float getPU();
        float getPD();

        float getR();
        float getSigma();

        float getContYield();
        
        float getDiscYield();
        float getDiscYieldTime();

        void useCRRVals(float deltaT);
        void useJRVals(float deltaT);

        float calculateProb(float deltaT);

        BiTree *createTree(float N);

        

};
#endif