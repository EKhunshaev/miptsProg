/*!
 * ПРограмма
 * Нулевой процесс рассылает массив данных всем процессам (и самому себе) На нулевом задан, на других он пустой
 * Рассылка на все оставшиеся процессы
 *
 *
 * Функция позволяющая отправлять всем
 * MPI_Bcast(void *buf, int count, MPI_Datatype type, int root, MPI_Comm comm);
 * root - процесс котолый всем рассылает
 *  Bcast рекурсивно отсылает данные
 *
 *
 * Равномерно расскидать массив на процессы
 * Сделать какие то операции
 * Собрать массив обратно
 * MPI_Scatter - разделяет массив, и отправляет на каждый процесс свою часть (себе тоже)
 * MPI_Scatter(void *sendBuf, int sendcount, MPI_Datatype sendtype,
 *              void *recvBuf, int recvCount, MPI_Datatype recvtype, int root, MPI_Comm comm);
 * sendBuf должен обязательно существовать на процессе root - массив который отсылается по всем процессам (сам себе тоже)
 * sendCOunt - число элементов
 * sendtype - их тип
 * recvBuf - указатель на массив в который будем получать (везде будет существовать) (отличен то sendBuf)
 * recvCount - число элементов в массиве recvCount
 * recvType - тип получения
 * root - ранк отправителя
 * comm - коммуникатор
 *
 * MPI_Gather(); Все аргументы те же (собирает в recv конечный результат)
 *
 * Задание число пи через Gather
 */

#include <stdio.h>
#include <mpi.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

int main(int argc, char **argv) {

    MPI_Init(&argc, &argv);

    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int size = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    //Без bcast
    int a[SIZE] = {0};
    double timer = 0;
    MPI_Request request;
    if (rank == 0) {
        srand(time(0));
        printf("The whole array print\n");
        for (int i = 0; i < SIZE; ++i) {
            a[i] = rand() % 100;
            printf("%d ", a[i]);
        }
        printf("\nEnd of whole array print\n");

        timer = MPI_Wtime();
        for (int i = 0; i < size; ++i) {
            MPI_Isend(a, SIZE, MPI_INT,
                      i, i, MPI_COMM_WORLD, &request);
        }

        MPI_Irecv(a, SIZE, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, MPI_STATUS_IGNORE);
        printf("I'm the %d process: ", rank);
        for (int i = 0; i < SIZE; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
    } else {
        MPI_Irecv(a, SIZE, MPI_INT, 0, rank, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, MPI_STATUS_IGNORE);

        printf("I'm the %d process: ", rank);
        for (int i = 0; i < SIZE; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Isend Irecv %lf мс", (MPI_Wtime() - timer) * 1000);
    }


    //Bcast
    int b[SIZE] = {};

    if (rank == 0) {
        printf("The whole array print\n");
        for (int i = 0; i < SIZE; ++i) {
            b[i] = rand() % 100;
            printf("%d ", b[i]);
        }
        printf("\nEnd of whole array print\n");
    }
    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) {
        timer = MPI_Wtime();
    }

    MPI_Bcast(b, SIZE, MPI_INT, 0, MPI_COMM_WORLD);

    printf("I'm the %d process: ", rank);
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");

    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) {
        printf("BCAST %lf мс\n", (MPI_Wtime() - timer) * 1000);
    }
    //BCAST END



    MPI_Finalize();
    return 0;
}