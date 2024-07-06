#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "BST.c"




int main(){

    Bst t;
    init(&t);

    Product p1 = {"TheBar", 135.00, 1, {3,2, 2025}};
    Product p2 = {"GSM", 135.00, 1, {3,2, 2025}};
    Product p3 = {"Primiera", 135.00, 1, {3,2, 2025}};
    Product p4 = {"Select", 135.00, 1, {3,2, 2025}};
    Product p5 = {"Tanduay", 135.00, 1, {3,2, 2025}};
    Product p6 = {"BlackLabel", 135.00, 1, {3,2, 2025}};
    Product p7 = {"Mojitos", 135.00, 1, {3,2, 2025}};
    Product p8 = {"Boracay", 135.00, 1, {3,2, 2025}};

    insert(&t, p5);
    insert(&t, p2);
    insert(&t, p3);
    insert(&t, p4);
    insert(&t, p1);
    insert(&t, p6);
    insert(&t, p7); 

    
    printf("\nPrinting Inorder\n");
    intraverse(t);
    printf("\n\nPrinting Preorder\n");
    pretraverse(t);
    printf("\n\nPrinting Postorder\n");
    posttraverse(t);
    printf("\n\nPrinting BSF\n");
    bsf(t);




    printf("\n\nCheking if %s is a member\n", p8.prodName);
    isMember(t, p8);


    deleteNode(&t, p2);

    printf("\n\n");

    printf("\nPrinting Inorder\n");
    intraverse(t);
    printf("\nPrinting Preorder\n");
    pretraverse(t);
    printf("\nPrinting Postorder\n");
    posttraverse(t);
    printf("\nPrinting BSF\n");
    bsf(t);

    printf("\nPrinting BSF\n");
    bsf(t);
    
    return 0;
}