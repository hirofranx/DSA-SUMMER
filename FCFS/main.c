#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	proclist pl;
	pl.list = NULL;
	pl.sorted = NULL;
	
	
	
	int c, x, y;
	int ascii = 65;
	printf("Number of Process: ");
	scanf("%d", &c);
	
	while(c > 0){
		printf("BT: ");
		scanf("%d", &x);
		printf("AT: ");
		scanf("%d", &y);
		
		
		addprocess(&pl, x, y, ascii);
		insertsorted(&pl, x, y, ascii);
		ascii++;
		c--;
	}
	
	display(pl.list);
	
	
	Queue result = calculate(&pl);

	printf("First Come First Served\n");
	display(result.head);
	
	ganttchart(result);
	
	
	
	return 0;
}
