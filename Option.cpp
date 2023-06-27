#include <math.h>
#include <vector>

#include "Option.h"
#include "Stock.h"

Option::Option(float K, int T, Stock S, float r, int N): K(K), T(T), stock(S), r(r), N(N) {
    dt = T/(float)N;

    p = (exp(r * dt) - stock.getD()) / (stock.getU() - stock.getD());
    disc = exp(-r * dt);
}