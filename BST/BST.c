#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>



void init(Bst *t){
    *t = NULL;
}
void insert(Bst *t, Product p){
    if(*t == NULL){
        *t = (Bst)malloc(sizeof(Tree));
        (*t)->data = p;
        (*t)->left = NULL;
        (*t)->right = NULL;
        printf("Inserting %s\n", p.prodName);
    } else if(strcmp((*t)->data.prodName, p.prodName) > 0){
        insert(&(*t)->left, p);
    } else if(strcmp((*t)->data.prodName, p.prodName) < 0){
        insert(&(*t)->right, p);
    }
}

bool isMember(Bst t, Product p){
    printf("Searching %s\n", p.prodName);
    while(t != NULL && strcmp(t->data.prodName, p.prodName) != 0){
        t = strcmp(t->data.prodName, p.prodName) > 0 ? t->left : t->right;
    }
    if(t == NULL){
        printf("%s is not found\n", p.prodName);
        return false;
    }
    if(strcmp(t->data.prodName, p.prodName) == 0){
        printf("%s is found\n", p.prodName);
        return true;
    } else {
        printf("%s is not found\n", p.prodName);
        return false;
    }
}

void deleteNode(Bst *t, Product p){
    Bst *trav;
    Bst temp, temp1;
    printf("Deleting %s\n", p.prodName);
    if(isMember(*t, p)){
        printf("Deleting %s\n", p.prodName);
            while( *t != NULL && (strcmp((*t)->data.prodName, p.prodName) !=0)){
                t = strcmp((*t)->data.prodName, p.prodName) > 0 ? &(*t)->left : &(*t)->right;
            }
                temp = *t;
                if((*t)->left != NULL){
                    trav = &(*t)->left;
                    while(((*trav)->right!=NULL)){
                        trav = &(*trav)->right;				
                    }
                    temp1 = *trav;
                    *trav = temp1->left;
                }else if ((*t)->right != NULL){
                    trav = &(*t)->right;
                    while(((*trav)->left!=NULL)){
                        trav = &(*trav)->left;					
                    }
                    temp1 = *trav;
                    *trav = temp1->right;
                }else{
                    *t = NULL;
                    free(temp);
                }
                if((*t)->left != NULL || (*t)->right != NULL){
                    temp1->left = temp->left;
                    temp1->right = temp->right;
                    *t = temp1;
                    free(temp);
                 }
                printf("deleting of %s successful. %s is now in place of it.\n", p.prodName, (*t)->data.prodName);
    } else {
        printf("Data is not Found, failed to delete\n");
    }
}
void intraverse(Bst t){
    if(t != NULL){
        intraverse(t->left);
        printf("%s - ", t->data.prodName);
        intraverse(t->right);
    }
}
void pretraverse(Bst t){
    if(t != NULL){
        printf("%s - ", t->data.prodName);
        pretraverse(t->left);
        pretraverse(t->right);
    }
}

void posttraverse(Bst t){
    if(t != NULL){
        posttraverse(t->left);
        posttraverse(t->right);
        printf("%s - ", t->data.prodName);
    }
}



void initQueue(Queue *q){
    q->head = NULL;
    q->rear = NULL;
}
void bsf(Bst t){
    if(t == NULL){
        return;
    }
    Queue q;
    initQueue(&q);
    enqueue(&q, t);

    while(!isEmpty(q)){
        Bst cur = front(q);
        dequeue(&q);
        printf("%s - ", cur->data.prodName);

        if(cur->left != NULL){
            enqueue(&q, cur->left);
        }

        if(cur->right != NULL){
            enqueue(&q, cur->right);
        }
    }
}
void enqueue(Queue *q, Bst node){
     NodePtr newNode = malloc(sizeof(Node));
        newNode->node = node;
        newNode->next = NULL;
    if(q->head == NULL){
        q->head = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}
void dequeue(Queue *q){
    NodePtr temp = q->head;
    q->head = q->head->next;
    free(temp);
}

bool isEmpty(Queue q){
    return q.head == NULL ? true : false;
}

Bst front(Queue q){
    return q.head->node;
}