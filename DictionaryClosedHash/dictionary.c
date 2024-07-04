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
        md->dict[i].count = -1;
        i++;
    }
}

void initAccessList(AccessList *al){
    al->head = NULL;
    al->rear = NULL;
}
void insertInto(MyDictionary *md, AccessList *al, mc_blocks data){
    
    if(!search(*md, data.blocks)){
        if(md->count + 1 == md->threshold){
            resize(md, al);
        }
            int key = hash(data.blocks, md->max) % md->max;
            int i;

            for(i = 0; i < md->max && (strcmp(md->dict[key].blocks, EMPTY) != 0 && strcmp(md->dict[key].blocks, DELETED) != 0);key = (key+1) % md->max, i++){}
            if(i < md->max){
                printf("Inserting %s to index %d\n", data.blocks, key);
                md->dict[key] = data;
                enqueue(al, data);
                md->count++;
            }
    } else {
        printf("Block %s already acquired!\n", data.blocks);
    }
} 


int hash(char blocks[], int max){
    int i;
    int sum = 0;
    for(i = 0; i < 3; i++){
        sum += blocks[i];
    }
    return sum;
}
bool enqueue(AccessList *al, mc_blocks data){
    NodePtr newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    NodePtr *trav = &al->head;

    while(*trav != NULL){
        trav = &(*trav)->next;
    }
    *trav = newNode;

    al->rear = newNode;
}
bool dequeue(AccessList *al){
    if(!isEmpty(*al)){
		NodePtr temp = al->head;
		al->head = al->head->next;
		free(temp);
		return true;
	}
	return false;
}
bool isEmpty(AccessList al){
    return al.head == NULL ? true : false;
}
mc_blocks front(AccessList al){
    return al.head->data;
}
void visualize(MyDictionary md){
    int i;
    for(i = 0; i < md.max; i++){
        printf("%d. ", i);
        if(strcmp(md.dict[i].blocks, EMPTY) == 0 || strcmp(md.dict[i].blocks, DELETED) == 0){
            printf("[]");
        } else {
           printf("%s ", md.dict[i].blocks);
        }
        printf("\n");
        
    }
}
void display(NodePtr temp){
    while(temp != NULL){
        printf("%s, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
bool search(MyDictionary md, char data[]){
    int i;
    bool ret = false;
    int key = hash(data, md.max) % md.max;
    for(i = 0; i < md.max && strcmp(md.dict[key].blocks, data) != 0;key = (key+1) % md.max, i++){}
        if(i != md.max){
           ret = true;
        } 
    return ret;

}
void resize(MyDictionary *md, AccessList *al){
    printf("Resizing...\n");
    int i = 0;
    free(md->dict);
    md->max *= 2;
    md->dict = malloc(md->max * sizeof(mc_blocks));
    md->threshold = md->max * 0.6;

    while(i < md->max){
        strcpy(md->dict[i].blocks, EMPTY);
        md->dict[i].count = -1;
        i++;
    }
    int key;
    mc_blocks tempdata;
    int j = 0;
    while(j < md->count){
        tempdata = front(*al);
        dequeue(al);
        key = hash(tempdata.blocks, md->max) % md->max;
        for(i = 0; i < md->max && (strcmp(md->dict[key].blocks, EMPTY) != 0 && strcmp(md->dict[key].blocks, DELETED) != 0);key = (key+1) % md->max, i++){}
        if(i < md->max){
            md->dict[key] = tempdata;
            printf("Inserting %s into index %d\n", tempdata.blocks, key);
        }
        enqueue(al, tempdata);
        j++;
    }
    printf("Resizing finished...\n");

}

mc_blocks retrieve(MyDictionary md, char data[]){
    int i;
    mc_blocks ret;
    strcpy(ret.blocks, EMPTY);
    int key = hash(data, md.max) % md.max;
    for(i = 0; i < md.max && strcmp(md.dict[key].blocks, data) != 0;key = (key+1) % md.max, i++){}
        if(i != md.max){
           ret = md.dict[key];
        } 
    return ret;
}
void delete(MyDictionary *md, AccessList *al, char data[]){
    int i;
    mc_blocks tempdata;
    AccessList temp;
    initAccessList(&temp);
    if(search(*md, data)){
        int key = hash(data, md->max) % md->max;
        for(i = 0; i < md->max && strcmp(md->dict[key].blocks, data) != 0;key = (key+1) % md->max, i++){}
            if(i != md->max){
                strcpy(md->dict[key].blocks, DELETED);
                md->dict[key].count = -1;

                while(!isEmpty(*al)){
                    tempdata = front(*al);
                    dequeue(al);

                    if(strcmp(tempdata.blocks, data) != 0){
                        enqueue(&temp, tempdata);
                    }
                }

                while(!isEmpty(temp)){
                    tempdata = front(temp);
                    dequeue(&temp);
                    enqueue(al, tempdata);
                }
                md->count--;

                printf("Successfully deleted %s\n", data);
             
            } 
    }   else {
        printf("Data not found.\n");
    }
}

void updateData(MyDictionary *md,AccessList *al, char data[], char uData[]){
    int i, j;
    mc_blocks tempdata;
    AccessList temp;
    initAccessList(&temp);
    if(search(*md, data)){
        int key = hash(data, md->max) % md->max;
        for(i = 0; i < md->max && strcmp(md->dict[key].blocks, data) != 0;key = (key+1) % md->max, i++){}
            if(i != md->max){
                tempdata = md->dict[key];
                strcpy(md->dict[key].blocks, DELETED);
                md->dict[key].count = -1;
                key = hash(uData, md->max);
                for(j = 0; j < md->max && (strcmp(md->dict[key].blocks, EMPTY) != 0 && strcmp(md->dict[key].blocks, DELETED) != 0);key = (key+1) % md->max, j++){}
                if(i < md->max){
                    strcpy(tempdata.blocks, uData);
                    md->dict[key] = tempdata;
                }

                while(!isEmpty(*al)){
                    tempdata = front(*al);
                    dequeue(al);

                    if(strcmp(tempdata.blocks, data) != 0){
                        enqueue(&temp, tempdata);
                    }
                }

                while(!isEmpty(temp)){
                    tempdata = front(temp);
                    dequeue(&temp);
                    enqueue(al, tempdata);
                }  
                printf("Successful updating \"%s\" data into \"%s\".\n\"%s\" new index at %d",data, uData, uData, key);    
            } 
    }   else {
        printf("Data not found.\n");
    }
}