#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1;
}
StackArrayList createStack(){
	StackArrayList s;
	s.top = -1;
	
	return s;
}

bool isEmpty(StackArrayList s){
	return s.top == -1 ? true : false;
}
bool isFull(StackArrayList s){
	return s.top == MAX ? true : false;
}


bool stack_push(StackArrayList *s, int elem){
	if(!isFull(*s)){
		s->data[++s->top] = elem;
		return true;
	}
	return false;
}

bool stack_pop(StackArrayList *s){
	if(!isEmpty(*s)){
		s->top--;
		return true;
	}
	return false;
}

int stack_peek(StackArrayList s){
	return s.data[s.top];
}

void display(StackArrayList s){
	StackArrayList temp = createStack();
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

void visualize(StackArrayList s){
	int i,j;
	if(!isEmpty(s)){
		printf("Index\t|\tData\n");
		printf("0\t|\t%d - TOP\n", s.data[s.top]);
		for(i = s.top-1, j = 1; i >= 0; i--, j++){
			printf("%d\t|\t%d\n", j, s.data[i]);
		}
	}	
}

StackArrayList removeEvenNumbers(StackArrayList *s){
	StackArrayList Even = createStack();
	StackArrayList temp = createStack();
	int td;
		while(!isEmpty(*s)){
			td = stack_peek(*s);
			stack_pop(s);
			if(td%2 == 0){
				stack_push(&Even, td);
			} else {
				stack_push(&temp, td);
			}
		}
		
		while(!isEmpty(temp)){
			td = stack_peek(temp);
			stack_pop(&temp);
			stack_push(s, td);
		}
		
	return Even;
	
}

