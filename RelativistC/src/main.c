#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#include "../include/constants.h"
#include "../include/metric.h"
#include "../include/integrator.h"
#include "../include/photon.h"
#include "../include/random.h"
#include "../include/compton.h"
#include "../include/grid.h"
#include "../include/parallel.h"
#include "../include/io.h"

int main(int argc, char **argv) {
    long num_packets = 1000000;
    int threads = 0;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-n") == 0 && i+1 < argc) num_packets = atol(argv[++i]);
        else if (strcmp(argv[i], "-t") == 0 && i+1 < argc) threads = atoi(argv[++i]);
    }

    if (threads > 0) omp_set_num_threads(threads);

    printf("RelativistC demo starting...\n");
    metric_init();
    integrator_init();
    grid_init();

    double tally = 0.0;
    long np = num_packets;

    #pragma omp parallel
    {
        unsigned int tid = (unsigned int) omp_get_thread_num();
        unsigned long long seed = 1469598103934665603ULL ^ (unsigned long long)(tid + 1);
        rng_seed(seed);

        #pragma omp for reduction(+:tally) schedule(dynamic, 1024)
        for (long i = 0; i < np; ++i) {
            // create photon with unit energy (erg)
            unsigned int useed = (unsigned int)(rng_next() & 0xFFFFFFFFu);
            photon_t p = photon_create(1.0, &useed);

            // simple tracking loop: step until photon leaves domain or reaches max steps
            int steps = 0;
            while (p.alive && steps < 1000) {
                integrator_step(&p, 0.1); // small affine step
                // small probability of scattering per step (demo)
                double density = grid_get_density(p.x[1], p.x[2], p.x[3]);
                double prob = density * 0.01;
                double u = rng_uniform();
                if (u < prob) {
                    compton_scatter(&p, &useed);
                }
                // accumulate energy leaving region as tally (demo)
                if (p.x[1] > 10.0 || p.x[1] < -10.0) { p.alive = 0; tally += p.energy * p.weight; }
                steps++;
            }
            photon_free(&p);
        }
    }

    int used_threads = parallel_get_max_threads();
    printf("Done. packets=%ld threads=%d total_energy=%.6e\n", np, used_threads, tally);
    io_write_output("relativistc_output.dat", tally, np, used_threads);
    return 0;
}
