#include "Vending.h"
#include "Dispenser.h"
#include "File_Handling.h"
#include "Managers_Access.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main() {
	
	int select, choice;
	mainMenu(&select);
	switch(select){
		
		case 1: 
			showSelection(&choice);
			sellProduct(&choice);
			break;
		case 2:
			passwordGetter();
			break;
		case 3:
			printf("\n\t\t Thank you for Buying at CPTLC! Terminating Program....\n");
			clear();
			exit(0);
		default :
            printf("\t\t An Error Has Occured. Terminating Program....");
            clear();
            break;
	}
	

	getch();
	return 0;
	
}

int mainMenu(int *select_ptr){
	
	printf("\n\n");
	printf("\t\t                    *** WELCOME TO CPTLC ***                       \n ");
	printf("\n\t\t=================================================================\n");
	printf("\t\t                      PLEASE CHOOSE AN ITEM                      \n");
	printf("\t\t=================================================================\n");
	printf("\t\t\t Press:\n");
	printf("\t\t\t\t [1] To Buy a Product\n");
	printf("\t\t\t\t [2] To Access Manager Options\n");
	printf("\t\t\t\t [3] To Exit the Program\n\n");
	printf("\t\t=================================================================\n");
	printf("\n\t\t\t Your Choice: ");
	scanf("%d", select_ptr);
	
	
	return ;
}


int showSelection(int *choice_ptr){
	
	system("cls");
	Sleep(500);
	int x=0,i,j,items, count;
	count=readInventory();
	readInventory();
	items=count;
	if(count<0){
		printf("\n\t\tNo Inventory Recorded");
	}
	printf(" \n\n\t\t\t\t        *****  MENU  *****\n");
	printf("\t\t\t    -------------------------------------------\n");
	printf("\t\t\t    | I.D |     NAME     | QUANTITY |  PRICE  |\n");
	printf("\t\t\t    -------------------------------------------\n");
	
	
		for(i=0;i<items;i++){
			
			if(menu[i].quantityLeft!=0){
			printf("\t\t\t       %d     %-10s       %-7d Php%-5.2f    \n",menu[i].itemID,menu[i].itemName,menu[i].quantityLeft, menu[i].price);
			}
			
		}
		
		
	fclose(fptr);

	printf("\n\t\t Enter the I.D. of the product you would like to buy, press [0] to cancel: ");
	scanf("%d", choice_ptr);
	

	return;
	
}

int sellProduct(int *choice_ptr){
	
	int checker,amountToBuy;
	float total;
	checker=IDchecker(&choice_ptr);
	if(checker==1){
		printf("\n\t\t ID does not exist\n");
		clear();
		return main();
	}
	else{
		amountToBuy=getCount(&choice_ptr);
		total=getProductCost(&choice_ptr, &amountToBuy);
		makeSale(&total,&choice_ptr,&amountToBuy);
		
	}
	
	return;
}


