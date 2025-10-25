#ifndef PARALLEL_H
#define PARALLEL_H

// Parallel utilities (OpenMP wrapper).
// Nothing fancy: presence of OpenMP is handled at compile-time.

int parallel_get_max_threads(void);

#endif // PARALLEL_H
