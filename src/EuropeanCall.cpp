#include "Option.h"
#include "EuropeanOption.h"
#include "EuropeanCall.h"

EuropeanCall::EuropeanCall(float K, int T, Stock S, float r, int N): EuropeanOption(K, T, S, r, N) {}

float EuropeanCall::deriveValue(float price) {
    return price - K > 0 ? price - K : 0;
};