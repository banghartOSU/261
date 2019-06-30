/* CS261- Assignment 1 - Q.2*/
/* Name: Thomas Banghart
 * Date: 06/29/2019
 * Solution description: Testing simple swap with pointers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
    int *temp = b;
    b = a;
    a = temp;
    /*Decrement the value of integer variable c*/
    c--;
    /*Return c*/
    return c;
}

//int main(){
//    srand(time(NULL));
//    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
//    int x, y, z, valReturnedByFoo;
//    x = rand() % (10+1);
//    y = rand() % (10+1);
//    z = rand() % (10+1);
//    /*Print the values of x, y and z*/
//    printf("Before swap:\nx:%d\ny:%d\nz:%d\n", x,y,z);
//    /*Call foo() appropriately, passing x,y,z as parameters*/
//    valReturnedByFoo = foo(&x,&y,z);
//
//    /*Print the values of x, y and z*/
//    printf("After swap:\nx:%d\ny:%d\nz:%d\n", x,y,z);
//    
//    /*Print the value returned by foo*/
//    printf("Value returned by foo():%d\n",valReturnedByFoo);
// 
//    
//    return 0;
//}
    
    
/*
 a. Is the return value different than the value of integer z? Why or why not?
 *****************************************************************************
    Yes, the value is one less than the integer z. Since we "return" a value from the
    function call - it is a new variable that is no longer associated with z. The value
    of z was originally passed by value within the call to foo(), so at no point did we
    have access to z, only it's original starting value.
 *****************************************************************************
 b. Are the values of integers x and y different before and after calling the
 function foo(..)? Why or why not?
 *****************************************************************************
    No, the definition of foo() does not permit that the simple swap works as one would expected
    coming from a C++ background. This is beacuse there is no pass by reference in C -- here we are passing
    a copy of the addresses of each variable - not the addresses themselves. The correct way to make
    this swap work would be to define foo() as foo(int** a, int** b, int c). This would provide us with
    a pointer to the pointers from which we could access the memory address of each pointer. We would pass
    the memory address of pointers to foo() given that definition.
 
 */

