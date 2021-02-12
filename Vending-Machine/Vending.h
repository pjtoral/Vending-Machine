#ifndef vending_h
#define vending_h
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>

//function prototypes
int mainMenu(int *select_ptr);
int showSelection(int *choice_ptr);
int sellProduct(int *choice_ptr);


typedef struct{
		
		int itemID;
		char itemName[150];
		int quantityLeft;
		int quantitySold;
		float price;
		float totalSales;
		
	}Inventory;
	
Inventory menu[30]; //maximum items that can be sold
FILE *fptr;

#endif
