#include "../include/random.h"
#include <stdint.h>
#include <math.h>

// xorshift64* implementation (fast, simple). Not cryptographic.
// Uses file-static state; rng_seed must be called per-thread before use.

static __thread unsigned long long state = 88172645463325252ULL;

void rng_seed(unsigned long long seed) {
    if (seed == 0) seed = 88172645463325252ULL;
    state = seed;
    // scramble
    state ^= state << 13;
    state ^= state >> 7;
    state ^= state << 17;
}

unsigned long long rng_next(void) {
    unsigned long long x = state;
    x ^= x >> 12;
    x ^= x << 25;
    x ^= x >> 27;
    state = x;
    return x * 2685821657736338717ULL;
}

double rng_uniform(void) {
    unsigned long long v = rng_next();
    // convert to double in [0,1)
    const double inv = 1.0 / (18446744073709551616.0); // 2^64
    return (v >> 11) * (1.0 / 9007199254740992.0); // use 53 bits
}
