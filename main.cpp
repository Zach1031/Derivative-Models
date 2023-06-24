#include <stdio.h>

#include "EuropeanCall.h"
#include "Stock.h"


int main() {
    Stock stock = Stock(100, 1.1, 1 / 1.1);

    EuropeanCall call = EuropeanCall(100, 1, stock, 0.06, 3);

    printf("The value of this call is: %.2f\n", call.calculateValue());
}