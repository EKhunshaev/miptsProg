/*!
 * @brief 10 seminar
 *
 * DMP - система с распределенной памятью
 * MPI - message passing interface
 * ПРоцессоры могут работать со своей памятью
 *
 * mpi.h - библиотека mpi
 *
 * mpicc 1.c -o proga - компиляция
 * mpirun для запуска бинарника
 *
 * C omp - 1 программа с n потоками с общими ресурсами
 * mpi - 4 программы (т.е каждый процесс может быть запущен на разных компьютерах) со своими ресурсами и тд
 *
 *
 * MPI_Barrier() - Синхронизация
 *
 * in pimpi.c description of command MPI_Isend MPI_Irecv MPI_Wait();
 */

#include <stdio.h>
#include <mpi.h>

//Нужны аргументы команджной строки
int main(int argc, char **argv) {
    /* => нужно сделать процессы разными внутри программы */

    MPI_Init(&argc, &argv); //Начало параллельной секции
    //Параллельность из двух частей (Доступ к данным и различить процессы)
    int rank = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);   //Какой процесс (0 если все хорошо и -1 если все плохо а значение по указателю)

    int size = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &size);   //Сколько всего процессов (0 если все хорошо и -1 если все плохо а значение по указателю)

    MPI_Request request;
    //Передата точка точка (один процесс другому)
    // Нужно чтобы один посылал всем
    if (rank == 0) {
        char str[] = "Jam a man of fortune, and J must seek my fortune!";
        MPI_Isend(str, 50, MPI_CHAR, 1, 1, MPI_COMM_WORLD, &request);
    } else if (rank == 1) {
        char dest[100] = {};
        MPI_Irecv(dest, 50, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, MPI_STATUS_IGNORE);
        printf("I'm the %d prog and get message\n%s\n", rank, dest);
    }

    //Функции поссылки и получения информации
    /*Есть коснтанты
     * MPI_INT - int
     * MPI_DOUBLE
     * MPI_CHAR
     * и т.д для стандартных типов (передаваемый тип)
     */
    // b - указатель на начало передаваемого массива, count - количество передаваемых элементов, type - тип, dest - ранк процесса получателя, tag - любое число (тег) для фильтрации
    //comm - коммуникатор, например MPI_COMM_WORLD
    // -1 если ошибка иначе количество переданных байт
    //MPI_Send(void *bnf, int count, MPI_Datatype type, int dest, int tag, MPI_Comm comm); Перессылка данных

    //source - номер источника (MPI_ANY_SOURCE - от любого источника), tag - по которому полчаем сообщение (MPI_ANY_TAG)
    //MPI_STATUS_IGNORE - в качестве статуса чтобы не заморачиваться
    //MPI_Recv(bnf, count, type, source, tag, comm, &status);

    //MPI_Wtime() - возвращает время

    MPI_Finalize(); //Конец параллельной секции

    return 0;
}