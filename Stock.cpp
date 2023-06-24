#ifndef MATH
    #include <math.h>
    #define MATH
#endif

#include "Stock.h"

Stock::Stock() {

}

Stock::Stock(float price, float u, float d): price(price), u(u), d(d) {}

float Stock::getPrice() { return price; }
float Stock::getU() { return u;}
float Stock::getD() { return d; }