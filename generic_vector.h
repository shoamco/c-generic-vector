

#ifndef C_GENERIC_VECTOR_SHOAMCO_GENERIC_VECTOR_H
#define C_GENERIC_VECTOR_SHOAMCO_GENERIC_VECTOR_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
typedef struct Vector Vector;
typedef  void(*FuncPrint)(Vector *vector);
typedef  int(*FuncCompare)(void *value1, void *value2);
typedef enum
{
    LEFT,
    RIGHT
}Direction;
typedef enum
{
    E_OK,
    E_NULL_PTR,
    E_UNDERFLOW,
    E_ALLOCATION_ERROR,
    E_BAD_INDEX
} ErrorCode;

void  shift(Vector *vector,size_t index, Direction direction);
void resize_vector_by2(Vector *vec);


Vector* vectorCreate(size_t size);
void vectorDestroy(Vector **vector);

/* Adds an item at the end. Grows if needed (by * 2) */
ErrorCode vectorPush(Vector *vector, void *value);

/* Adds an item at a certain position and shifts. Grows if needed (by * 2) */
ErrorCode vectorInsert(Vector *vector, void *value, size_t index);

/* Clears the item at the end. Grows if needed (by * 2) */
ErrorCode vectorPop(Vector *vector, void **res);

/* Clears an item at a certain position and shifts. */
ErrorCode vectorRemove(Vector *vector, size_t index, void **res);

ErrorCode vectorGetElement(const Vector *vector, size_t index, void **res);
ErrorCode vectorSetElement(Vector *vector, size_t index, void *value);

size_t vectorGetSize(const Vector *vector);
size_t vectorGetCapacity(const Vector *vector);
void shift_left(Vector *vector, size_t index);
void shift_right(Vector *vector, size_t index);
/* Counts how many instances of a given value there are. */
size_t vectorCount(const Vector *vector, void *value , FuncCompare func);
/*todo:move the function to a new file of user*/
void vectorPrint(const Vector *vector, FuncPrint func);
void print_float(const Vector *vector);
void print_char(const Vector *vector);
void print_int(const Vector *vector);
void print_string(const Vector *vector);

int compare_float(const void *value1,const void *value2);
int compare_char(const void *value1,const  void *value2);
int compare_int(const void *value1,const  void *value2);
int compare_string(const void *value1, const void *value2);
#ifdef _DEBUG
void vectorPrint(const Vector *vector, FuncPrint func);
#endif /* _DEBUG */
#endif /*C_GENERIC_VECTOR_SHOAMCO_GENERIC_VECTOR_H*/
