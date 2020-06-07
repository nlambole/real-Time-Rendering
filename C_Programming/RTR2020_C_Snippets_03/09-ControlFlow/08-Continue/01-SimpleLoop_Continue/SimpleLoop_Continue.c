#include <stdio.h>
int main(void)
{
	//Variable Declarartions
	int i_nrl;

	//code
	printf("\n\n");

	printf("Printing Even Numbers From 0 to 100: \n\n ");

	for (i_nrl = 0; i_nrl <= 100; i_nrl++)
	{
		//condition for a umber to be even number => division of number of number by 2 leaves no remainder (remainder = 0)
		//if remainder is not 0, the number is odd number...
		if (i_nrl % 2 != 0)
		{
			continue;
		}
		else
		{
			printf("\t%d\n", i_nrl);
		}
	}
	printf("\n\n");

	return(0);
}