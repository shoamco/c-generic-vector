
#include "generic_vector.h"

struct Vector {
    void **m_array_items;/*array of void*-generic items*/
    size_t m_capacity;
    size_t m_number_items;
};


Vector *vectorCreate(size_t size) {
    Vector *d_vector = malloc(sizeof(Vector));
    assert(d_vector);
    if (d_vector) {
        d_vector->m_capacity = size;
        d_vector->m_number_items = 0;
        d_vector->m_array_items = malloc(size * sizeof(void **));

        assert(d_vector->m_array_items);
        /* if (!d_vector->m_array_items) {*/
        if (!d_vector->m_array_items ) {

            free(d_vector);/*if allocation fall -free vector */
            d_vector = NULL;/*return null for the use*/

        }
    }
    return d_vector;
}

void vectorDestroy(Vector **vector) {
    if (((*vector)->m_array_items) && *vector) {
        free((*vector)->m_array_items);
        free(*vector);
        *vector = NULL; /**set to NULL ->for the user*/
    }


}

void resize_vector_by2(Vector *vector) {
    void **temp = vector->m_array_items;

    vector->m_capacity *= 2;
    vector->m_array_items = realloc(vector->m_array_items, vector->m_capacity * sizeof(void *));
    if (!(vector->m_array_items)) /*If the allocation failed -return the items*/
        vector->m_array_items = temp;
}

void shift_right(Vector *vector, size_t index) {
    size_t size = vector->m_number_items, i = size + 1;


    for (; i > index; --i) {
        vector->m_array_items[i] = vector->m_array_items[i - 1];

    }
}

void shift_left(Vector *vector, size_t index) {
    size_t size = vector->m_number_items, i = index;

    for (; i < size; ++i) {
        vector->m_array_items[i] = vector->m_array_items[i + 1];

    }
}

void shift(Vector *vector, size_t index, Direction direction) {
    if (direction == RIGHT) {
        shift_right(vector, index);
    } else {
        shift_left(vector, index);

    }
}

/* Adds an item at the end. Grows if needed (by * 2) */
ErrorCode vectorPush(Vector *vector, void *value) {
/*ErrorCode vectorPush(Vector *vector, void *value, char *type) {*/
    ErrorCode val_error = E_OK;
    assert(vector);
    if (vector->m_number_items >= vector->m_capacity) {
        resize_vector_by2(vector);
        if (!(vector->m_array_items))
            return E_ALLOCATION_ERROR;
    }
    vector->m_array_items[vector->m_number_items++] = value;
    return val_error;
}

/* Adds an item at a certain position and shifts. Grows if needed (by * 2) */
ErrorCode vectorInsert(Vector *vector, void *value, size_t index) {

    ErrorCode val_error = E_OK;
    assert(vector);/*assert not if,not  my responsibility*/

    if (index > vector->m_number_items)
        val_error = E_BAD_INDEX;
    else if (index == (vector->m_number_items)-1) {
        vectorPush(vector, value);
    }
    else {

        if (vector->m_number_items >= vector->m_capacity) {
            resize_vector_by2(vector);
            if (!(vector->m_array_items)) {
                return E_ALLOCATION_ERROR;
            }
        } else {
            shift(vector, index, RIGHT);
            vector->m_array_items[index] = value;
            ++(vector->m_number_items);
        }


    }
    return val_error;
}

/* Clears the item at the end*/
ErrorCode vectorPop(Vector *vector, void **res) {
    ErrorCode val_error;
    if (!vector)
        val_error = E_NULL_PTR;
    if (vector->m_number_items == 0) {
        val_error = E_UNDERFLOW;
    } else {

        *res = vector->m_array_items[(vector->m_number_items) - 1];

        vector->m_array_items[--(vector->m_number_items)] = 0;

        val_error = E_OK;
    }
    return val_error;

}

/* Clears an item at a certain position and shifts. */
ErrorCode vectorRemove(Vector *vector, size_t index, void **res) {
    ErrorCode val_error = E_OK;
    assert(vector);
    if (!vector)
        val_error = E_NULL_PTR;

    else if (index >= vector->m_number_items)
        val_error = E_BAD_INDEX;

    else {/*remove item and save it in res*/
        *res = vector->m_array_items[index];
        shift(vector, index, LEFT);

        vector->m_array_items[(vector->m_number_items)--] = 0;;

    }
    return val_error;
}

ErrorCode vectorGetElement(const Vector *vector, size_t index, void **res) {
    ErrorCode val_error = E_OK;
    if (!vector)
        val_error = E_NULL_PTR;

    else if (index > vector->m_number_items)
        val_error = E_BAD_INDEX;

    else {
        *res = vector->m_array_items[index];
    }
    return val_error;
}

ErrorCode vectorSetElement(Vector *vector, size_t index, void *value) {
    ErrorCode val_error = E_OK;
    if (!vector)
        val_error = E_NULL_PTR;

    else if (index > vector->m_number_items)
        val_error = E_BAD_INDEX;

    else {
        vector->m_array_items[index] = value;

    }
    return val_error;
}

size_t vectorGetSize(const Vector *vector) {
    return vector->m_number_items;;
}

size_t vectorGetCapacity(const Vector *vector) {

    return vector->m_capacity;

}


/* Counts how many instances of a given value there are. */
size_t vectorCount(const Vector *vector, void *value) {/*todo:type*/
    int i = 0;
    size_t count = 0;


    for (; i < vector->m_number_items; ++i) {
        count += (vector->m_array_items[i]) == value;
    }

    return count;
}

void vectorPrint(Vector *vector, Func func) {
    func(vector);


}

void print_int(Vector *vector) {
    int i = 0;
    for (; i < vector->m_number_items; ++i)
        printf("%d ", *(int *) vector->m_array_items[i]);
    printf("\n");
}

void print_char(Vector *vector) {
    int i = 0;
    for (; i < vector->m_number_items; ++i)
        printf("%c ", *(char *) vector->m_array_items[i]);
    printf("\n");
}

void print_float(Vector *vector) {
    int i = 0;
    for (; i < vector->m_number_items; ++i)
        printf("%f ", *(float *) vector->m_array_items[i]);
    printf("\n");
}
