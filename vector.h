#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdbool.h>
#include <stdio.h>

typedef struct vector{
    int *data;          //Указатель на элементы вектора
    size_t size;        //Размер вектора
    size_t capacity;    //Вместимость вектора
}vector;

//Возвращает структуру-дескриптор вектор из capacity значений
vector createVector(const size_t capacity);

//Освобождает память выделенную вектору
void deleteVector(vector *v);

//Изменяет кол-во памяти вместимости вектора на значение newCapacity
void reserveVector(vector *v, const size_t newCapacity);

//Удаляет элементы из контейнера, но не освобождает память
void clearVector(vector *v);

//Освобождает память выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

#endif //VECTOR_H
