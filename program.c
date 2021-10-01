#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SELECTIONS 2

/*
--main--
selectionPrompt ();

enterDetailsNewCustomer ();

printCustomers();

free();

--enterDetails--
enterMobileNum ();
enterPrice ();
createCustomerDetails(firstName,lastName,mobileNum,price);

*/


struct customerData
{
	char * firstName;
	char * lastName;
	char mobileNum [11];
	double price;
	struct customerData*next;
};

//--main--
int selectionPrompt (void);
struct customerData * enterDetailsNewCustomer (void);
void printCustomers (struct customerData*);
void freePtr(struct customerData *);
//--enterDetails
//void enterMobileNum (char*);
void enterMobileNum (char *);
double enterPrice (double);
struct customerData * createCustomer(char*,char*,char*,double);



int main (void)
{
	printf("DEBUGGING -- inside main\n");
	int selection = selectionPrompt ();
	struct customerData * newPt = NULL, *firstPt = NULL, *endPt = NULL;
	int firstFlag = 0;//first
	
	switch(selection)
	{
	case 1:
	newPt = enterDetailsNewCustomer ();//returns the address of a struct
	if(!firstFlag)
	{
		firstPt = newPt;
		firstFlag = 1;
	}
	break;
	//case 2:
	//searchCustomer ();
	//break;
	default:
	break;
	}

	printCustomers(firstPt);

	freePtr(firstPt);

	return 0;
}

struct customerData * enterDetailsNewCustomer (void)
{
	printf("DEBUGGING -- inside enterDetailsNewCustomer\n");
	char firstName [20];
	char lastName [20];
	char mobileNum[11];
	double price;
	
	printf("Please enter your name:\n");
	scanf("%s %s",firstName,lastName);
	printf("Enter your mobile number:\n");
	enterMobileNum(mobileNum);
	//strcpy(mobileNum,enterMobileNum(mobileNum));	
	printf("Enter price:\n");
	price = enterPrice (1.0);
	

	struct customerData * ptr;
	ptr = createCustomer(firstName,lastName,mobileNum,price);
	
	return ptr;
}

int selectionPrompt (void)
{
	printf("DEBUGGING -- inside selectionPrompt\n");
	printf("please select the following:\n");
	
	
	int option;
	char selection [][25] = 
	{
		"1 - New Customer",
		"2 - Existing Customer"
	};
	
	
	do
	{
		int i;
		for(i = 0; i < SELECTIONS; i++)
			printf("%s\n",selection[i]);
			
		scanf("%d",&option);
	
	}while(option <= 0 || option > SELECTIONS);

	return option;
	
}

//--I can't help myself because I married you


// [] [] [] [] [] [] [] [] [] [] [\0] arr index starts from 0 -> 10 hence 11 elements
//void enterMobileNum (char*mobileNum)
void enterMobileNum (char *mobileNum)
{
	printf("DEBUGGING -- inside enterMobileNum\n");
	char prompt [] = {"Please enter a valid mobile number:\n"};
	//char mobileNum [11];
	scanf("%s",mobileNum);
	
	int errorFlag = 0;//no errors
	int i = 0;
	int count = 0;
	
	do
	{
		if(errorFlag)
		{
			printf("%s",prompt);
			scanf("%s",mobileNum);
			errorFlag = 0;
		
		}
		
		//check if all numbers
		//for(i = 0; i < 10; i++)
		while(mobileNum[i] != '\0')
		{
			count++;
			//check if all digits are numbers
			if(mobileNum[i] >= '0' && mobileNum[i] <= '9') {}
			else
			{
				errorFlag = 1;
				break;
			}
			
			//check if there are 10 digits
			if(mobileNum[i] == '\0')
			{
				errorFlag = 1;
				break;
			}
			
			//check if the first 2 numbers are 04
			if(mobileNum[0] != '0' && mobileNum[1] != '4')
			{
				errorFlag = 1;
				break;
			}
			i++;
		}
		
		if(count < 10)
			errorFlag = 1;
	
	}while(errorFlag);
}

double enterPrice (double min)
{
	printf("DEBUGGING -- inside enterPrice\n");
	char prompt [] = {"Please enter a price higher than "};
	double price;
	
	do
	{	printf("%s %.2lf",prompt,min);
		scanf("%lf",&price);
	}while(price < min);	
		
	return price;
}

struct customerData * createCustomer (char*firstName,char*lastName,char*mobileNum,double price)
{
	printf("DEBUGGING -- inside createCustomer\n");
	struct customerData * ptr;
	ptr = (struct customerData *)malloc(sizeof(struct customerData));
	
	//strcpy(ptr->firstName,firstName);
	//strcpy(ptr->lastName, lastName);
	//strcpy(ptr->mobileNum, mobileNum);	
	//ptr->mobileNum = mobileNum;
	ptr->firstName = firstName;
	ptr->lastName = lastName;
	ptr->mobileNum = mobileNum;
	
	ptr->price = price;
	ptr->next = NULL;
	
	return ptr;
}

void printCustomers (struct customerData * firstPt)
{
	printf("DEBUGGING -- inside printCustomer\n");
	struct customerData * ptr = firstPt;
	
	while(ptr != NULL)
	{
		printf("Name: %s %s\n",ptr->firstName,ptr->lastName);
		printf("Mobile Number: %s\n",ptr->mobileNum);
		ptr++;
	}
}

void freePtr(struct customerData * firstPtr)
{
	printf("DEBUGGING -- inside freePtr\n");
	struct customerData * ptr = firstPtr;
	struct customerData * tmp;
	
	while(ptr != NULL)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}
