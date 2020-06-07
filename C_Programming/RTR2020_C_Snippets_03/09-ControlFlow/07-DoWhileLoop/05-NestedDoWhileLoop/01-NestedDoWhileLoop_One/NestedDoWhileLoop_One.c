#include <stdio.h>
int main(void)
{
	//Variable Declarations
	int i_nrl, j_nrl;

	//Code
	printf("\n\n");

	i_nrl = 1;
	do
	{
		printf("i = %d\n", i_nrl);
		printf("------------\n\n");

		j_nrl = 1;
		do
		{
			printf("\t j= %d\n", j_nrl);
			j_nrl++;

		} while (j_nrl <= 5);
		i_nrl++;
		printf("\n\n");
	} while (i_nrl <= 10);
	return(0);
}