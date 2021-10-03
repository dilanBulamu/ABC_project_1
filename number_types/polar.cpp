#include "polar.h"
#include "../random.h"

bool GetInput(polar* polar, FILE* file) {
    double angle;

    if (fscanf(file, "%lf", &angle) != 1) {
        printf("Некорректные данные.\n");
        return false;
    }

    polar->angle = angle;

    return GetInput(&polar->coordinates, file);
}

double Cast(const polar* polar) {
    return sqrt(polar->coordinates.x * polar->coordinates.x + polar->coordinates.y * polar->coordinates.y);
}

void GetRandom(polar* number) {
    number->angle = GetRandomDouble(0, 100);
    GetRandom(&number->coordinates);
}

void GetOutput(const polar* number, FILE* file) {
    fprintf(file, "Полярное число: w=%lf; coordinates=", number->angle);
    GetOutput(&number->coordinates, file);
    fprintf(file, "  .Вещественное представление: %lf\n", Cast((number)));
}