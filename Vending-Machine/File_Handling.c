#include "File_Handling.h"
#include "Vending.h"


int readInventory(){
	
	int n = 0;
	int i;
	fptr= fopen("Inventory.txt","r");
	if(fptr==NULL)
		return -1;
	fscanf(fptr,"%d\n",&n);
	for(i=0;i<n;++i){
		
		fscanf(fptr,"%d\n",&menu[i].itemID);
		fgets(menu[i].itemName,150,fptr);
		menu[i].itemName[strlen(menu[i].itemName)-1]=0;
		fscanf(fptr,"%d\n",&menu[i].quantityLeft);
		fscanf(fptr,"%d\n",&menu[i].quantitySold);
		fscanf(fptr,"%f\n",&menu[i].price);
		fscanf(fptr,"%f\n",&menu[i].totalSales);
	}
	
	fclose(fptr);
    return n;
	
	
}

int IDchecker(int **id){
	
	int i,n, num;
	num=readInventory();
	n=num;
	readInventory();
	for(i=0;i<num;i++){
		if(**id == menu[i].itemID){//If Id matches 
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


int findID(int id){
	
	int i,n=0, num;
	num=readInventory();
	readInventory();
	for(i=0;i<num;i++){
		
		if(id!=menu[i].itemID){
			n++;
		}
		else
			return n;	
	}
	fclose(fptr);
	
	}


void clear(){
	printf("\n\t\t Press Any Key To Continue: ");
	getch();
	system("cls");
}

void updateInventory(float *change, float *totalDeposit, int **amountToBuy, int ***choice_ptr){
	
	int i, count;
	float sale;
	sale = *totalDeposit - *change;
	
	count=readInventory();
	readInventory();
	
	for(i=0;i<count;i++){
		
		if(***choice_ptr==menu[i].itemID){
			
			menu[i].quantityLeft=menu[i].quantityLeft-**amountToBuy;
			menu[i].quantitySold=menu[i].quantitySold+**amountToBuy;
			menu[i].totalSales=menu[i].totalSales+sale;
		
		}
	}
	writeToFile(count);
	fclose(fptr);
}

int writeToFile(int count){
	
	int i;
	fptr= fopen("Inventory.txt","w");
		if(fptr==NULL){
			printf("\t\t FILE DOES NOT EXIST");
		}
	fprintf(fptr, "%d\n", count);//print in the file the initial count of items

	for (i = 0; i < count; ++i) // writing all the details from all the function to the text file.
    {
        fprintf(fptr, "%d\n", menu[i].itemID);
        fputs(menu[i].itemName, fptr);
        fprintf(fptr, "\n");
        fprintf(fptr, "%d\n", menu[i].quantityLeft);
        fprintf(fptr, "%d\n", menu[i].quantitySold);
        fprintf(fptr, "%f\n", menu[i].price);
        fprintf(fptr, "%f\n", menu[i].totalSales);
    }
	
	fclose(fptr);

	return 0;
}

int resetPassword(){
	
	FILE *Fpass;
	Fpass = fopen("passList.txt", "w"); 
	fprintf(Fpass, "password");
	fclose(Fpass);
	printf("\n\t\t Password Resetted to: password\n");
	clear();
	main();
	
	
}

int changePassword(){
	
	char change[20], input[20], password[20];
	FILE *Fpass;
	Fpass = fopen("passList.txt", "r"); 
	while(!feof(Fpass)){
		fgets (password, 20, Fpass);
		password[strlen(password)] = 0;
	}
	Fpass = fopen("passList.txt", "w"); 
	printf("\n\t\t Enter Current Password: ");
	scanf("%s", &input);
	if ((strcasecmp(input, password)) == 0){
		
		printf("\n\t\t Enter new password: ");
		scanf("%s", change);
		fputs(change, Fpass);
		fclose(Fpass);
		printf("\n\t\t Password Changed...");
		clear();
		managersAccess();
		
	}
	else{
		
		fputs(password, Fpass);
		fclose(Fpass);
		printf("\n\t\t Password Invalid. Returning to Main Menu...");
		clear();
		return main();
		
	}

	
}



