#include <stdio.h>
#include <stdlib.h>

#include "StackLinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	nodePtr stack = createStack();
	
	
	stack_push(&stack, 1);
	stack_push(&stack, 2);
	stack_push(&stack, 3);
	stack_push(&stack, 4);
	stack_push(&stack, 5);
	
	nodePtr even = removeEvenNumbers(&stack);
	
	display(stack);
	printf("\nUpdated List\n");
	visualize(even);
	
	
	
	return 0;
}
