#ifndef STOCK
#define STOCK

class Stock {
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

        void useCRRVals(float deltaT);
        void useJRVals(float deltaT);

        float calculateProb(float deltaT);

};
#endif