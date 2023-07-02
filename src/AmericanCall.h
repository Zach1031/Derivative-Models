#ifndef AMERICANCALL
#define AMERICANCALL

#include "AmericanOption.h"

class AmericanCall: public AmericanOption {
    public:
        AmericanCall(float K, int T, Stock S, float r, int N);
        float deriveValue(float price);
};
#endif
