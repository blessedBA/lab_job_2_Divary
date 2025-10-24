#include "gen_header.h"

#include <math.h>
#include <stdio.h>


#define R_0 1
int experiment (double* radioactivity, double* time, double start_time,
                double end_time, double step)
{
    double const betta = 3.5;
    int N = 100;
    for (int index = 0; index < N; index++)
    {
        time[index] = start_time + step * index;
        if ((index != 99) && time[index + 1] >= end_time)
        {
            N = index + 1;
            break;
        }
    }
    printf("TIME\n");
    for (int index = 0; index < N; index++)
    {
        printf("[%d] %f ", index, time[index]);

    }
    for (int index = 0; index < N; index++)
    {
        radioactivity[index] = R_0 * exp((-time[index]) / betta);
    }
    printf("\n\nRADIOACTIVITY\n");
    for (int index = 0; index < N; index++)
    {
        printf("[%d] %f ", index, radioactivity[index]);
    }

    return N;
}

void add_noise (double *radioactivity, int N)
{
    for (int index = 0; index < N; index++)
    {
        
    }
}
