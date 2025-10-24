#include "gen_header.h"
#include <stdio.h>
#include <assert.h>


double linear_equation(double * radioactivity, double * time, int N)
{
    assert(radioactivity != NULL);
    assert(time != NULL);
    assert(N > 0);

    double sum_t_square = 0;
    double denominator = 0;
    
    for (int i = 0; i < N; i++)
    {
        sum_t_square += time[i] * time[i];
        denominator += time[i] * (1 - radioactivity[i]);
    }

    double decay_rate = sum_t_square / denominator;
    return decay_rate;
}