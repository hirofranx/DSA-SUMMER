#include <stdio.h>
#include <stdlib.h>
#include "QueueLinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Queue q;
	initQueue(&q);
	printf("\nEnqueued data\n");
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	
	display(q);
	
	printf("\nDequeued data\n");
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	
	display(q);
	
	
	printf("Front Data - %d\n", front(q));
	printf("Rear Data - %d\n", rear(q));
	
	
	
	
	
	return 0;
	
	
	
	
	
}
