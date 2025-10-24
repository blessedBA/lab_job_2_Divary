#include "gen_header.h"

#include <assert.h>
#include <math.h>

static double model(double *radioactivity, double *time, const int N, double point)
{
    assert(radioactivity);
    assert(time);

    double model_val = 0;

    for (int i = 0; i < N; i++)
    {
        model_val += time[i] * exp(-time[i] / point) * 
        (radioactivity[i] - exp(-time[i] / point));
    }

    return model_val;
}

double nonlinear_equation (double *radioactivity, double *time, const int N, const double precision)
{
    assert(radioactivity);
    assert(time);

    const double interval1 = 0.2, interval2 = 8.2;

    double left_decay_time = interval1, right_decay_time = interval2;
    while (right_decay_time - left_decay_time > precision)
    {
        if(model(radioactivity, time, N, (right_decay_time + left_decay_time) / 2) > 0)
            right_decay_time = (left_decay_time + right_decay_time) / 2;
        
        else
            left_decay_time = (left_decay_time + right_decay_time) / 2;
    }

    return (left_decay_time + right_decay_time) / 2;
}
