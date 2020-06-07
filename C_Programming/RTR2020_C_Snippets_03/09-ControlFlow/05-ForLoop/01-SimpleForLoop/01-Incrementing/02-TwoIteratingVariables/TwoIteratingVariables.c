#include <stdio.h>

int main(void)
{
	//Variable Decalrations
	int i_nrl, j_nrl;

	//code 
	printf("\n\n");

	printf("Printing Digits 1 to 10 to 100 : \n\n");

	for (i_nrl = 1, j_nrl = 10; i_nrl <= 10, j_nrl <= 100; i_nrl++, j_nrl = j_nrl + 10)
	{
		printf("\t %d \t %d \n", i_nrl, j_nrl);
	}
	printf("\n\n");

	return(0);
}