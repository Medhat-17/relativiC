#ifndef IO_H
#define IO_H

// Basic I/O helpers for config and output (demo)
int io_read_config(const char *fname);
int io_write_output(const char *fname, double result, long npackets, int threads);

#endif // IO_H
