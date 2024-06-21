#ifndef UnIn
#define Unin


#define MAX 8

typedef struct{
	int setA[MAX];
	int setB[MAX];
} set;

void initset(set *s);
void addset(set *s);
void addElem(set *s);
void deleteValue(set *s);
set results(set *s);
void display(set s);



#endif
