#ifndef GEN_HEADER_H
#define GEN_HEADER_H

#include <math.h>
#include <assert.h>
#include <stdio.h>

//experiment

/**
* функция имитации эксперимента (снятия экспериментальных точек)
 * @param radioactivity - массив экспериментальных данных
 * @param time - массив временных точек
 * @param start_time - начальный момент времени (по умолчанию 0)
 * @param end_time - конечный момент времени
 * @param step - разность между двумя соседними моментами времени
 */

int experiment (double *radioactivity, double *time, double start_time,
                double end_time, double step);

/**
 * имитирует неточные значения экспериментальных
 * @param radioactivity - массив экспериментальных данных
 * @param N - число экспериментальных точек
 */

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
/**
 * Функция вычисления decay_time
 *
 * @param radioactivity - массив экспериментальных данных
 * @param time - массив временных точек
 * @param N - количество элементов массива
 * @param precision - погрешность вычисления decay_time
 * @return decay_time
 */
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

/**
 * Функция вычисления среднеквадратичного отклонения для экспоненциальной модели
 *
 * @param radioactivity - массив экспериментальных данных
 * @param time - массив временных точек
 * @param N - количество точек на интервале
 * @param precision - погрешность вычисления decay_time
 * @return значение времени, начиная с которого линейная модель не адекватно описывает процесс распада
 */
double precision_analysis(double *radioactivity, double *time, int N, double precision);

#endif // GEN_HEADER_H
