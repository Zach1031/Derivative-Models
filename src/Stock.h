#ifndef STOCK
#define STOCK

class Stock {
    protected:
        float price;
        float u;
        float d;
        
        float pu;
        float pd;

        float r;
        float sigma;

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