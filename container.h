#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H

#include "number_types/number.h"

#define MAX_SIZE 10000

struct container {
    int length;
    number* numbers[MAX_SIZE + 1];
};

container* Create();

void Clear(container* container);

bool Append(container* container, const number* num);

void GetOutput(const container* container, FILE* file);

bool GetInput(container* container, FILE* file);

void Sort(container* container);

bool GetRandom(container* container, int size, FILE* file);

#endif //PROJECT_CONTAINER_H
