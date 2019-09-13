

#include "test_generic_vector.h"

void print_all_details(Vector *vector, char message[]) {

    printf("%s  :size: %ld , capacity: %ld  \n", message, vectorGetSize(vector), vectorGetCapacity(vector));
    /* vectorPrint(vector);*/
}

void test_vector_create() {
    Vector *vector = vectorCreate(5);
    vectorDestroy(&vector);
}

void test_push() {
    Vector *vector = vectorCreate(3);
    int v1 = 1;
    float v2 = 5.5;
    char v3 = 'a';
    char v4[] = "generic vector";
    void *item;

    print_all_details(vector, "empty vector");


    item = &v1;
    vectorPush(vector, item);
    print_all_details(vector, "push item int =1");


    item = &v2;
    vectorPush(vector, item);
    print_all_details(vector, "push item float =5.5");


    item = &v3;
    vectorPush(vector, item);
    print_all_details(vector, "push item char ='a'");


    item = &v4;
    vectorPush(vector, item);
    print_all_details(vector, "push item string ='generic vector'");

    vectorDestroy(&vector);

}

void test_GetSize() {
    Vector *vector = vectorCreate(1);
    int v1 = 1;
    void *item;


    printf("empty vector: size: %ld\n", vectorGetSize(vector));


    item = &v1;
    vectorPush(vector, item);
    printf("vector after push one item: size: %ld\n", vectorGetSize(vector));


    vectorDestroy(&vector);
}

void test_insert() {
    Vector *vector = vectorCreate(2);
    int v1 = 1;
    float v2 = 5.5;
    char v3 = 'a';
    char v4[] = "generic vector";
    void *item;


    printf("\n***********   test vectorInsert  ***********\n");

    print_all_details(vector, "empty vector");

    item = &v1;

    printf("error code (empty vector,index 1) :%d  \n", vectorInsert(vector, item, 1));

    printf("error code :%d \n", vectorInsert(vector, item, 0));
    print_all_details(vector, "insert item int =1,in index 0");


    item = &v2;
    printf("error code :%d \n", vectorInsert(vector, item, 0));
    print_all_details(vector, "insert item float =5.5,in index 0");


    item = &v3;
    printf("error code :%d \n", vectorInsert(vector, item, 1));
    print_all_details(vector, "insert item char ='a',in index 1");

    item = &v4;
    printf("error code :%d \n", vectorInsert(vector, item, 1));
    print_all_details(vector, "insert item string,in index 1");


    vectorDestroy(&vector);

}

void test_GetCapacity() {
    Vector *vector = vectorCreate(5);
    int v1 = 1;
    void *item;
    printf("\n***********   test GetCapacity  ***********\n");

    printf(" vector: capacity: %ld\n", vectorGetCapacity(vector));
    vectorDestroy(&vector);

}

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

void test_GetElement() {

    Vector *vector = vectorCreate(3);
    int v1 = 1;
    float v2 = 5.5;
    char v3 = 'a';
    char v4[] = "generic vector";
    void *item1 = &v1, *item2 = &v2, *item3 = &v3, *item4 = &v4;
    void *res;

    printf("\n***********  test GetElement  ***********\n");

    vectorPush(vector, item1);
    vectorPush(vector, item2);
    vectorPush(vector, item3);

    print_all_details(vector, "vector");

    printf("error code index 10 :%d \n", vectorGetElement(vector, 10, res));
    printf("error code :%d \n", vectorGetElement(vector, 0, res));
    printf("res: %p \n", res);


    vectorDestroy(&vector);
}

void test_SetElement() {
    Vector *vector = vectorCreate(3);
    int v1 = 1, v2 = 2, v3 = 3;


    void *item1 = &v1, *item2 = &v2, *item3 = &v3;
    void *res;

    printf("\n***********  test SetElement  ***********\n");

    vectorPush(vector, item1);
    vectorPush(vector, item2);
    vectorPush(vector, item3);


    print_all_details(vector, "vector");


    vectorGetElement(vector, 0, res);
    printf("item1 %d \n",*(int *)item1);
    printf("before: first item address: %d \n", *(int *)res);


    printf("error code :%d \n", vectorSetElement(vector, 0, item3));
    printf("res: %d \n", *(int *)res);


    printf("error code index 10 :%d \n", vectorSetElement(vector, 10, res));


    vectorDestroy(&vector);
}

void test_Remove() {
    Vector *vector = vectorCreate(3);
    int v1 = 1;
    float v2 = 5.5;
    char v3 = 'a';
    char v4[] = "generic vector";
    void *item1 = &v1, *item2 = &v2, *item3 = &v3, *item4 = &v4;
    void *res;

    printf("\n***********  test Remove  ***********\n");


    vectorPush(vector, item1 );
    vectorPush(vector, item2);
    vectorPush(vector, item3);

    print_all_details(vector, "vector");
    printf("error code (index 100) :%d \n", vectorRemove(vector, 100, res));
    printf("error code :%d \n", vectorRemove(vector, 1, res));
    print_all_details(vector, "after remove index 1 ");

    printf("error code :%d \n", vectorRemove(vector, 0, res));
    print_all_details(vector, "after remove index 0 ");

    printf("error code :%d \n", vectorRemove(vector, 0, res));
    print_all_details(vector, "after remove index 0 ");

    printf("error code  empty vector:%d\n", vectorRemove(vector, 0, res));


    vectorDestroy(&vector);

}

void test_Pop() {

    Vector *vector = vectorCreate(3);
    int v1 = 1;
    float v2 = 5.5;
    char v3 = 'a';
    char v4[] = "generic vector";
    void *item1 = &v1, *item2 = &v2, *item3 = &v3, *item4 = &v4;
    void *res;

    printf("\n***********  test Pop  ***********\n");

    vectorPush(vector, item1);
    vectorPush(vector, item2);
    vectorPush(vector, item3);

    print_all_details(vector, "vector");

    printf("error code :%d", vectorPop(vector, res));
    print_all_details(vector, "after pop");

    printf("error code :%d", vectorPop(vector, res));
    print_all_details(vector, "after pop");

    printf("error code :%d", vectorPop(vector, res));
    print_all_details(vector, "after pop");

    printf("error code :%d", vectorPop(vector, res));
    print_all_details(vector, "after pop");

    vectorDestroy(&vector);
}

void test_ErrorCode() {
    printf("\n***********  test ErrorCode  ***********\n");

}