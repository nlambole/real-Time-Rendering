#include <stdio.h>	
int main(void)
{
	//Variable Declarations
	int i_nrl;

	//code 
	printf("\n\n");

	printf("Printing Digits 10 to 1 : \n\n");

	i_nrl = 10;
	do
	{
		printf("\t %d \n", i_nrl);
		i_nrl--;
	} while (i_nrl >= 1);

	printf("\n\n");

	return(0);
}