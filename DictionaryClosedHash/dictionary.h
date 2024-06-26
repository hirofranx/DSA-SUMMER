#ifndef dictionary
#define dictionary
#include <stdbool.h>

#define EMPTY "empty"
#define DELETED "deleted"

typedef struct{
    char blocks[20];
    int count;
} mc_blocks;

typedef struct{
	mc_blocks *dict;
	int count;
	int max;
	int threshold;
} MyDictionary;

typedef struct node{
    mc_blocks data;
    struct node* next;
}Node, *NodePtr;

typedef struct{
    NodePtr head;
    NodePtr rear;
} AccessList;

void initDictionary(MyDictionary *md);
void initAccessList(AccessList *al);
void insertInto(MyDictionary *md, AccessList *al, mc_blocks data);
int hash(char blocks[],int i, int max);
bool enqueue(AccessList *al, mc_blocks data);
bool dequeue(AccessList *al);
bool isEmpty(AccessList al);
mc_blocks front(AccessList al);
void visualize(MyDictionary md);
void display(NodePtr temp);
bool search(MyDictionary md, char data[]);
void resize(MyDictionary *md, AccessList *al);
mc_blocks retrieve(MyDictionary md, char data[]);
void delete(MyDictionary *md, AccessList *al, char data[]);
void updateData(MyDictionary *md,AccessList *al, char data[], char uData[]);






#endif 
