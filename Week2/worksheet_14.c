void _setCapacityDynArr(struct DynArr *v, int newCap)
{
	int i;

	struct DynArr * temp;
	temp->data = (TYPE*) malloc(sizeof(TYPE) * newCap);
	assert(temp->data != 0);
	temp->size = v->size;
	temp->capacity = newCap;

	for(i = 0; i < v->size; i++){
		temp->data[i] = v->data[i];
	}

	free(v);
	v = temp;
	temp = 0;
}

TYPE getDynArr (struct DynArr * da, int position) {
	assert(position >= 0 && position < da->size && da != 0);
	return = da->data[position];
}

void putDynArr(struct DynArr * da, int position, TYPE value) {
	assert(position >= 0 && position < da->size && da != 0);
	if(da->size == da->capacity)
		_setCapacityDynArr(da, 2 * da->capacity);
	int i;
	for(i = size; i > position; i--){
		da->data[i] = da->data[i-1];
	}
	da->data[position] = value;
	da->size++;
}

void swapDynArr (struct DynArr * da, int i, int j) {
	assert(da != 0);
	TYPE temp = da->data[i];
	da->data[i] = da->data[j];
	da->data[j] = temp;
}

void removeAtDynArr (struct DynArr * da, int index) {
	assert(index >= 0 && index < da->size && da != 0);
	int i;
	for(i = index; i < da->size-1; i++){
		da->data[i] = da->data[i+1];
	}
	da->size--;
}
