#include "gen_header.h"

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
