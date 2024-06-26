#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"



void initDictionary(MyDictionary *md){
    md->count = 0;
    md->max = 10;
    md->threshold = 10 * 0.6;
    md->dict = malloc(10 * sizeof(mc_blocks));
    int i = 0;

    while(i < 10){
        strcpy(md->dict[i].blocks, EMPTY);
        i++;
    }
}

void initAccessList(AccessList *al){
    al->head = NULL;
    al->rear = NULL;
}
void insertInto(MyDictionary *md, AccessList *al, mc_blocks data){
    int key;
    int i = 0;
    key = hash(data.blocks, i, md->max);   
    printf("[%d]", key);  
    while(i < md->max && (strcmp(md->dict[key].blocks, EMPTY) != 0 && strcmp(md->dict[key].blocks, DELETED) != 0)){
        key = hash(data.blocks, i, md->max);   
        i++;
    }

    md->dict[key] = data;
   

    
    md->count++;

    printf("%d", key);

}
int hash(char blocks[], int i, int max){
    int x, y;
    int j, sum = 0;
    for(j = 0; j < 3; j++){
        sum = sum + blocks[j];
    }
    x = sum % max;

    y = sum + 186;
    y = y % 31;
    y = (y % max) + 1;

    printf("%d--", y);
    return (x + (i * y)) % max;

}
bool enqueue(AccessList *al, mc_blocks data);
bool dequeue(AccessList *al);
bool isEmpty(AccessList al);
mc_blocks front(AccessList al);
void visualize(MyDictionary md){
    int i;
    for(i = 0; i < md.max; i++){
        printf("%d. ", i);
        if(strcmp(md.dict[i].blocks, EMPTY) == 0){
            printf("Empty");
        } else {
           printf("%s", md.dict[i].blocks);
        }
        printf("\n");
        
    }
}
void display(NodePtr temp);
bool search(MyDictionary md, char data[]);
void resize(MyDictionary *md, AccessList *al);
mc_blocks retrieve(MyDictionary md, char data[]);
void delete(MyDictionary *md, AccessList *al, char data[]);
void updateData(MyDictionary *md,AccessList *al, char data[], char uData[]);