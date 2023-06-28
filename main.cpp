#include <stdio.h>

#include "src/AmericanCall.h"
#include "src/EuropeanCall.h"
#include "src/EuropeanPut.h"
#include "src/AmericanCall.h"
#include "src/AmericanPut.h"
#include "src/Stock.h"


int main() {
    Stock stock = Stock(100, 0.06, 0.2);

    stock.useCRRVals(0.3);

    EuropeanCall put = EuropeanCall(100, 1, stock, 0.06, 3);

    printf("The value of this call is: %.2f\n", put.calculateValue());
}