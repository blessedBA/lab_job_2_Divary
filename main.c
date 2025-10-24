#include "gen_header.h"


int main ()
{
    const int N = 100;
    double radioactivity[N] = {};
    double time[N] = {};
    double start_time = 0.0;
    double end_time = 9.9;
    double step = 0.1;
    double precision = 0.0001;

    experiment(radioactivity, time, start_time, end_time, step);
    add_noise(radioactivity, N);

    return 0;
}
