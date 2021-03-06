#ifndef TEST_DS_VECTOR_H
#define TEST_DS_VECTOR_H

void test_createVector_deleteVector_NULL();

void test_createVector_deleteVector_notNULL();

void test_createVector_deleteVector();

void test_reserveVector_null();

void test_reserveVector_less();

void test_reserveVector_more();

void test_reserveVector_equals();

void test_reserveVector();

void test_clearVector_null();

void test_shrinkToFit();

void test_isEmpty_empty();

void test_isEmpty_notEmpty();

void test_isEmpty();

void test_isFull_full();

void test_isFull_notFull();

void test_isFull();

void test_getVectorValue();

void test_pushBack_emptyVector();

void test_pushBack_fullVector();

void test_popBack_notEmptyVector();

void test_atVector_notEmptyVector();

void test_back_oneElementInVector();

void test_front_oneElementInVector();

void test_atVector();

void test_backAndFront();

#include "test_ds_vector.c"

#endif //TEST_DS_VECTOR_H
