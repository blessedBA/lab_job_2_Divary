#include "gen_header.h"

#include <assert.h>
#include <math.h>

/*
передаем указатель на массив экспериментальных данных и массив аргу-
ментов, количество элементов массива, значение, в котором необходимо
найти значение функции, возвращает значение функции в данной точке.
*/

double model(double *radioactivity, double *time, const int N, double point)
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

/*
передаем указатель на массив экспериментальных дан-
ных и массив аргументов, количество элементов массива и точность ре-
шения нелинейного уравнения Ɛ (precision). Функция возвращает значе-
ние decay_time, который является корнем нелинейного уравнения, решен-
ного методом деления отрезка пополам. Эта функция, в свою очередь,
обращается к функции, в которой вычисляется значение функции, ноль
которой мы ищем в текущей точке интервала
*/

//returns decay time
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
