#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#include "FCFS.h"


void addprocess(proclist *pl, int x, int y, int letter){
	NodePtr newNode = malloc(sizeof(Node));
	
	newNode->proc.proc = letter;
	newNode->proc.AT = y;
	newNode->proc.BT = x;
	newNode->proc.CT = 0;
	newNode->proc.ET = 0;
	newNode->proc.TT = 0;
	newNode->proc.WT = 0;
	
	//insertList
	NodePtr trav = pl->list;
	
	if(pl->list == NULL){
		pl->list = newNode;
	} else {
		while(trav->next != NULL){
			trav = trav->next;
		}
		trav->next = newNode;
	}
	
}

void insertsorted(proclist *pl, int x, int y, int letter){
	NodePtr newNode = malloc(sizeof(Node));
	
	newNode->proc.proc = letter;
	newNode->proc.AT = y;
	newNode->proc.BT = x;
	newNode->proc.CT = 0;
	newNode->proc.ET = 0;
	newNode->proc.TT = 0;
	newNode->proc.WT = 0;
	
	//insertSorted
	NodePtr trav = pl->sorted;
	
	if(trav == NULL || trav->proc.AT > newNode->proc.AT){
		newNode->next = pl->sorted;
		pl->sorted = newNode;
	} else {
		while(trav->next != NULL && trav->next->proc.AT <= newNode->proc.AT){
		trav = trav->next;
		}
		newNode->next = trav->next;
		trav->next = newNode;
	}
	
}

bool isEmpty(proclist pl){
	
	return pl.list == NULL && pl.sorted == NULL ? true : false;	
}


void display(NodePtr list){
	NodePtr trav = list;
	float ttave, wtave;
	int tt = 0, wt = 0; 
	float counter = 0;
	
	if(trav == NULL){
	printf("No data");
	}
	printf("Process\tBT\tAT\tWT\tET\tCT\tTT\n");
	while(trav != NULL){
		printf("%c. \t%d\t%d\t%d\t%d\t%d\t%d\n", trav->proc.proc, trav->proc.BT, trav->proc.AT, trav->proc.WT, trav->proc.ET, trav->proc.CT, trav->proc.TT);
		tt = tt + trav->proc.TT;
		wt = wt + trav->proc.WT;
		counter++;
		trav = trav->next;
	}
	ttave = tt/counter;
	wtave = wt/counter;
	printf("\t\tWTAVE = %.2f\t\tTTAVE = %.2f\t", wtave, ttave );
	printf("\n\n");
}


Queue calculate(proclist *pl){
	NodePtr travs = pl->sorted;
	Queue q;
	q.head = NULL;
	q.rear = NULL;
	Queue result;
	result.head = NULL;
	result.rear = NULL;
	
	while(travs != NULL){
		enqueue(&q, travs->proc);
		travs = travs->next;
	}
	
	int timer = 0;
	while(!queueIsEmpty(q)){
		process p = front(q);	
		p.ET  = (timer >= p.AT) ? timer : p.AT;
		
		p.CT = p.ET + p.BT;
		timer = p.CT;
		p.WT = (timer > p.AT)? p.ET - p.AT : 0;
		p.TT = p.CT - p.AT;
	
		

		dequeue(&q);
	enqueue(&result, p);


	}	
	return result;	
}



bool enqueue(Queue *q, process proc){
	NodePtr newNode = malloc(sizeof(Node));
	newNode->proc = proc;
	newNode->next = NULL;
	
	if(queueIsEmpty(*q)){
		q->head = newNode;
	} else {
		q->rear->next = newNode;
	}
	q->rear = newNode;
	
	
	
}
bool dequeue(Queue *q){
	if(!queueIsEmpty(*q)){
		NodePtr temp = q->head;
		q->head = q->head->next;
		free(temp);
		return true;
	}
	
	return false;
	
	
}
bool queueIsEmpty(Queue q){
	return q.head == NULL ? true : false;
}

process front(Queue q){
	process p = q.head->proc;
	
	return p;
	
}

void ganttchart(Queue result){
	NodePtr trav = result.head;
	int i, j, k;
	NodePtr tempdata = trav;

	if(trav->proc.ET > 0){
		printf("|-");
	} 
	printf("|\t%c\t", trav->proc.proc);
	tempdata = trav;
	trav = trav->next;
	while(trav != NULL){
		if(trav->proc.ET - tempdata->proc.CT > 0){
			printf("|-");
		}
			printf("|\t%c\t", trav->proc.proc);
			tempdata = trav;
			trav = trav->next;
	}
	printf("|\n");
	
	
	trav = result.head;
	if(trav->proc.ET == 0){
		printf("%d\t\t", trav->proc.ET);
	} else {
		printf("0-%d\t\t", trav->proc.ET);
	}
		printf("%d", trav->proc.CT);
	
	
	tempdata = trav;
	trav = trav->next;
	while(trav != NULL){	
		if(trav->proc.ET - tempdata->proc.CT != 0){
			printf(" %d", trav->proc.ET);
		} 
		printf("\t\t%d", trav->proc.CT);
		tempdata = trav;

		trav = trav->next;
	}
	
	
	
	
	
	
	
}



