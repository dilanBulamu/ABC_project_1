#ifndef UNTITLED1_NUMBER_H
#define UNTITLED1_NUMBER_H

#include "polar.h"
#include "complex.h"
#include "fraction.h"

struct number {
    enum type {
        COMPLEX,
        FRACTION,
        POLAR };

    type number_type;

    union {
        complex complex;
        fraction fraction;
        polar polar;
    };
};

bool GetInput(number* num, FILE* file);

double Cast(const number* polar);

void GetOutput(const number* num, FILE* file);

#endif //UNTITLED1_NUMBER_H
