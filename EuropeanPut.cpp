#include "EuropeanOption.h"
#include "EuropeanPut.h"

EuropeanPut::EuropeanPut(float K, int T, Stock S, float r, int N): EuropeanOption(K, T, S, r, N) {}

float EuropeanPut::deriveValue(float price) {
    return K - price > 0 ? K - price : 0;
};