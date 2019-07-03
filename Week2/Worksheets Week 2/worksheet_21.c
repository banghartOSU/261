int containsDynArr (struct DynArr * da, TYPE e) {
	assert(da != 0);
	int i;
	for(i < da->size; i++){
		if(EQ(da->data[i],e))
			return 1;
	}
	return 0;
}

       
/*
1.	What should the removeAt method do if the index given as argument is not in range? 
*******************************************************************************************************************************************
	removeAt should return type int and evaluate to true if an element was removed and false if an element was not.
	This would be a good saftey check to ensure we're removing values as we intend to.
2.	What is the algorithmic complexity of the method removeAt? Given your answer to the previous question, what is the worst-case complexity of the method remove? 
	O(log n)? Not quite sure on this
3.	What are the algorithmic complexities of the operations add and contains? 
	O(n) -- both require loops that need to iterate through each elements. For add, this is when copying values. For contains, this is to check each value.
*/
