#include "Vending.h"
#include "File_Handling.h"
#include "Dispenser.h"
#include "CashRegister.h"


float acceptMoney (float *totalDeposit_ptr){
	
	float deposit; 
	scanf("%f",&deposit);
	*totalDeposit_ptr=*totalDeposit_ptr+deposit;

}

float currentBalance (float **total, float *totalDeposit_ptr){
	
	**total= **total - *totalDeposit_ptr;

}

float changeGiver(float *change,float *tempTotal_ptr, float *totalDeposit_ptr){
	
	*change = *totalDeposit_ptr - *tempTotal_ptr;
		
}

int checkCash(float *cashOnSystem){
	
	float cash;
	FILE *Fcash;
	Fcash=fopen("cashOnSystem.txt","r");
	fscanf(Fcash,"%f\n",&cash);
	*cashOnSystem=cash;
	fclose(Fcash);
	
}

int updateCash(float *cashOnSystem, float *totalDeposit,float *change){
	
	float updateCash, toDeposit;
	toDeposit= *totalDeposit - *change;
	updateCash = *cashOnSystem + toDeposit;
	FILE *Fcash;
	Fcash=fopen("cashOnSystem.txt","w");
	fprintf(Fcash,"%f\n",updateCash);
	fclose(Fcash);

	
}

int withdrawCash(float *toWithdraw){
	
	float cashOnSystem, updateCash;
	checkCash(&cashOnSystem);
	if(*toWithdraw>cashOnSystem){
		printf("\n\t\t Not enough available funds.");
		clear();
		depositCash();
	}
	updateCash= cashOnSystem- *toWithdraw;
	FILE *Fcash;
	Fcash=fopen("cashOnSystem.txt","w");
	fprintf(Fcash,"%f\n",updateCash);
	fclose(Fcash);
	
}
