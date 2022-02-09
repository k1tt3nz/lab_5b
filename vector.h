#ifndef VECTOR_H
#define VECTOR_H
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

//Вернет "истину", если вектор пуст, иначе - "лож"
bool isEmpty();

//Вернет "истину", вектор полный, иначе - "лож"
bool isFull();

//Возвращает i-ый элемент вектора v
int getVectorValue();

//Добавляет элемент x в конец вектора v
void pushBack();

//Удаляет последний элемент вектора
void popBack();

//Возвращает указатель на index-ный элемент вектора
int* atVector(vector *v, size_t index);

//Возвращает указатель на последний элемент вектора
int* vectorBack(vector *v);

//Возвращает указатель на нулевой элемент вектора
int* vectorFront(vector *v);

#include "vector.c"
#endif //VECTOR_H