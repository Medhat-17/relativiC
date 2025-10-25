#include "../include/parallel.h"
#include <omp.h>

int parallel_get_max_threads(void) {
    return omp_get_max_threads();
}
