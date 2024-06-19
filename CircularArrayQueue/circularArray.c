#include <stdbool.h>
#include <stdio.h>
#include "circularArray.h"

void initcq(CircularQ *cq){
	cq->front = 0;
	cq->rear = MAX-1;
}

bool enqueue(CircularQ *cq, int data){
	if(!isFull(*cq)){
		cq->rear = (cq->rear+1)%MAX;
		cq->data[cq->rear] = data;
		return true;
	} else {
		printf("Queue is Full\n");
		return false;
	}
}
bool dequeue(CircularQ *cq){
	if(!isEmpty(*cq)){
		cq->front = (cq->front+1)%MAX;
		return true;
	} else {
		printf("Queue is Empty\n");
		return false;
	}
}

bool isEmpty(CircularQ cq){
	if((cq.rear + 1) % MAX == cq.front){
		return true;
	} else {
		return false;
	}
}
bool isFull(CircularQ cq){
	if((cq.rear + 2) % MAX == cq.front){
		return true;
	} else {
		return false;
	}
}

int frontdata(CircularQ cq){
	return cq.data[cq.front];
}
int reardata(CircularQ cq){
	return cq.data[cq.rear];
}

void display(CircularQ cq){
	CircularQ temp;
	initcq(&temp);
	int td;
	if(isEmpty(cq)){
		printf("No data");
		return;
	} else {
		while(!isEmpty(cq)){
			td = frontdata(cq);
			printf("%d\n", td);
			dequeue(&cq);
			enqueue(&temp, td);
		}
		
		while(!isEmpty(temp)){
			td = frontdata(temp);
			dequeue(&temp);
			enqueue(&cq, td);
		}
	}
}
