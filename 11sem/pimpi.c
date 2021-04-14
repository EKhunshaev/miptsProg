/*!
 * @file pimpi.c
 *
 * MPI_Send и MPI_Recv - блокирующие команды, (останаливаются процессы пока кто то не получит или не отправит)
 * Ниже приведеные команды выполняются без блокировки
 * int MPI_Isend(void *buf, int count, type, dest, tag, comm, *request);
 * request - информация об отправке данных
 * int MPI_Irecv(void *buf, int count, type, src, tag, comm, *request);
 *
 * //Wait - блокирует пока Irecv или Isend не выполнятся до конца
 * MPI_Wait(request, status (MPI_STATUS_IGNORE)); //Синхронизация для Irecv поотму что данные могут ыть не получены
 * request type: MPI_Request
 *
 */

#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <malloc.h>

#define MELKOST 100000000
#define PI 3.1415926535

int main(int argc, char **argv) {
//    double pi1 = 0;
//    double n1 = MELKOST;
//    double time1 = MPI_Wtime();
//    //Напрямую
//    for (double i = 1; i <= n1; i++) {
//        pi1 += 4 / n1 * sqrt(1 - i / n1 * i / n1);
//    }
//    printf("Напрямую pi = %.10lf - %lf мс\n", pi1, (MPI_Wtime() - time1) * 1000);


    MPI_Init(&argc, &argv);

    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int size = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    //printf("size of threads is %d\n", size);

    double pi = 0;
    double n = MELKOST;
    double *piArr = (double *) malloc(sizeof(double) * size);
    if (rank == 0) {
        printf("The real PI %.10lf\n", PI);
    }
    //Scatter Gather
    MPI_Barrier(MPI_COMM_WORLD);
    double timer = 0;
    if (rank == 0) {
        timer = MPI_Wtime();
    }

    for (double i = rank * n / size + 1; i <= (rank + 1) * n / size; i++) {
        pi +=  4 / n * sqrt(1 - i / n * i / n);
    }

    MPI_Gather(&pi, 1, MPI_DOUBLE, piArr, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        double res;
        for (int i = 0; i < size; ++i) {
            res += piArr[i];
            printf("piArr %d = %lf\n", i, piArr[i]);
        }
        printf("The founded Pi is %.10lf\nIt took %lf мс\n", res, MPI_Wtime() - timer);
    }
    free(piArr);
    MPI_Finalize();

    return 0;
}