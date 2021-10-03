#include "complex.h"
#include "../random.h"

bool GetInput(complex* number, FILE* file) {
    double imaginary, real;
    if (fscanf(file, "%lf %lf", &imaginary, &real) != 2) {
        printf("Некорректные данные.\n");
        return false;
    }

    number->imaginary = imaginary;
    number->real = real;

    return true;
}

double Cast(const complex* number) {
    return sqrt(number->real * number->real + number->imaginary * number->imaginary);
}

void GetRandom(complex* number) {
    number->real = GetRandomDouble(-1000, 1000);
    number->imaginary = GetRandomDouble(-1000, 1000);
}

void GetOutput(const complex* number, FILE* file) {
    fprintf(file, "Комплексное число: (%lf, %lf) .Вещественное представление: %lf\n", number->real, number->imaginary, Cast(number));
}
