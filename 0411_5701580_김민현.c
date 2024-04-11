#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef int element;
typedef struct StackType {
	//element stack[];
	element* data;
	int capacity;
	int top;
} StackType;

//create : 이미 만들었음. StackType의 변수를 선언하면 만들어짐.
//delete : 할 수 없음

//init
void init(StackType* sptr) {
	sptr->top = -1;
	sptr->capacity = 5;
	sptr->data = (element *)malloc(sizeof(element) * sptr->capacity);
}
//is_full
int is_full(StackType *sptr) {
	
	return (sptr->top == (sptr->capacity - 1));
}

int is_empty(StackType *sptr) {
	return (sptr->top == -1);
}
//push
void push(StackType *sptr, element item) {
	if (is_full(sptr)) {
		sptr->capacity = sptr->capacity * 2;
		sptr->data = (element*)realloc(sptr->data, sptr->capacity * sizeof(element));
	}
	else {
		sptr->top = sptr->top + 1;
		sptr->data[sptr->top] = item;
	}
}

element pop(StackType *sptr) {
	element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack is empty\n");
		return -1;
	}
	else {
		//r = sptr->stack[sptr->top]
		//sptr->top = sptr->top - 1;
		//return r;
		return(sptr->data[(sptr->top)--]);
	}
}

element peek(StackType *sptr) {
	element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack is empty\n");
		exit(1);
	}
	else {
		//r=sptr->stack[top]
		//sptr_>top = sptr->top - 1;
		//return r;
		return(sptr->data[sptr->top]);
	}
}

int main(int argc, char* argv[]) {

	StackType s;
	int rand_num;

	srand(time(NULL));

	init(&s);
	
	for (int i = 0; i < 30; i++) {
		rand_num = rand() % 100 + 1;

		printf("%d\n", rand_num);
		if (rand_num % 2 == 0) {
			push(&s, rand_num);
			printf("Push Stack S %d\n", rand_num);
		}
		else {
			rand_num = pop(&s);
			printf("Pop Stack S %d\n", rand_num);
		}
	}
}