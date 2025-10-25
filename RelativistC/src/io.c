#include "../include/io.h"
#include <stdio.h>

int io_read_config(const char *fname) {
    (void)fname;
    // Demo: no config reading yet
    return 0;
}

int io_write_output(const char *fname, double result, long npackets, int threads) {
    FILE *f = fopen(fname, "w");
    if (!f) return -1;
    fprintf(f, "# RelativistC output\n");    fprintf(f, "packets %ld threads %d total_energy %.12e\n", npackets, threads, result);
    fclose(f);
    return 0;
}
