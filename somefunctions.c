#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "somefunctions.h"
#include "structure.h"


/*struct details
{
	char firstName [20];
	char lastName [20];
	char mobileNum [20];
	double price;
};*/

void enterMobileNum (char*mobileNum)
{
	int i = 0;
	int count = 0;
	int errorFlag = 0; //no errors
	size_t ln = 0;

	do
	{
		if(errorFlag)
		{
			printf("Enter a valid mobile number:\n");
			errorFlag = 0;
		}
		else
			printf("Enter your mobile number: \n");

		//scanf("%s", mobileNum);
		//fflush(stdin);

		//fgets(mobileNum,11,stdin);
		fgets(mobileNum,20,stdin);
		ln = strlen(mobileNum) - 1;
		if(mobileNum[(int)ln] == '\n')
            mobileNum[(int)ln] = '\0';
			//mobileNum[(int)ln] = '\n';

		//fgets(mobileNum,11,stdin);
		//[0][1][2][3][4][5][6][7][8][9][10] 11 elements
		while(mobileNum[i] != '\0')
		{
			//check if all digits
			if(mobileNum[i] >= '0' && mobileNum[i] <= '9'){}
			else
			{
				errorFlag = 1;
				break;
			}
			//check if it starts with 04
			if(mobileNum[0] != '0' && mobileNum[1] != '4')
			{
				errorFlag = 1;
				break;
			}

			i++;
			count++;
		}

		if(count != 10)//10 digits
		{
			errorFlag = 1;
			count = 0;
			i =0;
		}


	}while(errorFlag);
}

double enterPrice (double min)
{
	double price;
	char sPrice [20];
	char * end;
	size_t ln = 0;

	do
	{
		printf("Enter your price: ");
		fgets(sPrice,20,stdin);
		ln = strlen(sPrice) - 1;
		if(sPrice[(int)ln] == '\n')
			sPrice[(int)ln] = '\0';
		//convert to double
		price = strtod(sPrice,&end);
	}while(price < min);


	return price;
}

void enterName (char*firstName,char*lastName)
{
	int errorFlag = 0;
	size_t ln = 0;
	do{
		if(errorFlag)
		{
			printf("Please enter a valid name:\n");
			errorFlag = 0;
		}
		else
            	printf("Enter your name:\n");

            	printf("First name: ");
            	fgets(firstName,20,stdin);

            	ln = strlen(firstName) - 1;
            	if(firstName[(int)ln] == '\n')
            		firstName[(int)ln] = '\0';

            	printf("\nLast name: ");
            	fgets(lastName,20,stdin);
            	ln = strlen(lastName) - 1;
            	if(lastName[(int)ln] == '\n')
            		lastName[(int)ln] = '\0';

            	printf("\n");

		//scanf("%s %s",firstName,lastName);
		//fflush(stdin);

		if(!checkName(firstName))//no errors 0
		{
			if(!checkName(lastName))//no errors 0
				errorFlag = 0;
			else
				errorFlag = 1;
		}
		else
			errorFlag = 1;

	}while(errorFlag);
}

int checkName (char*name)
{
	int i = 0;
	int errorFlag = 0;//no error
	while(name[i] != '\0')
	{
		if(name[i] >= '0' && name[i] <= '9')
			errorFlag = 1;
		i++;
	}

	return errorFlag;
}

char enterChoice(void)
{
	char ch;
	int errorFlag = 0;//no error by default

	do
	{
		if(errorFlag)
		{
			printf("Please enter a vaild choice\n\n");
			errorFlag = 0;
		}

		printf("Do you want to add another customer? Y/N\n");
		//scanf("%c",&ch);
		//fflush(stdin);

		ch = (char) fgetc(stdin);

		while(getchar() != '\n' && getchar() != EOF);

		printf("DEBUGGING:  ch = %c\n\n",ch);

		if((ch != 'Y' && ch != 'y') && (ch != 'N' && ch != 'n'))
			errorFlag = 1;


	}while(errorFlag);


	return ch;
}
