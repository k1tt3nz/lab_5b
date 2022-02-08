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
