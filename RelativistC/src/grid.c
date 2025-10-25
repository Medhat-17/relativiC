#include "../include/grid.h"
#include <math.h>
#include <stdio.h>

void grid_init(void) {
    fprintf(stderr, "grid_init: demo density field set up\n");
}

double grid_get_density(double x, double y, double z) {
    // Simple Gaussian density centered at origin
    double r2 = x*x + y*y + z*z;
    return exp(-r2 / 4.0); // peak density = 1 at origin
}
