#include <stdio.h>
int main(void)
{
	//Variable Declarations
	int i_nrl;


	//Code 
	printf("\n\n");

	printf("Printing Digits 10 to 1 : \n\n");

	i_nrl = 10;
	while (i_nrl >= 1)
	{
		printf("\t%d\t\n", i_nrl);
		i_nrl--;
	}

	printf("\n\n");

	return(0);
}