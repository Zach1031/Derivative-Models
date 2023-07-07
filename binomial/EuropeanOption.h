#ifndef EUROPEANOPTION
#define EUROPEANOPTION

#include "Option.h"
#include "Stock.h"

class EuropeanOption: public Option {
    private:
        
    protected:
    
    public:
        EuropeanOption(float K, int T, Stock S, float r, int N);
        
        float calculateValue();

        void assignTree(BiTree *root); // fills tree and assigns the tree to be the options current tree
        //void fillTree(BiTree *root); // helper function for calculate value
        virtual float deriveValue(float price) = 0;
        float updateValue(BiTree *root);
};
#endif