#ifndef stackArray
#define stackArray
#include<stdbool.h>


typedef struct Node{
	int data;
	struct Node* next;
} node, *nodePtr;

void initStack(nodePtr *s);
nodePtr createStack();

bool isEmpty(nodePtr s);
bool isFull(nodePtr s);
bool stack_push(nodePtr *s, int elem);
bool stack_pop(nodePtr *s);
int stack_peek(nodePtr s);


void display(nodePtr s);
void visualize(nodePtr s);

nodePtr removeEvenNumbers(nodePtr *s);


#endif
