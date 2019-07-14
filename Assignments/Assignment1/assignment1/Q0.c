///* CS261- Assignment 1 - Q. 0*/
///* Name:Thomas Banghart
// * Date:06/29/2019
// * Solution description: Experimenting with printf() and pointers
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void fooA(int* iptr){
//    
//    /*Print the value and address of the integer pointed to by iptr*/
//    printf("%d %p\n", *iptr, iptr);
//    
//    /*Increment the value of the integer pointed to by iptr by 5*/
//    *iptr += 5;
//    
//    /*Print the address of iptr itself*/
//    printf("%p\n", &iptr);
//    
//    /*Dummy variable, ignore the warning*/
//    int c=5;
//}
//
//
//void fooB(int* jptr){
//    
//    /*Print the value and address of the integer pointed to by jptr*/
//    printf("%d %p\n", *jptr, jptr);
// 
//    /*Decrement the address by 1 pointed to by jptr using jptr */
//    jptr--;
//
//    /*Print the address of jptr itself*/
//    printf("%p\n", &jptr);
//}
//
//
//int main(){
//    srand(time(NULL));
//    
//    /*Declare an integer x and initialize it randomly to a value in [0,10] */
//    int x = (rand() % 10 + 1);
//    /*Print the value and address of x*/
//    printf("%d %p\n",x, &x);
//    
//    /*Call fooA() with the address of x*/
//    fooA(&x);
//    
//    /*Print the value of x*/
//    printf("%d\n",x);
//    /*Is the value of x different than the value that was printed at first? Why or why not?
//     ******************************************************************************************
//     Yes, calling fooA() with the address of x gave us access to the location of the variable in
//     memory. By dereferecing the pointer (*iptr) we're actually dealing with the same spot in
//     memory that x refers to. Since we add 5 to that value then the the function actual changes the
//     value of x after fooA() is finished. This is the closest we get to "pass by reference" in C.
//     */
//    
//    
//    /*Call fooB() with the address of x*/
//    fooB(&x);
//    /*Are the value and address of x different than the value and address that were printed before
//     the call to fooB(..)? Why or why not?
//     ******************************************************************************************
//     No, the value of x remains the same (5 more than the original amount after fooA()), as does the
//     address. This is because the memory location that gets passed to the function is a copy of
//     that address (pass by value). In other words, the scope of the pointer that we use
//     in fooB() stays within that function. Were we to print the value at jptr (*jptr) rather
//     than the address, we would see that it now points to something completely different. When testing
//     this, the interger value at the address one less than what gets passed to fooB() happened to
//     be 17. The same could be said for iptr.
//     
//     
//     */
//    /*Print the value and address of x*/
//    printf("%d %p\n",x,&x);
//    
//    
//    return 0;
//}
//
//
