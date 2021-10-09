#include <stdio.h>
#include "newCustomer.h"
#include "custom_ref.h"
#include "structure.h"


struct details * newCustomer (void)
{
	char firstName [20];
	char lastName [20];
	char mobileNum [20];
	double price = 0.00;
	struct details * ptr = NULL, *newPt = NULL, *endPt = NULL;
	
	enterName (firstName,lastName);
	enterMobileNum(mobileNum);
	price = enterPrice (1.00);
	
	ptr = createCustomer (firstName,lastName,mobileNum,price);
	
	if(newPt == NULL)
	{
		newPt = ptr;
		endPt = newPt;
	}
	else
	{
		endPt = connectStructs (ptr,endPt);
	}
	
	return newPt;
}



