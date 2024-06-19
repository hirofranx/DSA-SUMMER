#include <stdio.h>
#include <stdlib.h>
#include "circularArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CircularQ cq;
	initcq(&cq);
	
	enqueue(&cq, 1);
	enqueue(&cq, 2);
	enqueue(&cq, 3);
	enqueue(&cq, 4);
	enqueue(&cq, 5);
	enqueue(&cq, 7);
	enqueue(&cq, 8);
	enqueue(&cq, 9);
	enqueue(&cq, 10);
	enqueue(&cq, 11);	
	
	dequeue(&cq);
	enqueue(&cq, 203);	
	display(cq);

	
	
	
	return 0;
}
