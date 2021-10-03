#include "container.h"
#include "random.h"

container* Create(){
    container* new_container = (container*) malloc(sizeof(container));
    new_container->length = 0;

    for(int i = 0; i < MAX_SIZE; ++i){
        new_container->numbers[i] = NULL;
    }

    return new_container;
}

void Clear(container* container) {
    for (int i = 0; i < container->length; ++i) {
        delete container->numbers[i];
    }
    container->length = 0;
    delete container;
}

bool Append(container* container, const number* num) {
    if (MAX_SIZE <= container->length) {
        printf("Контейнер переполнен.");
        return false;
    }
    if (container->numbers[container->length] == NULL) {
        container->numbers[container->length] = (number*) malloc(sizeof(number));
    }
    container->numbers[container->length]->number_type = num->number_type;
    container->numbers[container->length]->complex = num->complex;
    container->numbers[container->length]->fraction = num->fraction;
    container->numbers[container->length]->polar = num->polar;

    container->length++;
    return 0;
}

void GetOutput(const container* container, FILE* file){
    for(int i = 1; i < container->length + 1; ++i){
        fprintf(file, "%d: ", i);
        GetOutput(container->numbers[i - 1], file);
    }
}

bool GetInput(container* container, FILE* file) {
    int count;
    if (fscanf(file, "%d\n", &count) != 1) {
        printf("Некорректные данные.\n");
        return false;
    } else if (count <= 0) {
        printf("Количество элементов не может быть <= 0.\n");
        return false;
    } else if (count > MAX_SIZE) {
        printf("Перебор с количесвтом элементов, допустимый максимум: %d.\n", MAX_SIZE);
        return false;
    }

    for(int i = 0; i < count; ++i){
        number num{};
        if (!GetInput(&num, file)){
            printf("Не получилось распарсить %d число.\n", i + 1);
        }
        Append(container, &num);
    }
    return true;
}

bool GetRandom(container* container, int size, FILE* file) {
    if (size > MAX_SIZE){
        printf("Перебор с количесвтом элементов, допустимый максимум: %d.\n", MAX_SIZE);
        return false;
    } else if (file) {
        fprintf(file, "%d\n", size);
    }

    for(int i = 0; i < size; ++i){
        number num{};
        int type = GetRandomInt(0, 3);
        if (file) {
            fprintf(file, "%d\n", type);
        }

        switch (type) {
            case number::COMPLEX:
                num.number_type = number::COMPLEX;
                GetRandom(&num.complex);
                if (file) {
                    fprintf(file, "%g %g\n", num.complex.real, num.complex.imaginary);
                }
                break;
            case number::FRACTION:
                num.number_type = number::FRACTION;
                GetRandom(&num.fraction);
                if (file) {
                    fprintf(file, "%d %d\n", num.fraction.numerator, num.fraction.denominator);
                }
                break;
            case number::POLAR:
                num.number_type = number::POLAR;
                GetRandom(&num.polar);
                if (file) {
                    fprintf(file, "%g %d %d\n", num.polar.angle, num.polar.coordinates.x, num.polar.coordinates.y);
                }
                break;
        }
        Append(container, &num);
    }
    return true;
}

void Sort(container* container) {
    for(int i = 0; i < container->length; ++i) {
        number* buffer = container->numbers[i];
        int j = i;
        for (; j > 0 && Cast(container->numbers[j-1]) > Cast(buffer); --j) {
            container->numbers[j] = container->numbers[j-1];
        }
        container->numbers[j] = buffer;
    }
}