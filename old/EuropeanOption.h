#ifndef EUROPEANOPTION
#define EUROPEANOPTION

#include "Stock.h"

class EuropeanOption: public Option {
    protected:
    
    public:
        EuropeanOption(float K, int T, Stock S, float r, int N);
        
        float calculateValue();

        virtual float deriveValue(float price) = 0;
};
#endif