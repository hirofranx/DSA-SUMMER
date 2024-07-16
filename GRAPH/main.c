#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int matrix[5][5];
	init(matrix);
	
	addEdge(matrix, 'A', 'C');
	addEdge(matrix, 'A', 'B');
	addEdge(matrix, 'A', 'D');
	addEdge(matrix, 'D', 'C');
	addEdge(matrix, 'D', 'B');
	addEdge(matrix, 'D', 'E');
	addEdge(matrix, 'B', 'E');
	addEdge(matrix, 'B', 'C');
	//addEdge(matrix, 'l', 'e');
	
	printf("\n");
	display(matrix);
	
	int list[5][5];
	initList(list);
	
	printf("\n");
	addEdgeList(list, 'a', 'b');
	addEdgeList(list, 'a', 'C');
	addEdgeList(list, 'a', 'D');
	addEdgeList(list, 'd', 'c');
	addEdgeList(list, 'd', 'b');
	addEdgeList(list, 'd', 'e');
	addEdgeList(list, 'b', 'e');
	addEdgeList(list, 'b', 'c');
	

	displayList(list);
	
	
	
	
	return 0;
}
