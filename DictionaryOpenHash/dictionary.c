#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"


void initDictionary(MyDictionary *md){
	md->count = 0;
	md->max = 10;
	md->threshold = 10 * 0.6;
	md->dict = malloc(md->max * sizeof(MyDictionary));
	int i = 0;
	while(i < 10){
		md->dict[i] = NULL;
		i++;
	}

}
void initAccessList(AccessList *al){
	al->front = NULL;
	al->rear = NULL;
}

void insertInto(MyDictionary *md, AccessList *al, mc_blocks data){
	if(search(*md, data.blocks) == false){
		NodePtr newNode = malloc(sizeof(Node));
		if(md->count + 1 > md->threshold){
			resize(md, al);
		}
		int key = hash(data.blocks, md->max);
		NodePtr *trav = &md->dict[key];
		newNode->data = data;
		
		while(*trav != NULL && strcmp((*trav)->data.blocks, newNode->data.blocks) > 0){
			trav = &(*trav)->next;
		}
		newNode->next = *trav;
		*trav = newNode;
		
		md->count++;
		enqueue(al, data);
	} else {
		printf("Block %s Already Acquired!\n",  data.blocks );
	}
}


int hash(char blocks[], int max){
	int i, sum = 0;
	for(i = 0; i < 3; i++){
		sum = sum + blocks[i];
	}
	
	return sum % max;
}
bool enqueue(AccessList *al, mc_blocks data){
	NodePtr newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	NodePtr *trav = &al->front;
	
	while(*trav != NULL){
		trav = &(*trav)->next;
	}
	*trav = newNode;
	
	al->rear = newNode;
}
bool dequeue(AccessList *al){
	if(!isEmpty(*al)){
		NodePtr temp = al->front;
		al->front = al->front->next;
		free(temp);
		return true;
	}
	return false;
}
bool isEmpty(AccessList al){
	return al.front == NULL ? true : false;
}
mc_blocks front(AccessList al){
	return al.front->data;
}
void visualize(MyDictionary md){
	int i;
	NodePtr trav;
	for(i = 0; i < md.max; i++){
		trav = md.dict[i];
		if(trav != NULL){
			while(trav != NULL){
				printf("-[%s]-", trav->data.blocks);
				trav = trav->next;
			}
			printf("\n");
		}
	}
}
void display(NodePtr temp){
	while(temp != NULL){
		printf("%s\n", temp->data.blocks);
		temp = temp->next;
	}
}
bool search(MyDictionary md, char data[]){
	NodePtr trav;
	int key = hash(data, md.max);

	trav = md.dict[key];
	while(trav != NULL){
		if(strcmp(trav->data.blocks, data) == 0){
			return true;
		}
		trav = trav->next;
	}
	return false;
}

void resize(MyDictionary *md, AccessList *al){
	NodePtr *trav;
	NodePtr temp;
	int i;
	
	for(i = 0; i < md->max; i++){
		trav = &(*md).dict[i];
		while(*trav != NULL){
			temp = *trav;
			*trav = temp->next;
			free(temp);
		}
	}
	
	free(md->dict);
	i = 0;
	md->max *= 2;
	md->threshold = md->max * 0.6;
	md->dict = malloc(md->max * sizeof(MyDictionary));
	
	while(i < md->max){
		md->dict[i] = NULL;
		i++;
	}
	
	mc_blocks tempdata;
	NodePtr newNode; 
	NodePtr *travd;
	int key;
	int j = 0;
	while(j < md->count){
		tempdata = front(*al);
		dequeue(al);
		newNode = malloc(sizeof(Node));
		newNode->data = tempdata;
		key = hash(newNode->data.blocks, md->max);
		
		travd = &(*md).dict[key];
		
		while(*travd != NULL && strcmp((*travd)->data.blocks, newNode->data.blocks) > 0){
			travd = &(*travd)->next;
		}
		newNode->next = *travd;
		*travd = newNode;
		enqueue(al, tempdata);
		j++;
	}		
}

mc_blocks retrieve(MyDictionary md, char data[]){
	if(search(md, data) == true){
		NodePtr trav;
		int key = hash(data, md.max);

		trav = md.dict[key];
		while(trav != NULL){
			if(strcmp(trav->data.blocks, data) == 0){
				return trav->data;
			}
			trav = trav->next;
		}
	}
}

void delete(MyDictionary *md, AccessList *al, char data[]){
	if(search(*md, data) == true){
		NodePtr *trav, temp;
		int key = hash(data, md->max);

		trav = &(*md).dict[key];
		while((*trav) != NULL){
			if(strcmp((*trav)->data.blocks, data) == 0){
				temp = *trav;
				*trav = (*trav)->next;
				free(temp);
			} else {
				trav = &(*trav)->next;
			}
		}

		AccessList tmp;
		initAccessList(&tmp);
		mc_blocks tmpdata;

		while(!isEmpty(*al)){
			tmpdata = front(*al);
			dequeue(al);
			if(strcmp(tmpdata.blocks, data) != 0){
				enqueue(&tmp, tmpdata);
			}
		}

		while(!isEmpty(tmp)){
			tmpdata = front(tmp);
			dequeue(&tmp);
			enqueue(al, tmpdata);
		}
		md->count--;
		printf("Successfully Deleted Data\n");

	} else {
		printf("Data Not Found\n");
	}
}

void updateData(MyDictionary *md,AccessList *al, char data[], char uData[]){
	if(search(*md, uData) == false){
		if(search(*md, data) == true){
			NodePtr *trav, temp;
			int key = hash(data, md->max);
			mc_blocks holder = retrieve(*md, data);
			strcpy(holder.blocks, uData);
			
			trav = &(*md).dict[key];
			while(*trav != NULL){
				if(strcmp((*trav)->data.blocks, data) == 0){
					temp = *trav;
					*trav = (*trav)->next;
					free(temp);
				} else {
					trav = &(*trav)->next;
				}
			}

			NodePtr *uTrav;
			NodePtr newNode = malloc(sizeof(Node));
			newNode->data = holder;
			int uKey = hash(newNode->data.blocks, md->max);
			uTrav = &(*md).dict[uKey];
			while(*uTrav != NULL && strcmp((*uTrav)->data.blocks, newNode->data.blocks) > 0){
				uTrav = &(*uTrav)->next;
			}
			newNode->next = *uTrav;
			*uTrav = newNode;


			AccessList tmp;
			initAccessList(&tmp);
			mc_blocks tmpdata;

			while(!isEmpty(*al)){
				tmpdata = front(*al);
				dequeue(al);
				if(strcmp(tmpdata.blocks, data) == 0){
					strcpy(tmpdata.blocks, uData);
				}
				enqueue(&tmp, tmpdata);
			}

			while(!isEmpty(tmp)){
				tmpdata = front(tmp);
				dequeue(&tmp);
				enqueue(al, tmpdata);
			}
			printf("Successfully Updated Data\n");

		} else {
			printf("Data Not Found\n");
		}
	} else {
		printf("Data Already Exists, Cannot Change Current Data\n");
	}
}

