#include <stdio.h>

int main(void)
{
	//Variable Declarations
	int i_nrl, j_nrl;

	//code 
	printf("\n\n");

	printf("Printing Digits 10 to 1 and 100 to 10 : \n\n");

	i_nrl = 10;
	j_nrl = 100;
	while (i_nrl >= 1, j_nrl >= 10)
	{
		printf("\t%d\t %d \n", i_nrl, j_nrl);
		i_nrl--;
		j_nrl = j_nrl - 10;
	}
	printf("\n\n");

	return(0);
}