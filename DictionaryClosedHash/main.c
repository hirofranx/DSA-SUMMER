#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include "dictionary.c" //comment line if using dev-c++
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
    MyDictionary md;
    initDictionary(&md);
    AccessList al;
    initAccessList(&al);
    mc_blocks data1 = {"sand", 64};
	mc_blocks data2 = {"grass", 64};
	mc_blocks data3 = {"wool", 64};
	mc_blocks data4 = {"wood", 64};
	mc_blocks data5 = {"lapis", 64};
	mc_blocks data6 = {"diamond", 64};
	mc_blocks data7 = {"planks", 64};
	mc_blocks data8 = {"wood", 64};

    insertInto(&md, &al, data3);
    insertInto(&md, &al, data4);
    insertInto(&md, &al, data1);
    insertInto(&md, &al, data2);
    insertInto(&md, &al, data5);
    insertInto(&md, &al, data5);
    insertInto(&md, &al, data7);

    printf("\n\n");
    visualize(md);
    printf("\n\n");
    //display(al.head);

    mc_blocks temp = retrieve(md, "diamond");
    printf("Retrieving \"diamond\" data...\n");
    if(strcmp(temp.blocks, EMPTY) != 0){
        printf("%s with %d is acquired", temp.blocks, temp.count);
    } else {
        printf("Data not found\n\n");
    }
 
    system("pause");
    system("cls");

    printf("Deleting Sand Data\n");
    delete(&md, &al,"sand");

    printf("\n\n");
    visualize(md);
    printf("\n\n");
    


    system("pause");
    system("cls");
    printf("Updating wood data into emerald\n");
	updateData(&md, &al, "wood", "emerald");
	printf("\n\nUpdated Data: \n");
	visualize(md);
 
    //display(al.head); //display accesslist


    return 0;

}