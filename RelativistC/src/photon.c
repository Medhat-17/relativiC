#include <stdlib.h>
#include <string.h>
#include "../include/photon.h"
#include "../include/random.h"

photon_t photon_create(double energy, unsigned int *seed) {
    photon_t p;
    memset(&p, 0, sizeof(photon_t));
    // start near origin, random small direction
    p.x[0] = 0.0; p.x[1] = 0.0; p.x[2] = 0.0; p.x[3] = 0.0;
    double ux = (double)rng_uniform() - 0.5;
    double uy = (double)rng_uniform() - 0.5;
    double uz = (double)rng_uniform() - 0.5;
    double norm = ux*ux + uy*uy + uz*uz;
    if (norm <= 0.0) { ux = 1.0; uy = uz = 0.0; norm = 1.0; }
    norm = sqrt(norm);
    p.k[0] = 1.0; // placeholder
    p.k[1] = ux / norm; p.k[2] = uy / norm; p.k[3] = uz / norm;
    p.energy = energy;
    p.weight = 1.0;
    p.alive = 1;
    return p;
}

void photon_free(photon_t *p) {
    (void)p; // nothing to free in demo
}
