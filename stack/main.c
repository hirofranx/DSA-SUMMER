#include <stdio.h>
#include <stdlib.h>

#include "stackArray.h"
#include "stackArray.c" //remove this line if running in dev c. this line is needed to run in vscode


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList s = createStack();
	StackArrayList Even = createStack();
	
	stack_push(&s, 1);
	stack_push(&s, 2);
	stack_push(&s, 3);
	stack_push(&s, 4);
	stack_push(&s, 5);
	
	display(s);
	
	
	printf("\n\nEven Numbers\n");
	Even = removeEvenNumbers(&s);
	display(Even);
	printf("\n\nUpdated List\n");
	visualize(s);
	
	
	return 0;
}
