#include <stdio.h>
#include <stdlib.h>
#include "UnIn.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	set s;
	set x;
	int i;
	int choose = 0;
	initset(&s);
	
	do{
		
		printf("What to do?\n");
		printf("1. Add Data To Set A and B\n");
		printf("2. Add Value To Set A or B\n");
		printf("3. Delete Value from Set A or Set B\n");
		printf("4. Calculate\n");
		printf("5. Display Data\n");
		printf("Choose: ");
		scanf("%d", &choose);
	
	
		switch(choose){
			case 1: 
			 	system("cls");
				addset(&s);
				break;
			
			case 2: 
			
				addElem(&s);
				break;
				
				
			case 3:
				deleteValue(&s);
				break;
				
			case 4:
				x = results(&s);
				display(s);
				printf("\n");
				printf("Union - \t");
				for(i = 0; i <MAX; i++){
					printf("%d ", x.setA[i]);
				}
				
				printf("\nIntersection - \t");
				
				for(i = 0; i <MAX; i++){
					printf("%d ", x.setB[i]);
				}
				printf("\n");
				
				
				system("pause");
				
				
				
				break;
			
			default:
				display(s);
				printf("\n");
				system("pause");
				break;
			
		}
		system("cls");
	}while(1);
		
	
	
	return 0;
}
