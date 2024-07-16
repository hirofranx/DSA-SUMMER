#include "graph.h"
#include <stdio.h>
#include <ctype.h>
void init(int matrix[][5]){
	int i, j;
	
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			matrix[i][j] = 0;
		}
	}
}
void addEdge(int matrix[][5], char a, char b){
	
	a = toupper(a);
	b = toupper(b);
	
	if(a > 69 || b > 69){
		printf("Invalid Input");
		return;
	}
	
	int n = hash(a);
	int m = hash(b);
	
	matrix[n][m] = 1;
	matrix[m][n] = 1;
}
int hash(char elem){
	return elem - 'A';
}

void display(int matrix[][5]){
	int i, j;
	int cha = 65;
	printf("   A B C D E\n");
	for(i = 0; i < 5; i++){
		printf("%c  ", cha);
		cha++;
		for(j = 0; j < 5; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}


void initList(int list[][5]){
	int i, j;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			list[i][j] = -1;
		}
	}
}

void addEdgeList(int list[][5], char a, char b){
	a = toupper(a);
	b = toupper(b);
	
	if(a > 69 || b > 69){
		printf("Invalid Input");
		return;
	}
	int i = 0;
	int n = hash(a);
	int m = hash(b);
	while(list[n][i] != -1 && i < 4){
		i++;
	}
	list[n][i] = b;
	
	int j = 0;
	while(list[m][j] != -1 && j < 4){
		j++;
	}
	list[m][j] = a;
	
}
void displayList(int list[][5]){
	int i, j;
	for(i = 0; i < 5; i++){
		printf("[ ");
		for(j = 0; j < 5; j++){
			if(list[i][j] != -1){
				printf("%c", list[i][j]);
			}	
		}
		printf(" ]");
		printf("\n");
	}
}




