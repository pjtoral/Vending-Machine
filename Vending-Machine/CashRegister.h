#ifndef cash_register_h
#define cash_register_h
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>

float currentBalance (float **total, float *totalDeposit_ptr); //calculates currentBalance
float acceptMoney(float *totalDeposit_ptr); //accepts money from user
float changeGiver(float *change,float *tempTotal_ptr, float *totalDeposit_ptr); //calculates the change
int checkCash(float *cashOnSystem);
int updateCash(float *cashOnSystem, float *totalDeposit,float *change);
int withdrawCash(float *toWithdraw);


#endif
