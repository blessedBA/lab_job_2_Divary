#ifndef GEN_HEADER_H
#define GEN_HEADER_H

#include <math.h>
#include <assert.h>
#include <stdio.h>

//experiment

int experiment (double *radioactivity, double *time, double start_time, double end_time, double step);

void add_noise (double *radioactivity, int N);



//nonlinear and linear equation

/**
 * Функция вычисления decay_rate
 *
 * @param radioactivity - массив экспериментальных данных
 * @param time - массив временных точек
 * @param N - количество элементов массива
 * @return decay_rate
 */
double linear_equation(double * radioactivity, double * time, int N);

//decay_rate
double nonlinear_equation (double *radioactivity, double *time, const int N, const double precision);

//precision_analysis:

/**
 * Функция вычисления среднеквадратичного отклонения для экспоненциальной модели
 *
 * @param radioactivity - массив экспериментальных данных
 * @param time - массив временных точек
 * @param M - количество точек на интервале
 * @param decay_rate - характерное время распада
 * @return линейное отклонение
 */
double dev_linear(double *radioactivity, double *time, int M, double decay_rate);

/**
 * Функция вычисления среднеквадратичного отклонения для экспоненциальной модели
 *
 * @param radioactivity - массив экспериментальных данных
 * @param time - массив временных точек
 * @param M - количество точек на интервале
 * @param decay_time - характерное время распада
 * @return среднеквадратичное отклонение
 */
double dev_exp(double *radioactivity, double *time, int M, double decay_time);


#endif // GEN_HEADER_H
