#include "../include/compton.h"
#include "../include/random.h"
#include <math.h>

int compton_scatter(photon_t *p, unsigned int *seed) {
    // Demo placeholder: random small deflection and small energy change
    double phi = 2.0 * 3.141592653589793 * rng_uniform();
    double cos_theta = 1.0 - 0.1 * rng_uniform(); // small-angle bias
    double sin_theta = sqrt(1.0 - cos_theta*cos_theta);
    double ux = sin_theta * cos(phi);
    double uy = sin_theta * sin(phi);
    double uz = cos_theta;

    // rotate direction approximately (naive)
    p->k[1] += ux * 0.1;
    p->k[2] += uy * 0.1;
    p->k[3] += uz * 0.1;
    // renormalize
    double n = sqrt(p->k[1]*p->k[1] + p->k[2]*p->k[2] + p->k[3]*p->k[3]);
    if (n > 0.0) {
        p->k[1] /= n; p->k[2] /= n; p->k[3] /= n;
    }
    // small energy loss/gain
    p->energy *= (1.0 - 0.01 * (rng_uniform() - 0.5));
    return 1;
}
