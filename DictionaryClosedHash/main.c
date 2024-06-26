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
    printf("\n\n");
    visualize(md);

    return 0;

}