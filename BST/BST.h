#ifndef BST
#define BST

#include <stdbool.h>
typedef struct{
    int day, month, year;
} Date;

typedef struct{
    char prodName[20];
    float price;
    int qty;
    Date expDate;
} Product;

typedef struct node{
    Product data;
    struct node *left;
    struct node *right;
} *Bst , Tree;

typedef struct nodeq{
    Bst node;
    struct nodeq *next;
} Node, *NodePtr;

typedef struct{
    NodePtr head;
    NodePtr rear;
} Queue;

void init(Bst *t);
void insert(Bst *t, Product p);
bool isMember(Bst t, Product p);
void deleteNode(Bst *t, Product p);
void intraverse(Bst t);
void pretraverse(Bst t);
void posttraverse(Bst t);
void initQueue(Queue *q);
void bsf(Bst t);
void enqueue(Queue *q, Bst node);
void dequeue(Queue *q);
bool isEmpty(Queue q);
Bst front(Queue q);







#endif 