#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "newCustomer.h"
#include "custom_ref.h"


int main (void)
{
	int choice;
	char c;
	struct details * firstStruct = NULL;
	printf("Please choose the following choices\n");
	
	printf("1 - New customer\n");
	printf("2 - Search customer\n");
	printf("3 - Print all customers\n");
	printf("4 - Print all archieved customers\n");
	printf("5 - Exit\n");
	
	scanf("%d",&choice);
	printf("DEBUGGING ----------- choice = %d\n",choice);
	
	
	//store something in choice
	while((c = getchar ()) != '\n' && c != EOF);
	
	printf("DEBUGGING ------------ choice = %d\n",choice);
	
	while(choice != 5)
	{
		if(choice == 1)
		{
			firstStruct = newCustomer();
			main();
		}
		else if(choice == 2)
		{
			main ();
		}
			//searchCustomer ();
		else if(choice == 3)
		{
			main();
		}
			//printCustomers ();
		else if(choice == 4)
		{
			main();
		}
			//printArchCustomers ();
		else
		{
			main ();
		}
	}
	
	freePtrs(firstStruct);

	return 0;
}
