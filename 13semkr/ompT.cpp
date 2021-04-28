#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <mpi.h>

using namespace std;
//Определение констант
#define A 0.01
#define XLEFT -100
#define XRIGHT 100
#define M 2000 // количество шагов по координате
#define N 100000 //по времени
//Шаги по времени и координате
#define DT 0.2
#define H ((XRIGHT - XLEFT) / (double)M)


double fCalc(const double u[M + 1], const int &m) {
    double m1 = (m == 0) ? 0 : u[m - 1];
    double m2 = u[m];
    double m3 = (m == M) ? 0 : u[m + 1];

    double res = A * A * DT / (H * H) * (m3 - 2 * m2 + m1) + m2;
    return res;
}

int main () {
    ofstream output("resultsomp.dat");
    output << "Условие Курента a^2 * dt / h^2 = " << A * A * DT / (H * H) << endl;

    if (output.is_open()) {
        //Создание массивов и задание начальных условий
        double u0[M + 1] = {};
        double u[M + 1] = {};
        for (int i = 0; i < M; ++i) {
            u0[i] = (-1 <= XLEFT + i * H && XLEFT + i * H <= 1) ? 1 : 0;
        }

        //Вычисления
        for (int n = 0; n < N; n++) {
            //Распараллеливание внутреннего цикла, внешний не можем, потому что нужно знать прошлую итерацию
            //Можем использовать parallel for т.к. используется только m-ый элемент массива u
            #pragma omp parallel for
            for (int m = 0; m <= M; m++) {
                u[m] = fCalc(u0, m);
            }

            memcpy(u0, u, M * sizeof(double));
        }

        //Вывод в файл в формате координата : значение
        for (int m = 0; m <= M; ++m) {
            output << setw(5) << XLEFT + m * H << " : " << u[m] << endl;
        }

    } else {
        cerr << "Can't open file";
        exit(EXIT_FAILURE);
    }

    output.close();
    return 0;
}