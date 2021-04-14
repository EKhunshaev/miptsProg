#include <stdio.h>
#include <mpi.h>
#include <math.h>

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

    double pi = 0;
    double n = MELKOST;
    if (rank == 0) {
        double time = MPI_Wtime();
        for (double i = 1; i <= n / size; i++) {
            pi +=  4 / n * sqrt(1 - i / n * i / n);
        }

        double piLoc = 0;
        for (int i = 1; i < size; ++i) {
            MPI_Recv(&piLoc, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            pi += piLoc;
            piLoc = 0;
        }

        printf("THe pi is %.10lf\nThe real is %.10lf\nIt took %lf ms\n", pi, PI, (MPI_Wtime() - time) * 1000);
    } else {
        for (double i = rank * n / size + 1; i <= (rank + 1) * n / size; i++) {
            pi +=  4 / n * sqrt(1 - i / n * i / n);
        }
        MPI_Send(&pi, 1, MPI_DOUBLE, 0, rank, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}