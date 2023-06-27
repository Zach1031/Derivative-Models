#include <stdio.h>

#include "EuropeanOption.h"
#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "AmericanCall.h"
#include "AmericanPut.h"
#include "Stock.h"


int main() {
    Stock stock = Stock(100, 1.1, 1 / 1.1);

    AmericanPut put = AmericanPut(100, 1, stock, 0.06, 3);

    printf("The value of this call is: %.2f\n", put.calculateValue());
}