void dynArrayRemoveAt (struct dynArray * dy, int index);

struct dynArrayIterator {
   struct dynArray * da;
   int currentIndex; 
};

void dynArrayIteratorInit (struct dynArray *da, struct dynArrayIterator *itr) {
   assert( da != 0);
   itr->da = da;
   itr->currentIndex = 0;
}

int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {
	assert(itr != 0);
	if(itr->da->data[itr->currentIndex+1]) {return 1;}
	return 0;
}

TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {
	assert(itr != 0);
	itr->currentIndex++;
	return itr->
}

void dynArrayIteratorRemove (struct dynArrayIterator *itr) {












}
