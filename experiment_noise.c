#include "gen_header.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define R_0 1
#define AMPLITUDE 0.05
int experiment (double* radioactivity, double* time, double start_time,
                double end_time, double step)
{
    #ifndef NDEBUG
    assert(radioactivity && time);
    #endif

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
    
    for (int index = 0; index < N; index++)
    {
        radioactivity[index] = R_0 * exp((-time[index]) / betta);
    }
    putchar('\n');

    #ifndef NDEBUG
    assert(radioactivity && time);
    #endif

    return N;
}

void add_noise (double *radioactivity, int N)
{
    #ifndef NDEBUG
    assert(radioactivity);
    #endif

    srand((unsigned int)time(NULL));

    double min = -1;
    double max =  1;
    double randomNumber = 0.0;
    for (int index = 0; index < N; index++)
    {
        double rnd = (double)rand() / (double)RAND_MAX; // [0,1]
        randomNumber = -1.0 + rnd * 2.0;                // [-1,1]
        randomNumber = round(randomNumber * 1e5) / 1e5; // округлить до 5 знаков
        //printf("randomNumber = %.5f\n", randomNumber);
        radioactivity[index] += randomNumber * AMPLITUDE;
    }

    #ifndef NDEBUG
    assert(radioactivity);
    #endif

    return;
}
