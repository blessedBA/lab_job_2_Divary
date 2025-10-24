#include "gen_header.h"


int main ()
{
    double radioactivity[100] = {};
    double time[100] = {};
    double start_time = 0.0;
    double end_time = 9.9;
    double step = 0.1;
    double precision = 0.0001;

    experiment(radioactivity, time, start_time, end_time, step);



    return 0;
}
