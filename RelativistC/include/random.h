#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>

// Thread-safe xorshift64* RNG: seed per-thread
void rng_seed(unsigned long long seed);
unsigned long long rng_next(void);
double rng_uniform(void); // [0,1)

#endif // RANDOM_H
