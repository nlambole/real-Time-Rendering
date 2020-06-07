#include <stdio.h>

int main(void)
{
	//Variable Declarations
	int i_nrl, j_nrl;

	//code
	printf("\n\n");

	printf("Print Digit 1 to 10 and 10 to 100 : \n\n");

	i_nrl = 1;
	j_nrl = 2;

	do
	{
		printf("\t %d \t %d \n", i_nrl, j_nrl);
		i_nrl++;

		j_nrl = j_nrl + 10;
	} while (i_nrl <= 10, j_nrl <= 100);

	printf("\n\n");

	return(0);
}