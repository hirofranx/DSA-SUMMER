#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueLinkedList.h"

void initQueue(Queue *q){
	q->front = NULL;
	q->rear = NULL;
}

bool isEmpty(Queue q){
	return q.front == NULL ? true : false;
}

bool enqueue(Queue *q, int data){
	NodePtr newData = (NodePtr)malloc(sizeof(Node));
	
	newData->data = data;
	newData->next = NULL;
	if(isEmpty(*q)){
		q->front = newData;
		} else {
			q->rear->next = newData;
		}
	q->rear = newData;
}

bool dequeue(Queue *q){
	
	if(!isEmpty(*q)){
		NodePtr temp = q->front;
		q->front = q->front->next;
		free(temp);
		return true;
	}
	
	return false;
	
	
}
int front(Queue q){
	int data;
	
	if(isEmpty(q)){
		printf("No data\n");
		return false;
	}
	data = q.front->data;
	return data; 
}
int rear(Queue q){
	int data;
	
	if(isEmpty(q)){
		printf("No data\n");
		return false;
	}
	data = q.rear->data;
	return data;
	
}

void display(Queue q){
	if(isEmpty(q)){
		printf("No Data");
		return;
	}
	
	while(q.front != NULL){
		printf("%d\n", q.front->data);
		q.front = q.front->next;
	}
}
