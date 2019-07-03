# ifndef ArrayBagStack
# define ArrayBagStack
# define MAX_SIZE 100
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

# define TYPE int
# define EQ(a, b) (a == b)

struct arrayBagStack {
TYPE data [MAX_SIZE];
int count; 
};

/* Interface for Bag */
void initBag (struct arrayBagStack * b);
void addBag (struct arrayBagStack * b, TYPE v);
int containsBag (struct arrayBagStack * b, TYPE v);
void removeBag (struct arrayBagStack * b, TYPE v);
int sizeBag (struct arrayBagStack * b);

/* Interface for Stack */
void pushStack (struct arrayBagStack * b, TYPE v);
TYPE topStack (struct arrayBagStack * b);
void popStack (struct arrayBagStack * b);
int isEmptyStack (struct arrayBagStack * b);

# endif 

/* Bag Implementation */
void initBag (struct arrayBagStack * b){
 /* You have to initialize the count variable to 0 only */
	b->count = 0;	
} 
void addBag (struct arrayBagStack * b, TYPE v) {
/* add the value to the end of the array */
	assert(b != 0);
	if(b->count >= MAX_SIZE) return;
	b->data[b->count] = v;
	b->count++;
}

int containsBag (struct arrayBagStack * b, TYPE v) {
	assert(b != 0);
	if(b->count > 0){
		int i;
		for(i = 0; i < b->count; i++){
			if(b->data[i] == v) return 1;
		}
	}
	return 0;
}

void removeBag (struct arrayBagStack * b, TYPE v) {
	assert(b != 0);
	if(b->count > 0){
		int i;
		for(i = 0; i < b->count; i++){
			if(b->data[i] == v){
				b->data[i] = b->data[b->count - 1];
				b->count--;
				return;
			}
		}
	}
} 

int sizeBag (struct arrayBagStack * b) {
	assert(b != 0);
	return b->count;
} 
/* Stack Implementation */
void pushStack (struct arrayBagStack * b, TYPE v) {
	assert(b != 0);
	if(b->count >= MAX_SIZE) return;
	b->data[b->count] = v;
	b->count++;
}
TYPE topStack (struct arrayBagStack * b) {
	return ->data[b->count-1];
} 

void popStack (struct arrayBagStack * b) {
	assert(b != 0);
	if(b->count > 0){
		b->count--;
	}
}
 

int isEmptyStack (struct arrayBagStack * b) {
	assert(b != 0);
	if(b->count > 0) 
		return 0;
	return 1;
} 

// int main(){
// 	struct arrayBagStack * b;
// 	printf("%p\n",b);
// 	initBag(b);

// 	pushStack(b,1);
// 	pushStack(b,2);
// 	pushStack(b,3);
// 	pushStack(b,4);
// 	pushStack(b,5);
// 	addBag(b,6);
// 	addBag(b,7);
// 	int i;
// 	for(i = 0; i < sizeBag(b); i++){
// 		printf("%d\n", b->data[i]);
// 	}
// 	printf("%p\n",b);

// 	popStack(b);
// 	popStack(b);
// 	removeBag(b,1);

// 	for(i = 0; i < sizeBag(b); i++){
// 		printf("%d\n", b->data[i]);
// 	}

// 	return 0;
// }



