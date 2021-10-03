#include "fraction.h"
#include "../random.h"

bool GetInput(fraction* number, FILE* file) {
    int numerator, denominator;

    if (fscanf(file, "%d %d", &numerator, &denominator) != 2) {
        printf("Некорректный ввод.\n");
        return false;
    }

    if (denominator == 0) {
        printf("Знаменатель не может = 0.\n");
        return false;
    }

    if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)) {
        numerator *= -1;
        denominator *= -1;
    }

    number->numerator = numerator;
    number->denominator = denominator;

    return true;
}

double Cast(const fraction* number) {
    return ((double) number->numerator) / number->denominator;
}

void GetRandom(fraction* number) {
    number->numerator = GetRandomInt(-1000, 1000);
    number->denominator = GetRandomInt(-1000, 1000);
}

void GetOutput(const fraction* number, FILE* file) {
    fprintf(file, "Дробное число: %d/%d  .Вещественное представление: %lf\n", number->numerator, number->denominator, Cast(number));
}
