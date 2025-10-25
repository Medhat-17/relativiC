#include <stdio.h>
#include "../include/metric.h"

void metric_init(void) {
    // Demo: no heavy init needed for flat metric
    fprintf(stderr, "metric_init: using flat spacetime (demo)\n");
}

void metric_info(void) {
    fprintf(stderr, "Metric: flat (demo)\n");
}
