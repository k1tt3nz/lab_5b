#include <stdlib.h>
#include "vector.h"

vector createVector(const size_t capacity) {
    int *data;
    if (capacity) {
        data = (int *) malloc(sizeof(int) * capacity);
        if (data == NULL) {
            fprintf(stderr, "memory allocation error: system cannot allocate %zu bytes of memory",
                    capacity * sizeof(int));
            exit(1);
        }
    } else {
        data = NULL;
    }

    return (vector) {data, 0, capacity};
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
}

void reserveVector(vector *v, const size_t newCapacity) {
    if (newCapacity) {
        v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
        if (v->data == NULL) {
            fprintf(stderr, "memory allocation error: system cannot allocate %zu bytes of memory",
                    newCapacity * sizeof(int));
            exit(1);
        }
    } else {
        v->data = NULL;
    }
    v->capacity = newCapacity;
    if (v->size > v->capacity) {
        v->size = v->capacity;
    }
}

void clearVector(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        reserveVector(v, 1);
    } else if (isFull(v)) {
        reserveVector(v, v->capacity * 2);
    }

    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (v->size == 0) {
        printf("Error: vector is empty");
        exit(1);
    } else {
        v->size--;
    }
}

int *atVector(vector *v, size_t index) {
    if (index > v->size || index <= 0) {
        printf("IndexError: %zu is not exists", index);
    } else {
        return v->data + index;
    }
}

int *vectorBack(vector *v) {
    return atVector(v, v->size - 1);
}

int *vectorFront(vector *v) {
    return atVector(v, 0);
}