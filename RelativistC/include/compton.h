#ifndef COMPTON_H
#define COMPTON_H

#include "photon.h"

// Compton scattering stub: performs scattering on photon and returns 1 if scattered.
// Current demo: a placeholder that slightly perturbs direction and energy.
int compton_scatter(photon_t *p, unsigned int *seed);

#endif // COMPTON_H
