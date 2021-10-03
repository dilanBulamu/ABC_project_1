#ifndef UNTITLED1_RANDOM_H
#define UNTITLED1_RANDOM_H

#include "random"
#include "math.h"

static int GetRandomInt(int min, int max) {
    return rand() % (max - min) + min;
}

static double GetRandomDouble(int min, int max) {
    return min + rand() % (max - min - 1) + (double) rand() / RAND_MAX;
}

#endif //UNTITLED1_RANDOM_H
