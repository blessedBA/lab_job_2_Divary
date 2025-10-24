#include "gen_header.h"

#include <stdio.h>

#define N 100

int experiment (double* radioactivity, double* time, double start_time,
                double end_time, double step)
{
    for (int index = 0; index < N; index++)
    {
        time[index] = start_time + step * index;
    }
    printf("TIME\n");
    for (int index = 0; index < N; index++)
    {
        printf("[%d] %d", time[index]);
    }

}
