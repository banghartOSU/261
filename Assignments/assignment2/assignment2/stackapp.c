/*    stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"
/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
    param:     s pointer to a string
*/
char nextChar(char* s)
{
    static int i = -1;
    char c;
    ++i;
    c = *(s+i);
    if ( c == '\0' )
        return '\0';
    else
        return c;
}

void _checkParen(struct DynArr * leftParens, char currentChar){
    assert(leftParens != 0);
    //Push the corresponding closing paren to the stack to check comparison easily.
    switch (currentChar) {
        case '(':
            pushDynArr(leftParens, ')');
            break;
        case '[':
            pushDynArr(leftParens, ']');
            break;
        case '{':
            pushDynArr(leftParens, '}');
            break;
    }
}
/* Checks whether the (), {}, and [] are balanced or not
    param:     s pointer to a string
    pre:       s is not null
    post:      returns 1 if there are no '()', '{}, or '[]', or if there are an even          number of them. returns 0 otherwise.
*/
int isBalanced(char* s)
{
    assert(s != 0);
    //Make new array of "left" parens found
    struct DynArr * leftParens = newDynArr(2);
    //Iterate through the string
    char currentChar = nextChar(s);
    while(currentChar != '\0')
    {
        _checkParen(leftParens, currentChar);
        
        if(currentChar == ')' || currentChar == ']' || currentChar == '}')
        {
            if(isEmptyDynArr(leftParens)) {return 0;}
            else if (currentChar == topDynArr(leftParens)) { popDynArr(leftParens);}
        }
        currentChar = nextChar(s);
    }
    //Check if we haven't "popped" all the left parens
    if(!isEmptyDynArr(leftParens)) { deleteDynArr(leftParens); return 0;}
    else { deleteDynArr(leftParens); return 1; }
}


int main(int argc, char* argv[]){

    char* s=argv[1];
    int res;

    printf("Assignment 2\n");

    res = isBalanced(s);

    if (res)
        printf("The string %s is balanced\n",s);
    else
        printf("The string %s is not balanced\n",s);

    return 0;
}
