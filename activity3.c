#include <stdio.h>
#include <stdlib.h>

// Include the header file containing the prototypes (declarations) of
// functions defined in the helper file string_funcs.c
#include "string_funcs.h"

// Declarations of functions defined below
void task1();
int arg_modifier(int x, int *y);

void task2();
void init_array1(int nums[], int len, int mult);
void init_array2(int nums[], int len, int mult);

void task3();



int main() {
    // Task 1: call the first example to show how a pointer to int works
    task1();

    // Task 2: call the second example that creates static and dynamic arrays
    task2();

    // Task 3: call the last example, which does string operations
    task3();
}


/*
 * This function runs the first example (drawn from _Dive into Systems_) where
 * we read values from the user, and then pass one value as an int and the other
 * through a pointer to int to a function. The function can actually modify
 * the memory location where the second value is stored in the previous function
 */
void task1() {
    int val1, val2, ret;

    printf("Enter a value: ");
    scanf("%d", &val1);
    printf("Enter another value: ");
    scanf("%d", &val2);

    // pass val1 by value and val2 by pointer:
    printf("--before call:  val1 = %d   val2 = %d\n", val1, val2);
    ret = arg_modifier(val1, &val2);
    printf("--after call :  val1 = %d  val2 = %d  ret = %d\n", val1, val2, ret);

    /*
     * uncomment to test passing val2 by value and val1 by pointer
     */
    //printf("before 2nd call: val1 = %d val2 = %d\n", val1, val2);
    //ret = arg_modifier(val2, &val1);
    //printf("after 2nd call: val1 = %d val2 = %d\n", val1, val2);
}

/*
 * This function illustrates C-style pass by pointer semantics, the
 * argument pointed to by the second parameter, y, will be modified
 * after the call, the value of the first argument, x, will not.
 */
int arg_modifier(int x, int *y) {

    printf("   entering arg_modifier:    x = %d   *y = %d\n", x, *y);

    /* the location y points to gets (value of what y points to + x) */
    *y = *y + x;

    x = x + 5;
    printf("   leaving arg_modifier :    x = %d   *y = %d\n", x, *y);
    /* 
     * TODO: draw state of program stack at this point!
     */
    return x;
}

/* 
 * Creates static and dynamic arrays and passes them to two helper functions
 * as pointers, showing different ways of accessing/manipulating arrays
 */
void task2() {
    int arr_len = 10;
    int arr1[arr_len];
    int *arr2;
    int i;

    arr2 = (int *)malloc(sizeof(int) * arr_len);
    if (arr2 == NULL) {
        printf("Malloc failed!\n");
        exit(1);
    }

    // change which pair of calls is uncommented below to see how 
    // init_array1 and init_array2 work
    init_array1(arr1, arr_len, 2);
    init_array1(arr2, arr_len, 5);
    // init_array2(arr1, arr_len, 2);
    // init_array2(arr2, arr_len, 5);

    // TODO: draw state of program stack and heap at this point

    for (i = 0; i < arr_len; i++) {
        printf("static: %d    dynamic: %d\n", arr1[i], arr2[i]);
    }
    free(arr2);
}


/* 
 * Takes in a pointer to int (an array of integers), the length of the array
 * and a multiplier, and it initializes the first len cells of the nums array
 * to hold its index times mult (using normal array indexing)
 */
void init_array1(int *nums, int len, int mult) {
    int i;
    for (i=0; i < len; i++) {
        nums[i] = mult * i;
    }
}

/* 
 * Takes in a pointer to int (an array of integers), the length of the array
 * and a multiplier, and it initializes the first len cells of the nums array
 * to hold its index times mult (using pointer arithmetic)
 */
void init_array2(int *nums, int len, int mult) {
    int i;
    for (i=0; i < len; i++) {
        *(nums + i) = mult * i;
    }
}


/* 
 * This creates a string (array of characters), and illustrates how to 
 * manipulate strings
 */
void task3() {
    char dest[128];

    array_strcpy(dest, "Array Test Copy!");
    printf("Testing Array Copy: %s\n", dest);

    ptr_strcpy(dest, "Pointer Test Copy!");
    printf("Testing Pointer Copy: %s\n", dest);

    // TODO: Add sample calls to my_strcat and my_strncpy here

}