#ifndef dispenser_h
#define dispenser_h
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>


int getCount(int **id);
int getProductCost(int **id, int *amountToBuy);
int makeSale(float *total,int **choice_ptr,int *amountToBuy);

#endif
