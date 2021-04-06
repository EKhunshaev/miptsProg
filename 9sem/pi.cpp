/*!
 * @file pi.cpp
 * @brief Вычисление числа Пи
 *
 * @details
 * Программа вычисляет число пи тремя способами
 * 1) последовательно
 * 2) через pragma omp parallel
 * 3) через pragma omp parallel for
 *
 * Вычисление числа пи как площадь единичной окружности (через прямоугольники (интеграл))
 */

#include <omp.h>
#include <stdio.h>
#include <math.h>
#define MELKOST 500000000
#define PI 3.1415926535 ///< 10 знаков после запятой числа пи
//Число пи = 3,1415926535897932384626433832795
int main() {
    printf("The real PI = %.10lf\n", PI);
    double pi = 0;
    double n = MELKOST;
    double time = omp_get_wtime();
    //Напрямую
    for (double i = 1; i <= n; i++) {
        pi += 4 / n * sqrt(1 - i / n * i / n);
    }
    printf("Напрямую pi = %.10lf - %lf мс\n", pi, (omp_get_wtime() - time) * 1000);

    //pragma omp parallel
    double arrPi[4] = {0};
    time = omp_get_wtime();
#pragma omp parallel
    {
        int nThread = omp_get_num_threads();
        int thr = omp_get_thread_num();
        for (double i = thr * (n / nThread) + 1; i <= (thr + 1) * (n / nThread); i++) {
            arrPi[thr] += 4 / n * sqrt(1 - i / n * i / n);
        }
    }
    printf("Parallel pi = %.10lf - %lf мс\n", arrPi[0] + arrPi[1] + arrPi[2] + arrPi[3], (omp_get_wtime() - time) * 1000);

    arrPi[0] = arrPi[1] = arrPi[2] = arrPi[3] = 0;
    time = omp_get_wtime();
#pragma parallel for
    for (int i = 1; i <= (int) n; i++) {
        arrPi[omp_get_thread_num()] += 4 / n * sqrt(1 - i / n * i / n);
    }
    printf("Parallel for pi = %.10lf - %lf мс\n", arrPi[0] + arrPi[1] + arrPi[2] + arrPi[3], (omp_get_wtime() - time) * 1000);


    return 0;
}