#ifndef AMERICANPUT
#define AMERICANPUT

#include "AmericanOption.h"

class AmericanPut: public AmericanOption {
    public:
        AmericanPut();
        AmericanPut(float K, int T, Stock S, float r, int N);
        float deriveValue(float price);
};
#endif
