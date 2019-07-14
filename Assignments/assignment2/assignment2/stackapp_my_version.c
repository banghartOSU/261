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

int _balanceCheck(struct DynArr * d)
{
    assert( d != 0);

    if(sizeDynArr(d) <= 0)
    {
        return 1;
    }
    
    struct DynArr * left = newDynArr(2);
    struct DynArr * right = newDynArr(2);
    while(!isEmptyDynArr(d))
    {
        if(topDynArr(d) == ')' || topDynArr(d) == ']' || topDynArr(d) == '}')
        {
            pushDynArr(right, topDynArr(d));
        }
        else
        {
            pushDynArr(left, topDynArr(d));
        }
         popDynArr(d);
    }
    
    if(sizeDynArr(left) == sizeDynArr(right))
    {
        return 1;
    }
    
    return 0;
}

/* Checks whether the (), {}, and [] are balanced or not
    param:     s pointer to a string
    pre:
    post:
*/
int isBalanced(char* s)
{
    assert(s != 0);
    int i = 0;
    
    struct DynArr * parens = newDynArr(2);
    struct DynArr * brackets = newDynArr(2);
    struct DynArr * braces = newDynArr(2);
    printf("%p\n",parens);
    
    while(nextChar(s) != '\0'){
        char currentChar = s[i];
        if(currentChar == '(' || currentChar == ')')
        {
            pushDynArr(parens, currentChar);
        }
        else if (currentChar == '[' || currentChar == ']')
        {
            pushDynArr(brackets, currentChar);
        }
        else if (currentChar == '{' || currentChar == '}')
        {
            pushDynArr(braces, currentChar);
        }
        i++;
    }
    if(_balanceCheck(parens) && _balanceCheck(brackets) && _balanceCheck(braces))
    {
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[]){

    char* s=argv[1];
    //REVERT TO ABOVE ONCE DONE TESTING
//    char* s = (char *) malloc(sizeof(char)*1000);
//    scanf("%[^\n]s",s);
    int res;

    printf("Assignment 2\n");

    res = isBalanced(s);

    if (res)
        printf("The string %s is balanced\n",s);
    else
        printf("The string %s is not balanced\n",s);

    return 0;
}
