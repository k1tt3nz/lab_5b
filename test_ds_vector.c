#include "test_ds_vector.h"
#include "vector.h"

#include <assert.h>

void test_createVector_deleteVector_NULL() {
    printf("Create vector capacity = 0 :");

    int capacity = 0;
    vector v = createVector(capacity);
    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == capacity);

    printf(" success\n");

    printf("delete vector:");

    deleteVector(&v);
    assert(v.data == NULL);

    printf(" success\n");
}

void test_createVector_deleteVector_notNULL() {
    printf("Create vector capacity = 666 :");

    int capacity = 666;
    vector v = createVector(capacity);
    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == capacity);

    printf(" success\n");

    printf("delete vector:");

    deleteVector(&v);
    assert(v.data == NULL);

    printf(" success\n");
}

void test_createVector_deleteVector() {
    test_createVector_deleteVector_NULL();
    test_createVector_deleteVector_notNULL();
}

void test_reserveVector_null() {
    printf("newCapacity = 0 :");

    size_t newCapacity = 0;
    vector v = createVector(10);
    v.size = 5;
    reserveVector(&v, newCapacity);
    assert(v.data == NULL);
    assert(v.capacity == newCapacity);
    assert(v.size == v.capacity);

    deleteVector(&v);

    printf(" success\n");
}

void test_reserveVector_less() {
    printf("newCapacity = 5; size = 10 :");

    size_t newCapacity = 5;
    vector v = createVector(newCapacity);
    v.size = 10;
    reserveVector(&v, 5);
    assert(v.data != NULL);
    assert(v.capacity == newCapacity);
    assert(v.size == newCapacity);

    deleteVector(&v);

    printf(" success\n");
}

void test_reserveVector_more() {
    printf("newCapacity = 100; size = 10 :");

    size_t newCapacity = 100;
    vector v = createVector(10);
    v.size = 10;
    reserveVector(&v, newCapacity);
    assert(v.data != NULL);
    assert(v.capacity == newCapacity);
    assert(v.size == 10);

    deleteVector(&v);

    printf(" success\n");
}

void test_reserveVector_equals() {
    printf("newCapacity = 10; size = 10 :");

    size_t newCapacity = 10;
    vector v = createVector(10);
    v.size = 10;
    reserveVector(&v, newCapacity);
    assert(v.data != NULL);
    assert(v.capacity == newCapacity);
    assert(v.size == 10);

    deleteVector(&v);

    printf(" success\n");
}

void test_reserveVector() {
    void test_reserveVector_null();
    void test_reserveVector_less();
    void test_reserveVector_more();
    void test_reserveVector_equals();
}

void test_clearVector_null() {
    printf("Clear vector :");
    vector v = {v.data, 10, 20};

    clearVector(&v);
    assert(v.size == 0);

    printf(" success\n");
}

void test_isEmpty_empty() {
    printf("isEmpty empty :");
    vector v = {v.data, 0, 10};
    assert(isEmpty(&v));

    printf(" success\n");
}

void test_isEmpty_notEmpty() {
    printf("isEmpty not empty:");
    vector v = {v.data, 1, 10};
    assert(!isEmpty(&v));

    printf(" success\n");
}

void test_isEmpty() {
    test_isEmpty_empty();
    test_isEmpty_notEmpty();
}

void test_isFull_full() {
    vector v = {v.data, 10, 10};
    assert(isFull(&v));
}

void test_isFull_notFull() {
    vector v = {v.data, 1, 10};
    assert(!isFull(&v));
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
}

void test_pushBack_emptyVector() {
    vector v = {v.data, 0, 10};
    int x = 4;
    pushBack(&v, x);

    assert(v.data[0] == x);
}

void test_pushBack_fullVector() {
    vector v = {v.data, 10, 10};
    int x = 3;
    pushBack(&v, x);

    assert(v.data[10] == 10);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}
