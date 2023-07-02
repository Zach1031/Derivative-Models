#ifndef EUROPEANCALL
#define EUROPEANCALL

#include "EuropeanOption.h"

class EuropeanCall: public EuropeanOption {
    public:
        EuropeanCall(float K, int T, Stock S, float r, int N);
        float deriveValue(float price);
};
#endif
