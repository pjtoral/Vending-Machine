#ifndef file_handling_h
#define file_handling_h
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>

int readInventory(); //reads the inventory file
void updateInventory(); //updates the inventory text file
int writeToFile(int count); //write to the inventory text file
int IDchecker(int **id); //checks for the ID of an existing product
int findID(int id); // Find for the location of the ID
int resetPassword(); //resets password to "password"
int changePassword(); //changes password

void clear(); //clears screen

#endif
