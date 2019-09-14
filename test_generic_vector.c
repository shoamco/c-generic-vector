

#include "test_generic_vector.h"

void print_all_details(Vector *vector, char message[], FuncPrint func) {

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
    FuncPrint func = &print_int;
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
    FuncPrint func = &print_char;
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


void test_Count() {
    Vector *vector_char = vectorCreate(4);
    Vector *vector_string = vectorCreate(4);
    Vector *vector_int = vectorCreate(4);
    char v1 = 'a', v2 = 'b', v3 = 'c', v4 = 'd', v5 = 'f';
    int int1 = 1, int2 = 3, int3 = 3, int4 = 4, int5 = 5;
    char *s1 = "aaa", *s2 = "bbb", *s3 = "ccc", *s4 = "ddd", *s5 = "fff";
    FuncPrint func_print_char = &print_char, func_print_str = &print_string, func_print_int = &print_int;

    FuncCompare func_compare_char = &compare_char, func_compare_str = &compare_string, func_compare_int = &compare_int;

    void *item1 = &v1, *item2 = &v2, *item3 = &v3, *item4 = &v4, *item5 = &v5;
    void *item_str1 = &s1, *item_str2 = &s2, *item_str3 = &s3, *item_str4 = &s4, *item_str5 = &s5;
    void *item_int1 = &int1, *item_int2 = &int2, *item_int3 = &int3, *item_int4 = &int4, *item_int5 = &int5;

    printf("\n***********   test Count  ***********\n");
/*push items char to vector_char*/
    vectorPush(vector_char, item1);
    vectorPush(vector_char, item2);
    vectorPush(vector_char, item3);
    vectorPush(vector_char, item4);
    vectorPush(vector_char, item1);
    vectorPush(vector_char, item1);

/*push items str to vector_str*/
    vectorPush(vector_string, item_str1);
    vectorPush(vector_string, item_str2);
    vectorPush(vector_string, item_str2);
    vectorPush(vector_string, item_str3);
    vectorPush(vector_string, item_str4);
    vectorPush(vector_string, item_str1);

    /*push items str to vector_str*/
    vectorPush(vector_string, item_str1);
    vectorPush(vector_string, item_str2);
    vectorPush(vector_string, item_str2);
    vectorPush(vector_string, item_str3);
    vectorPush(vector_string, item_str4);
    vectorPush(vector_string, item_str1);

    /*push items int to vector_int*/
     vectorPush(vector_int, item_int1);
       vectorPush(vector_int, item_int2);
       vectorPush(vector_int, item_int4);
       vectorPush(vector_int, item_int3);
       vectorPush(vector_int, item_int1);
       vectorPush(vector_int, item_int1);

       print_all_details(vector_char, "vector char:", func_print_char);


       printf("count,%c appears %ld times \n", *(char *) item1, vectorCount(vector_char, item1, func_compare_char));
       printf("count,%c appears %ld times \n", *(char *) item4, vectorCount(vector_char, item4, func_compare_char));
       printf("count,%c appears %ld times \n", *(char *) item5, vectorCount(vector_char, item5, func_compare_char));


       print_all_details(vector_string, "vector string:", func_print_str);

       printf("count,%s appears %ld times \n", *(char **) item_str1,
              vectorCount(vector_string, item_str1, func_compare_str));
       printf("count,%s appears %ld times \n", *(char **) item_str2,
              vectorCount(vector_string, item_str2, func_compare_str));
       printf("count,%s appears %ld times \n", *(char **) item_str5,
              vectorCount(vector_string, item_str5, func_compare_str));


       print_all_details(vector_int, "vector string:", func_print_int);

       printf("count,%d appears %ld times \n", *(int*) item_int1,
              vectorCount(vector_int, item_int1, func_compare_int));
       printf("count,%d appears %ld times \n", *(int *) item_int2,
              vectorCount(vector_int, item_int2, func_compare_int));
       printf("count,%d appears %ld times \n", *(int *) item_int5,
              vectorCount(vector_int, item_int5, func_compare_int));


    vectorDestroy(&vector_char);
    vectorDestroy(&vector_string);
    vectorDestroy(&vector_int);

}

void test_GetElement() {

    Vector *vector = vectorCreate(3);
    char v1 = 'a', v2 = 'b', v3 = 'c', v4 = 'd';
/*char *v1 = "aaa", *v2 = "bbb", *v3 = "ccc", *v4 = "ddd";*/
    FuncPrint func = &print_char;

/* Func func = &print_string;  */
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
    FuncPrint func = &print_char;
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
    FuncPrint func = &print_char;
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
    FuncPrint func = &print_char;
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


