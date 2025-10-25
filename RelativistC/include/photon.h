#ifndef PHOTON_H
#define PHOTON_H

#include "constants.h"

typedef struct {
    double x[4];    // position (t, x, y, z) - t may be unused in demo
    double k[4];    // 4-momentum (k^t, k^x, k^y, k^z)
    double energy;  // photon energy [erg]
    double weight;  // statistical weight
    int alive;      // 1 if photon is still being tracked
} photon_t;

photon_t photon_create(double energy, unsigned int *seed);
void photon_free(photon_t *p);

#endif // PHOTON_H
