#include <stdio.h>
#include <math.h>
#include "../include/integrator.h"
#include "../include/photon.h"

void integrator_init(void) {
    // nothing for demo
}

void integrator_step(photon_t *p, double step) {
    // Straight-line advance: x += k * step (k spatial components assumed normalized)
    p->x[1] += p->k[1] * step;
    p->x[2] += p->k[2] * step;
    p->x[3] += p->k[3] * step;
    // simple time advance
    p->x[0] += step;
}
