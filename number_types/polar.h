#ifndef UNTITLED1_POLAR_H
#define UNTITLED1_POLAR_H

#include <iostream>
#include "point.h"
#include "math.h"
struct polar {
    double angle;
    point coordinates;
};

bool GetInput(polar* polar, FILE* file);

double Cast(const polar* polar);

void GetRandom(polar* number);

void GetOutput(const polar* number, FILE* file);

#endif //UNTITLED1_POLAR_H
