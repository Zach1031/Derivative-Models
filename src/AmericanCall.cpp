#include <math.h>

#include "Option.h"
#include "EuropeanOption.h"
#include "AmericanCall.h"

AmericanCall::AmericanCall(float K, int T, Stock S, float r, int N): AmericanOption(K, T, S, r, N) {}

float AmericanCall::deriveValue(float price) {
    return price - K > 0 ? price - K : 0;
};

