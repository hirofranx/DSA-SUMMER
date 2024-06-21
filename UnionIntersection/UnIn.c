#include <stdio.h>

#include "UnIn.h"

void initset(set *s){
	int i = 0;
	while(i < MAX){
		s->setA[i] = 0;
		s->setB[i] = 0;
		i++;
	}
}

void addset(set *s){
	int i = 0, j = 0;
	int x = 9,y = 9;
	int a = 9,b = 9;

	while(x > 8){
		printf("Enter number of elements for the set A. (MAX &): ");
		scanf("%d", &x);
	}
	
	
	printf("Enter %d Set Values for Set A. (0-7)\n", x);
		while(i < x){
			do{
				printf("%d.", i+1);
				scanf("%d", &a);
			}while(a > 7); 
			s->setA[a] = 1;
			i++;
		}
	
	system("cls");
	
	while(y > 8){
		printf("Enter number of elements for the set B. (MAX &): ");
		scanf("%d", &y);
	}
	printf("Enter %d Set Values for Set B. (0-7)\n", y);
	while(j < y){
		do{
			printf("%d.", j+1);
			scanf("%d", &b);
		} while(b > 7);
		s->setB[b]= 1;
		j++;
	}
}
void addElem(set *s){
	char choose;
	int i, j;
	int x = 9;
	
	printf("Set A - ");
	for(i = 0; i <MAX; i++){
		printf("%d ", s->setA[i]);
	}
	
	printf("\nSet B - ");
	
	for(i = 0; i <MAX; i++){
		printf("%d ", s->setB[i]);
	}
	
	
	printf("\n");
	
	printf("Choose Set to add a Value: ");
	scanf(" %c", &choose);
	
	if(choose == 'a' || choose == 'A'){
		do{
			printf("Choose value(0-7): ");
			scanf("%d", &x);
		}while(x > 7);
		s->setA[x] = 1;
	}
	if(choose == 'b' || choose == 'B'){
		do{
			printf("Choose value(0-7): ");
			scanf("%d", &x);
		}while(x > 7);
		s->setB[x] = 1;
	}
}

void deleteValue(set *s){
	char choose;
	int i, j;
	int x;
	
	printf("Set A - ");
	for(i = 0; i <MAX; i++){
		printf("%d ", s->setA[i]);
	}
	
	printf("\nSet B - ");
	
	for(i = 0; i <MAX; i++){
		printf("%d ", s->setB[i]);
	}
	
	
	printf("\n");
	
	printf("Choose Set to delete a value from: ");
	scanf(" %c", &choose);
	
	if(choose == 'a' || choose == 'A'){
		printf("Choose value to delete: ");
		scanf("%d", &x);
		s->setA[x] = 0;
	}
	if(choose == 'b' || choose == 'B'){
		printf("Choose value to delete: ");
		scanf("%d", &x);
		s->setB[x] = 0;
	}
	
}

set results(set *s){
	//Union
	set x;
	initset(&x);
	int i,j;
	for(i = 0; i < MAX; i++){
		if(s->setA[i] == 1 || s->setB[i] == 1){
			x.setA[i] = 1;
		}
	}
	
	//Intersection
	for(j = 0; j < MAX; j++){
		if(s->setA[j] == 1 && s->setB[j] == 1){
			x.setB[j] = 1;
		}
	}
	
	
	return x;
	
}
void display(set s){
	system("cls");
	int i;
		printf("Set A - ");
	for(i = 0; i <MAX; i++){
		printf("%d ", s.setA[i]);
	}
	
	printf("\nSet B - ");
	
	for(i = 0; i <MAX; i++){
		printf("%d ", s.setB[i]);
	}
	
}


