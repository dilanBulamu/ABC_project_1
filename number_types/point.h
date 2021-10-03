#ifndef UNTITLED1_POINT_H
#define UNTITLED1_POINT_H

#include <iostream>

struct point {
    int x;
    int y;
};

bool GetInput(point* coordinates, FILE* file);

void GetRandom(point* coordinates);

void GetOutput(const point* coordinates, FILE* file);

#endif //UNTITLED1_POINT_H
