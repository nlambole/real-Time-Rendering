#include <stdio.h>

int main(void)
{
	//Variable Declartions
	int i_nrl;

	//code
	printf("\n\n");

	printf("Printing Digits 1 to 10 : \n\n");

	i_nrl = 1;
	do
	{
		printf("\t %d \n", i_nrl);
		i_nrl++;
	} while (i_nrl <= 10);
	printf("\n\n");

	return(0);
}