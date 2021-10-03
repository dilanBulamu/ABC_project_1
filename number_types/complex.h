#ifndef UNTITLED1_COMPLEX_H
#define UNTITLED1_COMPLEX_H

#include <iostream>
#include "math.h"

struct complex {
    double imaginary, real;
};

bool GetInput(complex* number, FILE* file);

double Cast(const complex* number);

void GetRandom(complex* number);

void GetOutput(const complex* number, FILE* file);

#endif //UNTITLED1_COMPLEX_H
