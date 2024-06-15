#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLinkedList.h"

void initStack(nodePtr *s){
	s = NULL;
}

nodePtr createStack(){
	nodePtr s = NULL;
	
	return s;
}

bool isEmpty(nodePtr s){
	return s == NULL ? true : false;
}

bool stack_push(nodePtr *s, int elem){
	nodePtr newnode = malloc(sizeof(node));
	
	if(newnode != NULL){
		newnode->data = elem;
		newnode->next = *s;
		*s = newnode;
		return true;
	} else {
		return false;
	}
}

bool stack_pop(nodePtr *s){
	if(*s == NULL){
		printf("No Data");
		return false;
	} else {
		nodePtr temp = *s;
		*s = (*s)->next;
		free(temp);
		return true;
	}
}

int stack_peek(nodePtr s){
	int data;
	data = s->data;
	return data;
}


void display(nodePtr s){
	nodePtr temp = NULL;
	int td;
	
	while(!isEmpty(s)){
		td = stack_peek(s);
		printf("%d\n", td);
		stack_pop(&s);
		stack_push(&temp, td);
	}
	
	while(!isEmpty(temp)){
		td = stack_peek(temp);
		stack_pop(&temp);
		stack_push(&s, td);
	}
}


void visualize(nodePtr s){
	int count = 0;
	printf("Index\t|\tData\n");
	printf("%d\t|\t%d - TOP\n", count, s->data);
	nodePtr trav = s->next;
	while(trav != NULL){
		printf("%d\t|\t%d\n", ++count, trav->data);
		trav = trav->next;
	}
	
}


nodePtr removeEvenNumbers(nodePtr *s){
	nodePtr temp = createStack();
	nodePtr even = createStack();
	int td;
	while(!isEmpty(*s)){
		td = stack_peek(*s);
		stack_pop(s);
		if(td % 2 == 0){
			stack_push(&even, td);
		} else {
			stack_push(&temp, td);
		}
	}
	
	while(!isEmpty(temp)){
		td = stack_peek(temp);
		stack_pop(&temp);
		stack_push(s, td);
	}
	return even;
	
	
	
}








