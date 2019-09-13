

#include "test_generic_vector.h"

void print_all_details(Vector *vector, char message[], Func func) {

    printf("%s  :size: %ld , capacity: %ld  \n", message, vectorGetSize(vector), vectorGetCapacity(vector));
    vectorPrint(vector, func);
}

void test_vector_create() {
    Vector *vector = vectorCreate(5);
    printf("\n***********   test vector_create  ***********\n");
    vectorDestroy(&vector);
}

void test_push() {
    Vector *vector = vectorCreate(3);
    int v1 = 1, v2 = 2, v3 = 3, v4 = 4;
    Func func = &print_int;
    void *item1 = &v1, *item2 = &v2, *item3 = &v3, *item4 = &v4;

    printf("\n***********   test push  ***********\n");
    print_all_details(vector, "empty vector", func);


    vectorPush(vector, item1);
    print_all_details(vector, "push item int =1", func);


    vectorPush(vector, item2);
    print_all_details(vector, "push item 2", func);


    vectorPush(vector, item3);
    print_all_details(vector, "push item 3'", func);


    vectorPush(vector, item4);
    print_all_details(vector, "push item 4", func);

    vectorDestroy(&vector);

}

void test_GetSize() {
    Vector *vector = vectorCreate(1);
    int v1 = 1;
    void *item = &v1;

    printf("\n***********   test GetSize  ***********\n");
    printf("empty vector: size: %ld\n", vectorGetSize(vector));


    vectorPush(vector, item);
    printf("vector after push one item: size: %ld\n", vectorGetSize(vector));


    vectorDestroy(&vector);
}

void test_insert() {
    Vector *vector = vectorCreate(2);
    char v1 = 'a', v2 = 'b', v3 = 'c', v4 = 'd';
    Func func = &print_char;
    void *item1 = &v1, *item2 = &v2, *item3 = &v3, *item4 = &v4;


    printf("\n***********   test vectorInsert  ***********\n");

    print_all_details(vector, "empty vector", func);


    printf("error code (empty vector,index 1) :%d  \n", vectorInsert(vector, item1, 1));

    printf("error code :%d \n", vectorInsert(vector, item1, 0));
    print_all_details(vector, "insert item1 ,in index 0", func);


    printf("error code :%d \n", vectorInsert(vector, item2, 0));
    print_all_details(vector, "insert item in index 0", func);


    printf("error code :%d \n", vectorInsert(vector, item3, 1));
    print_all_details(vector, "insert item in index 1", func);


    printf("error code :%d \n", vectorInsert(vector, item4, 1));
    print_all_details(vector, "insert item string,in index 1", func);


    vectorDestroy(&vector);

}

void test_GetCapacity() {
    Vector *vector = vectorCreate(5);
    int v1 = 1;
    void *item = &v1;
    printf("\n***********   test GetCapacity  ***********\n");

    printf(" vector: capacity: %ld\n", vectorGetCapacity(vector));
    vectorPush(vector, item);
    printf(" vector: capacity: %ld\n", vectorGetCapacity(vector));
    vectorDestroy(&vector);

}

/*
void test_Count() {
    Vector *vector = vectorCreate(3);
    int v1 = 1;
    float v2 = 5.5;
    char v3 = 'a';
    char v4[] = "generic vector";
    void *item1 = &v1, *item2 = &v2, *item3 = &v3, *item4 = &v4;

    printf("\n***********   test Count  ***********\n");

    vectorPush(vector, item1);
    vectorPush(vector, item2);
    vectorPush(vector, item3);
    vectorPush(vector, item4);
    vectorPush(vector, item1);
    vectorPush(vector, item1);

    print_all_details(vector, "vector");


    printf("count item1: %ld \n", vectorCount(vector, item1));
    printf("count item4: %ld\n ", vectorCount(vector, item4));
    vectorDestroy(&vector);

}
 */

void test_GetElement() {

    Vector *vector = vectorCreate(3);
    char v1 = 'a', v2 = 'b', v3 = 'c', v4 = 'd';
    Func func = &print_char;
    void *item1 = &v1, *item2 = &v2, *item3 = &v3, *item4 = &v4;
    void *res;


    printf("\n***********  test GetElement  ***********\n");

    vectorPush(vector, item1);
    vectorPush(vector, item2);
    vectorPush(vector, item3);
    vectorPush(vector, item4);

    print_all_details(vector, "vector", func);

    printf("error code index 10 :%d \n", vectorGetElement(vector, 10, res));
    printf("error code :%d \n", vectorGetElement(vector, 0, &res));
    printf("res: %c \n", *(char *) res);


    vectorDestroy(&vector);
}

void test_SetElement() {
    Vector *vector = vectorCreate(3);
    char v1 = 'a', v2 = 'b', v3 = 'c', v4 = 'd';
    Func func = &print_char;
    void *item1 = &v1, *item2 = &v2, *item3 = &v3, *item4 = &v4;


    printf("\n***********  test SetElement  ***********\n");

    vectorPush(vector, item1);
    vectorPush(vector, item2);
    vectorPush(vector, item3);


    print_all_details(vector, "vector", func);


    printf("error code :%d \n", vectorSetElement(vector, 0, item4));

    print_all_details(vector, "after set index 0", func);

    printf("error code index 10 :%d \n", vectorSetElement(vector, 10, item4));


    vectorDestroy(&vector);
}

void test_Remove() {
    Vector *vector = vectorCreate(3);
    char v1 = 'a', v2 = 'b', v3 = 'c';
    Func func = &print_char;
    void *item1 = &v1, *item2 = &v2, *item3 = &v3;
    void *res = NULL;

    printf("\n***********  test Remove  ***********\n");


    vectorPush(vector, item1);
    vectorPush(vector, item2);
    vectorPush(vector, item3);

    print_all_details(vector, "vector", func);

    printf("error code (index 100) :%d \n", vectorRemove(vector, 100, res));


    printf("error code :%d \n", vectorRemove(vector, 1, &res));
    printf("res: %c \n", *(char *) res);
    print_all_details(vector, "after remove index 1 ", func);


    printf("error code :%d \n", vectorRemove(vector, 0, &res));
    printf("res: %c \n", *(char *) res);
    print_all_details(vector, "after remove index 0 ", func);


    printf("error code :%d \n", vectorRemove(vector, 0, &res));
    printf("res: %c \n", *(char *) res);
    print_all_details(vector, "after remove index 0 ", func);

    printf("error code  empty vector:%d\n", vectorRemove(vector, 0, &res));


    vectorDestroy(&vector);

}

void test_Pop() {
    Vector *vector = vectorCreate(3);
    char v1 = 'a', v2 = 'b', v3 = 'c';
    Func func = &print_char;
    void *item1 = &v1, *item2 = &v2, *item3 = &v3;
    void *res;

    printf("\n***********  test Pop  ***********\n");

    vectorPush(vector, item1);
    vectorPush(vector, item2);
    vectorPush(vector, item3);

    print_all_details(vector, "vector", func);


    printf("error code :%d", vectorPop(vector, &res));
    printf("res: %c \n", *(char *) res);
    print_all_details(vector, "after pop", func);


    printf("error code :%d", vectorPop(vector, &res));
    printf("res: %c \n", *(char *) res);
    print_all_details(vector, "after pop", func);


    printf("error code :%d", vectorPop(vector, &res));
    printf("res: %c \n", *(char *) res);
    print_all_details(vector, "after pop", func);


    printf("error code :%d", vectorPop(vector, &res));
    print_all_details(vector, "after pop", func);

    vectorDestroy(&vector);
}

void test_ErrorCode() {
    printf("\n***********  test ErrorCode  ***********\n");

}
