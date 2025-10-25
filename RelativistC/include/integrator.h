#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "photon.h"

// Integrator API: advance photon along geodesic for a small affine step.
// For demo, does simple straight-line advance in flat spacetime.
void integrator_init(void);
void integrator_step(photon_t *p, double step);

#endif // INTEGRATOR_H
