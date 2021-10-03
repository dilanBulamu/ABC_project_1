#include "point.h"
#include "../random.h"

bool GetInput(point* coordinates, FILE* file) {
    int x, y;

    if (fscanf(file, "%d %d", &x, &y) != 2) {
        printf("Некорректные данные.\n");
        return false;
    }

    coordinates->x = x;
    coordinates->y = y;

    return true;
}

void GetRandom(point* coordinates) {
    coordinates->x = GetRandomInt(-1000, 1000);
    coordinates->y = GetRandomInt(-1000, 1000);
}

void GetOutput(const point* coordinates, FILE* file) {
    fprintf(file, "(%d, %d)", coordinates->x, coordinates->y);
}
