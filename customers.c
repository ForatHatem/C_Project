#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"


/*struct details
{
	char firstName [20];
	char lastName [20];
	char mobileNum [20];
	double price;
};*/

struct details * createCustomer (char * firstName, char * lastName, char * mobileNum, double price)
{
	struct details * ptr = (struct details *)malloc(sizeof(struct details));

	strcpy(ptr->firstName,firstName);
	strcpy(ptr->lastName,lastName);
	strcpy(ptr->mobileNum,mobileNum);
	ptr->price = price;
	ptr->next = NULL;

	return ptr;
}

void printCustomers (struct details * ptr)
{
    int customerNum = 1;
    while(ptr != NULL)
    {
        printf("------------CUSTOMER %d-------------\n",customerNum);
        printf("Name: %s %s\n",ptr->firstName,ptr->lastName);
        printf("Mobile num: %s\n",ptr->mobileNum);
        printf("Price: %.2lf\n", ptr->price);
        printf("---------------------------------------\n");
        ptr = ptr->next;
        customerNum++;
    }

}

void freePtrs (struct details * ptr)
{
    while(ptr != NULL)
    {
        free(ptr);
        ptr = ptr->next;
    }
}

struct details * connectStructs (struct details * ptr, struct details * endPt)
{
	struct details * tmp = endPt;
	endPt = ptr;
	tmp->next = endPt;

	return endPt;
}
