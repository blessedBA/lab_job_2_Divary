#include "gen_header.h"

double precision_analysis(double *radioactivity, double *time, int N, double precision) {
    assert(radioactivity != NULL);
    assert(time != NULL);
    assert(N != NULL);

    double decay_rate, decay_time, i;

    for(i = 10; i < (N + 1); i ++) {
        decay_rate = linear_equation(radioactivity, time, i);
        decay_time = nonlinear_equation(radioactivity, time, i, precision);

        if ((dev_linear(radioactivity, time, i, decay_rate) * 2) < dev_exp(radioactivity, time, i, decay_time)) break;
    }

    return time[i - 1];
}

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

double dev_linear(double *radioactivity, double *time, int M, double decay_rate)
{
    assert(radioactivity != NULL);
    assert(time != NULL);
    assert(M > 0);

    double sum_residuals2 = 0.0, s2 = 0.0;
    for (int i = 0; i < M; i++)
    {
        s2 = radioactivity[i] - (1 - time[i] / decay_rate);
        sum_residuals2 += s2 * s2;
    }
    double deviation2 = sqrt(sum_residuals2) / M;
    return deviation2;
}
