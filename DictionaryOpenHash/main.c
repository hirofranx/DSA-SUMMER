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


	printf("Data 1. %s -- %d units\n", data1.blocks, data1.count);
	printf("Data 2. %s -- %d units\n", data2.blocks, data2.count);
	printf("Data 3. %s -- %d units\n", data3.blocks, data3.count);
	printf("Data 4. %s -- %d units\n", data4.blocks, data4.count);
	printf("Data 5. %s -- %d units\n", data5.blocks, data5.count);
	printf("Data 6. %s -- %d units\n", data6.blocks, data6.count);
	printf("Data 7. %s -- %d units\n", data7.blocks, data7.count);
	printf("Data 8. %s -- %d units\n", data8.blocks, data8.count);
	
	printf("Inserting All These Data ...\n");

	insertInto(&md, &al, data1);
	insertInto(&md, &al, data2);
	insertInto(&md, &al, data3);
	insertInto(&md, &al, data4);
	insertInto(&md, &al, data5);
	insertInto(&md, &al, data6);
	insertInto(&md, &al, data7);
	insertInto(&md, &al, data8);

	printf("\n\nData: \n\n");
	visualize(md);
	
	system("pause");
	system("cls");

	printf("Deleting wood data\n\n");

	delete(&md, &al, "wood");
	printf("\n\nUpdated Data: \n");
	visualize(md);
	
	system("pause");
	system("cls"); 

	printf("Updating diamond data into emerald\n\n");
	updateData(&md, &al, "diamond", "emerald");
	printf("\n\nUpdated Data: \n");
	visualize(md);

	system("pause");
	system("cls"); 


	//display(al.front); // accesslist display



	return 0;
}
