#include "test_ds_vector.h"
#include "vector.h"

#include <assert.h>

void test_createVector_deleteVector_NULL() {
    int capacity = 0;
    vector v = createVector(capacity);
    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == capacity);

    printf(" success\n");

    printf("delete vector:");

    deleteVector(&v);
    assert(v.data == NULL);
}

void test_createVector_deleteVector_notNULL() {
    int capacity = 666;
    vector v = createVector(capacity);
    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == capacity);

    deleteVector(&v);
    assert(v.data == NULL);
}

void test_createVector_deleteVector() {
    test_createVector_deleteVector_NULL();
    test_createVector_deleteVector_notNULL();
}

void test_reserveVector_null() {
    size_t newCapacity = 0;
    vector v = createVector(10);
    v.size = 5;
    reserveVector(&v, newCapacity);
    assert(v.data == NULL);
    assert(v.capacity == newCapacity);
    assert(v.size == v.capacity);

    deleteVector(&v);
}

void test_reserveVector_less() {
    size_t newCapacity = 5;
    vector v = createVector(newCapacity);
    v.size = 10;
    reserveVector(&v, 5);
    assert(v.data != NULL);
    assert(v.capacity == newCapacity);
    assert(v.size == newCapacity);

    deleteVector(&v);
}

void test_reserveVector_more() {
    size_t newCapacity = 100;
    vector v = createVector(10);
    v.size = 10;
    reserveVector(&v, newCapacity);
    assert(v.data != NULL);
    assert(v.capacity == newCapacity);
    assert(v.size == 10);

    deleteVector(&v);
}

void test_reserveVector_equals() {
    size_t newCapacity = 10;
    vector v = createVector(10);
    v.size = 10;
    reserveVector(&v, newCapacity);
    assert(v.data != NULL);
    assert(v.capacity == newCapacity);
    assert(v.size == 10);

    deleteVector(&v);
}

void test_reserveVector() {
    void test_reserveVector_null();
    void test_reserveVector_less();
    void test_reserveVector_more();
    void test_reserveVector_equals();
}

void test_clearVector_null() {
    vector v = {v.data, 10, 20};

    clearVector(&v);
    assert(v.size == 0);

    deleteVector(&v);
}

void test_isEmpty_empty() {
    vector v = {v.data, 0, 10};
    assert(isEmpty(&v));

    deleteVector(&v);
}

void test_isEmpty_notEmpty() {
    vector v = {v.data, 1, 10};
    assert(!isEmpty(&v));

    deleteVector(&v);
}

void test_isEmpty() {
    test_isEmpty_empty();
    test_isEmpty_notEmpty();
}

void test_isFull_full() {
    vector v = {v.data, 10, 10};
    assert(isFull(&v));

    deleteVector(&v);
}

void test_isFull_notFull() {
    vector v = {v.data, 1, 10};
    assert(!isFull(&v));

    deleteVector(&v);
}

void test_isFull() {
    test_isFull_full();
    test_isFull_notFull();
}

void test_getVectorValue() {
    vector v = {v.data, 0, 0};
    int x = 10;
    pushBack(&v, x);

    assert(v.data[0] == x);

    deleteVector(&v);
}

void test_pushBack_emptyVector() {
    vector v = {v.data, 0, 10};
    int x = 4;
    pushBack(&v, x);

    assert(v.data[0] == x);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = {v.data, 10, 10};
    int x = 3;
    pushBack(&v, x);

    assert(v.data[10] == 10);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    v.size = v.capacity;
    size_t i = 0;
    assert(atVector(&v, i) == v.data + i);
    deleteVector(&v);

}

void test_atVector_requestToLastElement() {
    vector v = (vector) {(int[]) {1, 2, 3}, 3, 3};
    assert(*atVector(&v, v.size - 1) == 3);

    deleteVector(&v);
}

void test_atVector() {
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
}

void test_back_oneElementInVector() {
    vector v = (vector) {(int[]) {1}, 1, 1};
    assert(*vectorBack(&v) == 1);

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = (vector) {(int[]) {1}, 1, 1};
    assert(*vectorFront(&v) == 1);

    deleteVector(&v);
}

void test_backAndFront() {
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}