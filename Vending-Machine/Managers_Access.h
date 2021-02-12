#ifndef managersAccess_h
#define managersAccess_h
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>


void managersList(); //prints the managers access list
void managersAccess(); // only managers who know the password can get in
int passwordGetter();  //gets password for managers access
void addProduct(); //adds product to txt file
void editProduct(); //edits products and writes to text file
void deleteInventory(); //deletes product from txt file
void printInventory(); //prints txt file including sales and etc.
int mngrChecker(int id); //managers check ID for product
int enterPassword(); // asks for password to get into the password settings
int depositCash();
int passwordList(); //list for the password settings

#endif
