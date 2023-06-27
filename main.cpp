#include <stdio.h>

#include "src/AmericanCall.h"
#include "src/EuropeanCall.h"
#include "src/EuropeanPut.h"
#include "src/AmericanCall.h"
#include "src/AmericanPut.h"
#include "src/Stock.h"


int main() {
    Stock stock = Stock(100, 1.1, 1 / 1.1);

    AmericanPut put = AmericanPut(100, 1, stock, 0.06, 3);

    printf("The value of this call is: %.2f\n", put.calculateValue());
}