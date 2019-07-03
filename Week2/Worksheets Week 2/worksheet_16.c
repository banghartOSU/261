# define TYPE int

struct DynArr {
        TYPE * data;
        int size;
        int capacity;
};


void dynArrayPush (struct DynArr * da, TYPE e) {
 	assert(da != 0);
 	if(da->size == da->capacity)
 		_setCapacityDynArr(da, da->capacity*2);
 	
 	da->data[da->size] = e;
 	da->size++;
}

TYPE dynArrayTop (struct DynArr * da) {
	assert(da != 0 && da->size > 0);
	return da->[da-size-1];
}

void dynArrayPop (struct DynArr * da) {
	assert(da != 0 && da->size > 0);
	da->size--;
}

int dynArrayIsEmpty (struct DynArr * da) {
	assert(da != 0);
	if(da->size > 0)
		return 0;
	return 1;
}

/* Questions

1. What is the algorithmic execution time for the operations pop and top?
******************************************************************************************************************************
	O(1) -- simply return the top element or reduce the size of the stack.
2. What is the algorithmic execution time for the operation push, assuming there is sufficient capacity for the new elements?
******************************************************************************************************************************
	O(1) -- since we're only adding an element at `size`.
3. What is the algorithmic execution time for the internal method _dynArraySetCapacity?
******************************************************************************************************************************
	O(n) -- since we need to copy the elements from the old array to the new array. The number of elements in the old array will 
	determine the execution time of the operation. 
4. Using as a basis your answer to 3, what is the algorithmic execution time for the operation push assuming that a new array must be created.
******************************************************************************************************************************
	O(n) -- since we need to copy the array and allocate a new capciaty. The additinal step to add an element to the stack is negligible. 
*/