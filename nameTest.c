#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customers.h"//printcustomer createcustomer freeCustomer
#include "somefunctions.h"
#include "structure.h"

/*extern struct details
{
	char firstName [20];
	char lastName [20];
	char mobileNum [20];
	double price;
};*/

/*
- New Customer
- Search customers
- Print all customers
*/

int main (void)
{
    int i = 5;
	char firstName [20];
	char lastName [20];
	char mobileNum [20];
	double price;
	struct details * ptr;
	struct details * newPt = NULL, *endPt = NULL;
	char choice; //Y/N

	int forat;

	do
	{
		enterName(firstName,lastName);
		enterMobileNum(mobileNum);
		price = enterPrice(1.00);

		ptr = createCustomer (firstName,lastName, mobileNum, price);

		if(newPt == NULL)
		{
			newPt = ptr;
			endPt = newPt;
		}
		else
		{
			endPt = connectStructs(ptr,endPt);
		}

		choice = enterChoice ();

	}while(choice == 'Y' || choice == 'y');

	printCustomers (newPt);

	freePtrs (newPt);

	return 0;
}

//[endPt] [ptr]

