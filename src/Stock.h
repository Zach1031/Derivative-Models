#ifndef STOCK
#define STOCK

class Stock {
    private:
        float price;
        float u;
        float d;

    public:
        Stock();
        Stock(float price, float u, float d);
        
        float getPrice();
        float getU();
        float getD();

};
#endif