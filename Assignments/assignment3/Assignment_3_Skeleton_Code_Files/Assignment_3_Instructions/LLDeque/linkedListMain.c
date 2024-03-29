#include "linkedList.h"
#include <stdio.h>

int main(){
    struct LinkedList* l = linkedListCreate();
    printf("5, 4, 1, 2, 3, 6\n");
    linkedListAddFront(l, (TYPE)1);
    linkedListAddBack(l, (TYPE)2);
    linkedListAddBack(l, (TYPE)3);
    linkedListAddFront(l, (TYPE)4);
    linkedListAddFront(l, (TYPE)5);
    linkedListAddBack(l, (TYPE)6);
    linkedListPrint(l);
    printf("First Print\n");
    printf("Print Front and Back\n");
    printf("%i\n", linkedListFront(l));
    printf("%i\n", linkedListBack(l));
    printf("Remove Front and Back\n");
    linkedListRemoveFront(l);
    linkedListRemoveBack(l);
    linkedListPrint(l);
    linkedListDestroy(l);
/* BAG */
    
    struct LinkedList* k = linkedListCreate();
    linkedListAdd (k, (TYPE)10);
    linkedListAdd (k, (TYPE)11);
    linkedListAdd (k, (TYPE)13);
    linkedListAdd(k, (TYPE)14);
    linkedListRemove(k, (TYPE)11);
    linkedListPrint(k);
    linkedListDestroy(k);
    return 0;
}

