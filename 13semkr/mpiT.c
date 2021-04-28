#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>

//Определение констант (те же что и через omp)
#define A 0.01
#define XLEFT -100
#define XRIGHT 100
#define M 2000 // количество шагов по координате
#define N 100000 //по времени
//Шаги по времени и координате
#define DT 0.2
#define H ((XRIGHT - XLEFT) / (double)M)


double fCalc(double u[M], int m) {
    double m1 = (m == 0) ? 0 : u[m - 1];
    double m2 = u[m];
    double m3 = (m == M) ? 0 : u[m + 1];

    double res = A * A * DT / (H * H) * (m3 - 2 * m2 + m1) + m2;
    return res;
}

int main (int argc, char** argv) {
    FILE *fp = NULL;

    if ((fp = fopen("resultmpi.dat", "w")) != NULL) {
        fprintf(fp, "Условие Курента a^2 * dt / h^2 = %lg\n", A * A * DT / (H * H));
        //Создание массива и задание начальных условий
        double u0[M] = {};
        for (int i = 0; i < M; ++i) {
            u0[i] = (-1 <= XLEFT + i * H && XLEFT + i * H <= 1) ? 1 : 0;
        }

        MPI_Init(&argc, &argv);

        int rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        int size;
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        double *u = (double *)malloc(M / size * sizeof(double)); // у всех свой u для size потоков
        //Вычисления
        for (int n = 0; n < N; n++) {
            //Каждый процесс собирает свой u. в функции fCalc смещение для разных ранков
            for (int m = 0; m < M / size; m++) {
                u[m] = fCalc(u0, m + rank * M / size);
            }

            //функции ниже блокирующие, поэтому все процессы будут в одной итерации цикла вместе
            //Собираем массив в u0 в нулевом потоке
            MPI_Gather(u, M / size, MPI_DOUBLE, u0, M / size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
            //Обновляем u0 всем процессам
            MPI_Bcast(u0, M, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        }

        //Вывод в файл в формате координата : значение
        if (rank == 0) {
            for (int m = 0; m < M; ++m) {
                fprintf(fp, "%.1lf  :   %.2E\n", XLEFT + m * H, u0[m]);
            }
        }
        free(u); //освобождаем выделенную память
        MPI_Finalize();
    } else {
        printf("Не удалось открыть файл\n");
        return -1;
    }

    fclose(fp);
    return 0;
}
