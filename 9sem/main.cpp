/*!
 * @file main.cpp
 * @brief 9 семинар: параллельное программирование
 * @details
 * 2 подхода параллельного программирования, их преимущества и недостатки.
 * (Процессы и нити исполнения - 3 семестр (Операционные системы))
 * Недостаток процессов: fork() - низкоуровневая функция обращающаяся к ядру (не кроссплатформенный)
 *
 * 1 подход SMP - sharing memory processing
 * Разделяемая память для нескольких процессоров. Для передачи информации от одного процессора другому достаточно записать в
 * память передаваемые данные.
 * SMP - плохо масштабируем (Общая шина соединяет все ядра с памятью. Чем больше процессоров тем меньше скорость передачи)
 * (SMP - fork()) - работа с общей памятью в прошлом семестре
 *
 * 2 подход DMP - distributed memory processing
 * 2 компьютера со своими процессорами работают через сетевой интерфейс.
 * У каждого процессора своя память и данные передаются только в случае необходимости (минимизация пересылок большая скорость)
 * Мастабируемость не ограниченна
 *
 * На небольшом числе процессоров SMP лучше.
 *
 * Можно использовать оба подхода сразу (каждый компьютер в сети имеет несколько ядер)
 *
 * OpenMP - библиотека для общей памяти
 * #include <omp.h>
 *
 * Компиляция с флагом -fopenmp
 */
#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 5
int main() {

    //Использование #pragma omp parallel вывод Hello world
#pragma omp parallel //Код в скобках распаралеливается на заданное количество потоков (по умолчанию количество ядер)
    {
        printf("Hello, World!\n");
    }

    //Установка и получение количества потоков
    //Выведет один т.к. не в распараллеленом куске кода
    printf("Количество потоков: %d\n", omp_get_num_threads()); //Функция omp_get_num_threads() - возвращает количество потоков
    omp_set_num_threads(8); //Установка количества потоков
#pragma omp parallel
    {
        printf("Я поток %d, всего нас %d\n", omp_get_thread_num(), omp_get_num_threads()); //omp_get_thread_num() - возвращает текущий поток c 0
    };

    /* Задача:
     * Просумировать 2 массива:
     * Напрямую
     * через omp parallel
     * и через omp parallel for
     * Вернуть время с помощью omp_get_wtime()
     */
    int a[MAX_SIZE] = {0};
    int b[MAX_SIZE] = {0};
    int c[MAX_SIZE] = {0};
    //Напрямую
    double time = omp_get_wtime();
    for (int i = 0; i < MAX_SIZE; i++) {
        a[i] = rand() % 101;
        b[i] = rand() % 1001;
        c[i] = a[i] + b[i];
    }
    printf("Напрямую заняло %lf мс\n", (omp_get_wtime() - time) * 1000);

    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");
    //Через pragma parallel
    omp_set_num_threads(4);
    time = omp_get_wtime();
    double n;
#pragma omp parallel
    {
        n = omp_get_num_threads();
        int cur = omp_get_thread_num();
        for (int i = floor(cur * MAX_SIZE / n); i < floor((cur + 1) * MAX_SIZE / n); i++) {
            a[i] = rand() % 73;
            b[i] = rand() % 27;
            c[i] = a[i] + b[i];
        }
    };
    printf("Pragma omp parallel заняло %lf мс\n", (omp_get_wtime() - time) * 1000);

    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");

    //Parallel for
    time = omp_get_wtime();
#pragma omp parallel for //omp parallel for распараллеливает цикл for
    for (int i = 0; i < MAX_SIZE; i++) {
        a[i] = rand() % 17;
        b[i] = rand() % 113;
        c[i] = a[i] + b[i];
    }
    printf("Pragma omp parallel for заняло %lf мс\n", (omp_get_wtime() - time) * 1000);

    for (int i = 0; i < MAX_SIZE; ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");
    return 0;
}
