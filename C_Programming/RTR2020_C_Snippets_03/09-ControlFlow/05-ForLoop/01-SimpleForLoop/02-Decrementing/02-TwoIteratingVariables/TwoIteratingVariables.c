#include <stdio.h>
int main(void)
{
	//Variable Declarations
	int i_nrl, j_nrl;

	//
	printf("\n\n");

	printf("Printing Digits 10 to 1 and 100 to 10 : \n\n");

	for (i_nrl = 10, j_nrl = 100; i_nrl >= 1, j_nrl >= 10; i_nrl--, j_nrl--)
	{
		printf("\t %d \t %d \n", i_nrl, j_nrl);
	}

	printf("\n\n");

	return(0);
}