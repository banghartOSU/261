struct DynArr {
   TYPE *data;
   int size;
   int capacity;
};



void half(DynArr *v) {
	assert(v != 0 && v->size > 1);
	int originalSize = v->size;
	while(!(originalSize >= 0.5*v->capacity))
	{
		if(v->size >= v->capacity)
		{
			v->size--;
			v->data[v->size] = 0;
		}
		v->capacity--;
	}
}