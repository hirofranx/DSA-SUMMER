#ifndef circularArray
#define circularArray
#include <stdbool.h>

#define MAX 10


typedef struct{
	int data[MAX];
	int front;
	int rear;
} CircularQ;

void initcq(CircularQ *cq);

bool enqueue(CircularQ *cq, int data);
bool dequeue(CircularQ *cq);

bool isEmpty(CircularQ cq);
bool isFull(CircularQ cq);

int frontdata(CircularQ cq);
int reardata(CircularQ cq);

void display(CircularQ cq);


#endif
