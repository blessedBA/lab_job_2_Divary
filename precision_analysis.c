#include "gen_header.h"

double dev_exp(double *radioactivity, double *time, int M, double decay_time) {
    assert(radioactivity != NULL);
    assert(time != NULL);
    assert(M != NULL);
    assert(decay_time != NULL);

    double sum_residuals = 0.0;

    for (int i = 0; i < M; i++) {
        double theoretical_value = exp(-time[i] / decay_time);
        double residual = radioactivity[i] - theoretical_value;
        sum_residuals += residual * residual;
    }

    double deviation = sqrt(sum_residuals / M);

    return deviation;
}
