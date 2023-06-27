#include "Option.h"
#include "AmericanPut.h"

AmericanPut::AmericanPut(float K, int T, Stock S, float r, int N): AmericanOption(K, T, S, r, N) {}

float AmericanPut::deriveValue(float price) {
    return K - price > 0 ? K - price : 0;
};