#ifndef FCFS
#define FCFS

#include <stdbool.h>

typedef struct{
	int proc;
	int AT;
	int BT;
	int WT;
	int ET;
	int CT;
	int TT;
} process;


typedef struct node{
	process proc;
	struct node* next;
} Node, *NodePtr;

typedef struct{
	NodePtr list;
	NodePtr sorted;
} proclist;

typedef struct{
	NodePtr head;
	NodePtr rear;
	float ttave;
	float wtave;
} Queue;



void addprocess(proclist *pl, int x, int y, int letter);
void insertsorted(proclist *pl, int x, int y, int letter);
bool isEmpty(proclist pl);
void display(NodePtr list);
Queue calculate(proclist *pl);

bool enqueue(Queue *q, process proc);
bool dequeue(Queue *q);
bool queueIsEmpty(Queue q);
process front(Queue q);
void ganttchart(Queue result);





#endif
