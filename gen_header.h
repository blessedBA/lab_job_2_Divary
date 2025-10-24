#ifndef GEN_HEADER_H
#define GEN_HEADER_H

int experiment (double *radioactivity, double *time, double start_time,
                double end_time, double step);
void add_noise (double *radioactivity, int N);

#endif // GEN_HEADER_H
