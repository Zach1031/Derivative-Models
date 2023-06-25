#include <stdio.h>

#include "EuropeanOption.h"
#include "EuropeanCall.h"
#include "EuropeanPut.h"
#include "Stock.h"


int main() {
    Stock stock = Stock(100, 1.1, 1 / 1.1);

    EuropeanPut put = EuropeanPut(100, 1, stock, 0.06, 3);

    printf("The value of this put is: %.2f\n", put.calculateValue());
}