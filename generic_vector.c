//
// Created by shoam on 9/12/19.
//

#include "generic_vector.h"

typedef struct Vector {
    void **m_array_items;/*array of void*-generic items*/
    size_t m_capacity;
    size_t m_number_items;
} Vector;


void shift(Vector *vector, int index, Direction direction) {

}

void resize_vector_by2(Vector *vec) {

}


Vector *vectorCreate(size_t size) {
    Vector *d_vector = malloc(sizeof(Vector));
    assert(d_vector);
    if (d_vector) {
        d_vector->m_capacity = size;
        d_vector->m_number_items = 0;
        d_vector->m_array_items = malloc(size * sizeof(void **));
        assert(d_vector->m_array_items);
        if (!d_vector->m_array_items) {

            free(d_vector);/*if allocation fall -free vector */
            d_vector = NULL;/*return null for the use*/

        }


        return d_vector;
    }
}

void vectorDestroy(Vector **vector) {

}

/* Adds an item at the end. Grows if needed (by * 2) */
ErrorCode vectorPush(Vector *vector, int value) {
    ErrorCode errorCode = E_OK;
    return errorCode;
}

/* Adds an item at a certain position and shifts. Grows if needed (by * 2) */
ErrorCode vectorInsert(Vector *vector, int value, size_t index) {
    ErrorCode errorCode = E_OK;
    return errorCode;
}

/* Clears the item at the end. Grows if needed (by * 2) */
ErrorCode vectorPop(Vector *vector, int *res) {
    ErrorCode errorCode = E_OK;
    return errorCode;
}

/* Clears an item at a certain position and shifts. */
ErrorCode vectorRemove(Vector *vector, size_t index, int *res) {
    ErrorCode errorCode = E_OK;
    return errorCode;
}

ErrorCode vectorGetElement(const Vector *vector, size_t index, int *res) {
    ErrorCode errorCode = E_OK;
    return errorCode;
}

ErrorCode vectorSetElement(Vector *vector, size_t index, int value) {
    ErrorCode errorCode = E_OK;
    return errorCode;
}

size_t vectorGetSize(const Vector *vector) {
    size_t size;
    return size;
}

size_t vectorGetCapacity(const Vector *vector) {
    size_t size;
    return size;
}

void shift_left(Vector *vector, int index) {

}

void shift_right(Vector *vector, int index) {

}

/* Counts how many instances of a given value there are. */
size_t vectorCount(const Vector *vector, int value) {
    size_t count;
    return count;
}

void vectorPrint(const Vector *vector) {

}
