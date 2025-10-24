#include "gen_header.h"

#define NUM_OF_POINTS 100


int main(void)
{
    double radioactivity[NUM_OF_POINTS] = {};
    double time[NUM_OF_POINTS] = {};

    const double start_time= 0.0;
    const double end_time = 9.9;
    const double step = 0.1;
    
    double precision = 0, betta = 0;
    while(scanf("%lf%lf", &precision, &betta) == 2)
    {
        static int count = 1;

        experiment(radioactivity, time, start_time, end_time, step);
        add_noise(radioactivity, NUM_OF_POINTS);

        double decay_rate = linear_equation(radioactivity, time, NUM_OF_POINTS);
        double decay_time = nonlinear_equation(radioactivity, time, NUM_OF_POINTS, precision);

        double decay_time_err = dev_exp(radioactivity, time, NUM_OF_POINTS, decay_time);
        double decay_rate_err = dev_linear(radioactivity, time, NUM_OF_POINTS, decay_rate);

        printf("test data[%d]:\n", count++);
        printf("decay rate = %lg\n", decay_rate);
        printf("decay time = %lg\n", decay_time);
        printf("time_difference = %lg\n", precision_analysis(radioactivity, time, NUM_OF_POINTS));

        putchar('\n');

    }
    return 0;
}
