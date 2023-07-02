#ifndef EUROPEANPUTT
#define EUROPEANPUTT

#include "EuropeanOption.h"

class EuropeanPut: public EuropeanOption {
    public:
        EuropeanPut(float K, int T, Stock S, float r, int N);
        float deriveValue(float price);
};
#endif
