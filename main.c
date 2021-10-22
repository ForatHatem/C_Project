#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "newCustomer.h"
#include "searchCustomer.h"
#include "custom_ref.h"

int displayMenu (void)
{
	int choice;
	char c;
	
	printf("Please choose the following choices\n");
	
	printf("1 - New customer\n");
	printf("2 - Search customer\n");
	printf("3 - Print all customers\n");
	printf("4 - Print all archieved customers\n");
	printf("5 - Exit\n");
	
	scanf("%d",&choice);
	printf("DEBUGGING ----------- choice = %d\n",choice);
	
	while((c = getchar ()) != '\n' && c != EOF);
	
	printf("DEBUGGING ------------ choice = %d\n",choice);
	
	return choice;
}

int main (void)
{
	int choice;
	struct details * firstStruct = NULL;
	
	choice = displayMenu ();
	
	while(choice != 5)
	{
		if(choice == 1)
		{
			firstStruct = newCustomer();
			//main();
			printf("Inside ch 1\n");
			choice = displayMenu ();
		}
		else if(choice == 2)
		{
			int N = 20;
			int errorFlag = 0;//no errors
			char mobileNum [N];
			char c;
			printf("Inside ch 2\n");
			do
			{
				printf("Please enter customer's mobile number:\n");
				fgets(mobileNum,N,stdin);//store string
				while( (c = fgetc(stdin)) != '\n' && c != EOF);//clear input buffer
				errorFlag = checkMobileNum(mobileNum);//check error flag
			}while(errorFlag);	
			
			searchCustomer(mobileNum,firstStruct);
			choice = displayMenu ();
			//main ();
		}
			//searchCustomer ();
		else if(choice == 3)
		{
			printf("Inside ch 3\n");
			choice = displayMenu ();
			//main();
		}
			//printCustomers ();
		else if(choice == 4)
		{
			printf("Inside ch 4\n");
			choice = displayMenu ();
			//main();
		}
			//printArchCustomers ();
		else
		{
			printf("inside ch > 5\n");
			choice = displayMenu ();
			//main ();
		}
	}
	
	freePtrs(firstStruct);
	

	return 0;
}
