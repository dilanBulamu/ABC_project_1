#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include "container.h"

#define HELP    "Программу разработал Буламу Дилан группа БПИ204.\n"\
                "Домашнее задание по дисциплине архитектура вычислительных систем задание №1.\n"\
                "Для генерации случаных параметров введите -r, количество параметров и название файла формата .txt, через пробел.\n"\
                "Пример: -r 100 output.txt\n"\
                "Для открытия файла с параметрами и последующей записи в дугой файл в другом формате\n" \
                "-in названия открываемого файла и загрузочного через пробел.\n"\
                "Пример: -in test_1.txt output_1.txt"

int main(int argc, char* argv[]){
    if (argc != 4) {
        printf("Введена неверная команда.");
        return 1;
    }
    time_t start, finish;
    start = clock();
    container* container = Create();
    int size;
    if (strcmp(argv[1], "-r") == 0) {
        FILE* file = fopen(argv[3], "w");
        if (!GetRandom(container, atoi(argv[2]), file)) {
            return 1;
        }
    } else if (strcmp(argv[1], "-in") == 0) {
        if (access(argv[2], F_OK) == -1) {
            return 1;
        }
        FILE *file = fopen(argv[2], "r");
        GetInput(container, file);
        file = fopen(argv[3], "w");
        GetOutput(container, file);
        fprintf(file, "\n\n\n Отсортированные числа: \n\n");
        Sort(container);
        GetOutput(container, file);
    } else {
        printf(HELP);
        return 1;
    }
    Clear(container);
    finish = clock();
    printf("Время работы: %f\n", difftime(finish, start) / CLOCKS_PER_SEC);
    return 0;
}