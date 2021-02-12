#include "Managers_Access.h"
#include "Vending.h"
#include "File_Handling.h"

void managersList(){
	
	printf("\n\t=================================================================\n");
	printf("\t                         MANAGERS ACCESS                         \n");
	printf("\t=================================================================\n");
	printf("\t\t Press:\n");
	printf("\t\t\t [1] To Add a Product\n");
	printf("\t\t\t [2] To Edit an Existing Product\n");
	printf("\t\t\t [3] To Delete an Existing Product\n");
	printf("\t\t\t [4] To Print Inventory\n");
	printf("\t\t\t [5] To Access Cash on System\n");
	printf("\t\t\t [6] To Change Password\n");
	printf("\t\t\t [7] To Go Back to Main Menu\n");
	printf("\t\t\t [8] To Exit the Program\n\n");
	printf("\t=================================================================\n");
	
	
	
}

void managersAccess(){
	
	managersList();
	int choice;
	
	printf("\n\t\t Your Choice: ");
	scanf("%d",&choice);
	printf("\n");
	
	
	switch(choice){
		
		case 1:
			system("cls");
			printInventory();
			addProduct();
			break;
		case 2:
			system("cls");
			printInventory();
			editProduct();
			break;
		case 3:
			system("cls");
			printInventory();
			deleteInventory();
			break;
		case 4:
			system("cls");
			printInventory();
			clear();
			managersAccess();
			break;
		case 5:
			system("cls");
			depositCash();
			clear();
			managersAccess();
			break;
		case 6:
			enterPassword();
			break;
		case 7:
			system("cls");
			Sleep(500);
			main();
			break;
		case 8:
			printf("\n\t\tThank you! Terminating Program....\n");
			clear();
			exit(0);
			break;
		default :
            printf("\t\t An Error Has Occured. Terminating Program....\n");
            break;
	}

	return;
	
	
}

int passwordGetter(){
	
	char input[20], password[20];
	FILE *Fpass;
	Fpass = fopen("passList.txt", "r"); 
	while(!feof(Fpass)){
		fgets (password, 20, Fpass);
		password[strlen(password)] = 0;
	}

	printf("\n\t\t\t Please input the password: ");
	scanf("%s",input);
	
	if((strcasecmp(input , password) == 0) ){
		
			printf("\n\t\t\t ACCESS GRANTED");
			Sleep(500);
			system("cls");
			managersAccess();
	}
	else{
			printf("\n\t\t\t INVALID PASSWORD\n");
			clear();
			return main();
			
		}
	
}

void addProduct(){
	
	//count for now is 0 because arrays start at 0, but if there is already text in the file then count has been incremented already
	
	int checker, count;
	count=readInventory();
	printf("\n\n\t\t\t        ENTER NEW PRODUCT \n");
	readInventory();
	if(count>0){
		count=readInventory();
	}
	
		printf("\n\t\t Product ID Number: ");
		scanf("%d",&menu[count].itemID);
		
		if(menu[count].itemID < 0){
			printf("\n\t\t Invalid ID format");
			clear();
			return managersAccess();
		}
		
		checker=mngrChecker(menu[count].itemID);
		if(checker==1){
				
		printf("\t\t Product Name: ");
		scanf("%s",menu[count].itemName);
		printf("\t\t Quantity of the product: ");
		scanf("%d",&menu[count].quantityLeft);
		printf("\t\t Price of the product: ");
		scanf("%f",&menu[count].price);
		
		count++; //this indicates that there is a new product being added
		
		writeToFile(count);
		clear();
		printf("\n");
		printf("\t                        ANYTHING ELSE?                           \n\n");

		return managersAccess();
			}
		else
			printf("\t\t ID is already taken");
			clear();
	return managersAccess();
	
}

void editProduct(){
	
	int i,id, checker, count;
	int choice;
	count=readInventory();
	readInventory(); //to recall all inventory
	printf("\n\n\t\t\t     ENTER PRODUCT ID TO EDIT \n");
	printf("\n\t\t Product ID:");
	scanf("%d",&id);
	checker=mngrChecker(id);
	if(checker==1){
		printf("\t\t ID does not exist");
	}
	else{
		readInventory();
	{
		
	for(i=0;i<count;i++){
		
		if(id != menu[i].itemID){ //if its not the same ID write the inventory
			writeToFile(count);
		}else{ //when the ID being searched is already in line
			printf("\n\t\t [1] Update product ID Number?");
		    printf("\n\t\t [2] Update Name of the product? ");
		    printf("\n\t\t [3] Update Quantitiy of the product?");
		    printf("\n\t\t [4] Update Price of the product?");
		    printf("\n\t\t Enter your choice:");
			scanf("%d",&choice);
			
			switch(choice){
				
				case 1:
					printf("\t\t Enter New Product ID Number:");
					scanf("%d",&menu[i].itemID);
					checker=mngrChecker(menu[i].itemID);
					if(checker == 0){
						printf("\n\t\t I.D. already exists...");
						clear();
						managersAccess();
					}
					break;
				case 2:
					printf("\t\t Enter New Product Name:");
					gets(menu[i].itemName);
					break;
				case 3:
					printf("\t\t Enter New Product Quantity:");
					scanf("%d",&menu[i].quantityLeft);
					break;
				case 4:
					printf("\t\t Enter New Product Price:");
					scanf("%f",&menu[i].price);
					break;
				default:
					printf("\n\t\t An Error Has Occured. Terminating Program....");
					clear();
					exit(0);
           			break;
				}
			writeToFile(count);
			}
		}
	}
	fclose(fptr);
	fptr=fopen("Inventory.txt","r");
	readInventory();
		{
			writeToFile(count);
		}
	fclose(fptr);
	printf("\t\t RECORD UPDATED");
		
	}
	clear();
	printf("\n");
	printf("\t                        ANYTHING ELSE?                           \n");

	
	return managersAccess();
}



void deleteInventory(){

	
	int i,j,id,checker,count;
	count=readInventory();
	readInventory();
	
	printf("\n\n\t\t ENTER PRODUCT ID TO DELETE PRODUCT\n"); //check alignment daw pj
	printf("\n\t\t Product ID:");
	scanf("%d",&id);
	checker=mngrChecker(id);
	if(checker==1){
		printf("\t\t Product does not exist");
	}
	else{
		readInventory();
	{
		
	for(i=0;i<count;i++){
		
		if(id != menu[i].itemID){ //if its not the same ID write the inventory
			writeToFile(count);
		}
		else{
			for(j=i;j<(count-1);j++)
			{
				menu[j]=menu[j+1];
				
			}
			count--;
		}
		}
		
		}
	writeToFile(count);
	fclose(fptr);
	printf("\t\t RECORD UPDATED");
		
	}
	clear();
	printf("\n");
	printf("\t                        ANYTHING ELSE?                           \n");

	
	return managersAccess();

}

void printInventory(){
	
	int i,count;
	count=readInventory();
	readInventory();
	
	if(count<0){
		printf("\n\t\tNo Inventory Recorded");
	}
	printf(" \n\n\t\t\t      *****  INVENTORY  *****\n");
	printf("\t---------------------------------------------------------------------\n");
	printf("\t|    NAME     |  PROD ID  |  QUANTITY | PROD SOLD |  PRICE  | SALES |\n");
	printf("\t---------------------------------------------------------------------\n");
	
	for(i=0;i<count;i++){
		
		printf("\t%-10s       %-8d     %-5d      %-3d       %-6.2f    P%-5.2lf\n",menu[i].itemName,menu[i].itemID,menu[i].quantityLeft,menu[i].quantitySold, menu[i].price,menu[i].totalSales);
	}
	
	fclose(fptr);

}

int mngrChecker(int id){
	
	int i,n, num;
	num=readInventory();
	n=num;
	readInventory();
	for(i=0;i<num;i++){
		if(id == menu[i].itemID){//If Id matches 
			fclose(fptr);
			return 0;
			break;	
		}
		n--;
	}
	fclose(fptr);
	if(n==0)
		return 1;
}

int enterPassword(){
	
	FILE *Fpass;
	Fpass = fopen("passList.txt", "r");
	char password[20];
	char input[20];
	int i;
	while(!feof(Fpass)){
		fgets (password, 20, Fpass);
		password[strlen(password)] = 0;
	}
	
	printf("\n\t\t Enter Password: ");
	scanf("%s", &input);
	
	if ((strcasecmp(input, password)) == 0){
		
		printf("\n\t\t ACCESS GRANTED\n");
		clear();
		return passwordList();
		
	} else {
		
		for(i=0;i<6;i++){
			
			printf("\n\t\t Try again\n");
			getch();
			return enterPassword();
		}
			printf("\n\t\t INVALID PASSWORD.");
			return main();
	}
	
	
	fclose(Fpass);

}


int passwordList(){
	
	
	int choice;
	printf("\n\t\t   ***Password Settings***   ");
	printf("\n\t\t----------------------------");
	printf("\n\t\t [1] Change Password");
	printf("\n\t\t [2] Reset Password");
	printf("\n\t\t [3] Return");
	printf("\n\t\t----------------------------");
	printf("\n\n\t\t Your choice: ");
	scanf("%i", &choice);
	
	switch (choice){
		
		
		case 1: 
			changePassword();
			break; 
		
		case 2: 
			resetPassword();
			break;
		case 3:
			clear();
			managersAccess();
			break;
		default: 
			printf("\n\t\t Please try again");
			clear();
			main();
			break;
	}
	
}

int depositCash(){
	
	int choice;
	float cashOnSystem,deposit, withdraw, dummyVar=0; //included dummy var for updateCash *change;
	printf("\n\t\t   ***Cash on System***   ");
	printf("\n\t\t----------------------------");
	printf("\n\t\t [1] Check Cash");
	printf("\n\t\t [2] Deposit Cash");
	printf("\n\t\t [3] Withdraw Cash");
	printf("\n\t\t [4] Return");
	printf("\n\t\t----------------------------");
	printf("\n\n\t\t Your choice: ");
	scanf("%i", &choice);
	
	switch (choice){
		
		
		case 1: 
			checkCash(&cashOnSystem);
			printf("\n\n\t\t----------------------------");
			printf("\n\t\t CURRENT BALANCE: %0.2f ",cashOnSystem);
			printf("\n\t\t----------------------------");
			clear();
			managersAccess();
			break; 
		
		case 2: 
			checkCash(&cashOnSystem);
			printf("\n\n\t\t----------------------------");
			printf("\n\t\t CURRENT BALANCE: %0.2f ",cashOnSystem);
			printf("\n\t\t----------------------------");
			printf("\n\n\t\t----------------------------");
			printf("\n\t\t ENTER DEPOSIT: ");
			scanf("%f", &deposit);
			printf("\t\t----------------------------");
			updateCash(&cashOnSystem, &deposit,&dummyVar);
			checkCash(&cashOnSystem);
			printf("\n\n\t\t----------------------------");
			printf("\n\t\t CURRENT BALANCE: %0.2f ",cashOnSystem);
			printf("\n\t\t----------------------------");
			printf("\n\t\t Thank you for your deposit!");
			clear();
			managersAccess();
			break;
		case 3:
			checkCash(&cashOnSystem);
			printf("\n\n\t\t----------------------------");
			printf("\n\t\t CURRENT BALANCE: %0.2f ",cashOnSystem);
			printf("\n\t\t----------------------------");
			printf("\n\n\t\t----------------------------");
			printf("\n\t\t AMOUNT TO WITHDRAW: ");
			scanf("%f", &withdraw);
			printf("\t\t----------------------------");
			withdrawCash(&withdraw);
			checkCash(&cashOnSystem);
			printf("\n\n\t\t----------------------------");
			printf("\n\t\t CURRENT BALANCE: %0.2f ",cashOnSystem);
			printf("\n\t\t----------------------------");
			printf("\n\t\t Thank you for withdrawing!");
			clear();
			managersAccess();
			break;
		case 4:
			clear();
			managersAccess();
			break;
		default: 
			printf("\n\t\t Please try again");
			clear();
			main();
			break;
	}
	
	
}
