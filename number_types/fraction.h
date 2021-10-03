#ifndef UNTITLED1_FRACTION_H
#define UNTITLED1_FRACTION_H

#include <iostream>

struct fraction {
    int numerator;
    int denominator;
};

bool GetInput(fraction* number, FILE* file);

double Cast(const fraction* number);

void GetRandom(fraction* number);

void GetOutput(const fraction* number, FILE* file);

#endif //UNTITLED1_FRACTION_H
