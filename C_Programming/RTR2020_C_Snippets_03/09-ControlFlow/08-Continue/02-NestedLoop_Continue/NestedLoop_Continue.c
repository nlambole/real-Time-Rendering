#include <stdio.h>
int main(void)
{
	//Variable Declarartions
	int i_nrl, j_nrl;

	//code
	printf("\n\n");

	printf("Puter Loop Prints Odd Numbers Between 1 and 10. \n\n");
	printf("Inner Loop Prints Even Numbers Between 1 and 10 For Every Odd Number Printed By Outer Loop..\n\n");

	//Condition for a number to be even number => division of number by 2 leaves no remainder (remiander = 0)
	//condition for a number to be odd number => division of number by 2 leaves remainder (remainder = (usually)


	for (i_nrl = 1; i_nrl <= 10; i_nrl++)
	{
		if (i_nrl % 2 != 0) //If Number (j) Is Odd...
		{	
			printf("i = %d\n", i_nrl);
			printf("-------\n\n");
			for (j_nrl = 1; j_nrl <= 10; j_nrl++)
			{
				if (j_nrl % 2 == 0) //If Number (j) Is Even...
				{
					printf("\tj_nrl=%d\n", j_nrl);
				}
				else //If Number (j) Is Odd...
				{
					continue;
				}
			}
			printf("\n\n");
		}
		else  //If Number (i) Is Odd..
		{
			continue;
		}

	}
	printf("\n\n");
	return(0);


}
