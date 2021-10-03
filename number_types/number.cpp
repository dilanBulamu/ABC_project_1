#include "number.h"

bool GetInput(number* num, FILE* file) {
    int type = 0;

    fscanf(file, "%d'\n", &type);

    switch (type) {
        case number::COMPLEX:
            num->number_type = number::COMPLEX;
            return GetInput(&num->complex, file);
        case number::FRACTION:
            num->number_type = number::FRACTION;
            return GetInput(&num->fraction, file);
        case number::POLAR:
            num->number_type = number::POLAR;
            return GetInput(&num->polar, file);
        default:
            printf("Некорректные данные.\n");
            return false;
    }
}

void GetOutput(const number* num, FILE* file){
    switch (num->number_type) {
        case number::COMPLEX:
            GetOutput(&num->complex, file);
            return;
        case number::FRACTION:
            GetOutput(&num->fraction, file);
            return;
        case number::POLAR:
            GetOutput(&num->polar, file);
            return;
        default:
            printf("Некорректные данные.\n");
    }
}

double Cast(const number* num){
    switch (num->number_type) {
        case number::COMPLEX:
            return Cast(&num->complex);
        case number::FRACTION:
            return Cast(&num->fraction);
        case number::POLAR:
            return Cast(&num->polar);
        default:
            return 0.0;
    }
}