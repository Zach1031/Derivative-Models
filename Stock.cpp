#ifndef MATH
    #include <math.h>
    #define MATH
#endif

#include "Stock.h"

// class Stock {
//     private:
//         float price;
//         float u;
//         float d;

//     public:
//         Stock();

//         Stock(float price, float u, float d): price(price), u(u), d(d) {}

//         float getPrice() { return price; }
//         float getU() { return u;}
//         float getD() { return d; }

// };

Stock::Stock() {

}

Stock::Stock(float price, float u, float d): price(price), u(u), d(d) {}

float Stock::getPrice() { return price; }
float Stock::getU() { return u;}
float Stock::getD() { return d; }