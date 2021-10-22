#include <stdio.h>
#include <string.h>
#include "structure.h"
#include "searchCustomer.h"
#include "custom_ref.h"

#define FOUND 		0
#define NOTFOUND	1

//compare mobile number to ptr->mobileNum
//if equal, print customer, break
//if not, ptr++, 
//if we reach the end print customer not found


void searchCustomer (char * mobileNum, struct details * firstStruct)
{
	struct details * ptr = firstStruct;
	int index = 0, found = NOTFOUND;//
	
	while(ptr != NULL)
	{
		found = strcmp(mobileNum,ptr->mobileNum);//return 0
		
		if(found == FOUND)
		{
			printCustomer(ptr);
			break;
		}
		else
			ptr++;
	}

	if(found == NOTFOUND)//not found customer
		printf("Customer doesn't exist\n");

}

void printCustomer (struct details * ptr)
{
	printf("%s %s\n",ptr->firstName,ptr->lastName);
	printf("%s\n",ptr->mobileNum);
	printf("%.2lf\n",ptr->price);
}
