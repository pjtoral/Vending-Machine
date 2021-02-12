#include "Dispenser.h"
#include "Vending.h"
#include "File_Handling.h"

int getCount(int **id){
	
	int location,amountToBuy;
	readInventory();
	location=findID(**id);
	if(menu[location].quantityLeft==0){
			printf("\n\t\t This Item is Out of Stock!\n");
			clear();
			return main();
	}
	else{
			printf("\n\t\t How Many Would You Like: ");
			if(scanf("%d",&amountToBuy)!= 1){
				printf("\n\t\t Invalid Input...");
				clear();
				main();
			}
			if(amountToBuy>menu[location].quantityLeft){
					printf("\n\t\t Not Enough Stocks\n");
					clear();
					return main();
			}
			else if (amountToBuy == 0 ){
					printf("\n\t\t Thank you for Buying at CPTLC! Terminating Program....\n");
					clear();
					return main();
			}
			else{
					return amountToBuy;
			}
		
	}
	
}

int getProductCost(int **id, int *amountToBuy){
	
	int location;
	float total;
	readInventory();
	location=findID(**id);
	total=*amountToBuy*menu[location].price;
	return total;
	
	
}

int makeSale(float *total,int **choice_ptr,int *amountToBuy){
	
	int count, location;
	float deposit, totalDeposit=0,change=0, balance=0, tempTotal, cashOnSystem;
	tempTotal=*total;
	printf("\n\t\t That would be Php%0.2f in Total, Please Enter Your Payment: ",*total);
	acceptMoney(&totalDeposit);

		if(totalDeposit<*total){
			printf("\n\t\t Please insert more money. You lack %0.2f: ",*total-totalDeposit);
			acceptMoney(&totalDeposit);
			currentBalance(&total,&totalDeposit);

			if(*total>0){
			printf("\n\t\t You failed to deposit enough money. Transaction failed....");
			printf("\n\t\t Here is your deposit of %0.2f", totalDeposit);
			clear();
			main();
		}
		}
		
	currentBalance(&total,&totalDeposit);
	changeGiver(&change, &tempTotal , &totalDeposit);
	checkCash(&cashOnSystem);
	if(change>cashOnSystem){
		printf("\n\n\t\t We do not have enough change for your transaction...");
		printf("\n\t\t Here is your deposit of %0.2f\n", totalDeposit);
		clear();
		main();
	}
	else{
	
	count=readInventory();
	readInventory();
	location=findID(**choice_ptr);
	
		if(*amountToBuy==1){
			printf("\n\t\t Here is your %s and your change of Php %0.2f",menu[location].itemName,change);
			printf("\n\t\t Enjoy!");
		}
		else if(*amountToBuy>1){
			printf("\n\n\t\t Here are your %ss and your change of Php %0.2f",menu[location].itemName,change);
			printf("\n\n\t\t ENJOY!");
		}
		
	updateInventory(&change, &totalDeposit, &amountToBuy, &choice_ptr);
	updateCash(&cashOnSystem,&totalDeposit, &change);
	fclose(fptr);
	
	clear();

	return main();
		
		
	}
	
	
}



