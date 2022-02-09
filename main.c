#include "test_ds_vector.h"

void test(){
    test_createVector_deleteVector_NULL();
    test_createVector_deleteVector_notNULL();
    test_createVector_deleteVector();
    test_reserveVector_null();
    test_reserveVector_less();
    test_reserveVector_more();
    test_reserveVector_equals();
    test_reserveVector();
    test_clearVector_null();
    test_shrinkToFit();
    test_isEmpty_empty();
    test_isEmpty_notEmpty();
    test_isEmpty();
    test_isFull_full();
    test_isFull_notFull();
    test_isFull();
    test_getVectorValue();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector();
    test_backAndFront();
}

int main() {
    test();
    return 0;
}