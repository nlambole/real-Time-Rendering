#include <stdio.h>
int main(void)
{
	//Variable Declarartions
	int i_nrl, j_nrl, k_nrl;

	//code
	printf("\n\n");

	i_nrl = 1;
	do
	{
		printf("i_nrl = %d \n", i_nrl);
		printf("-----------\n\n");

		j_nrl = 1;
		do
		{
			printf("\t j= %d \n", j_nrl);
			printf("\t-------------\n\n");

			k_nrl = 1;
			do
			{
				printf("\t\tk=%d\n", k_nrl);
				k_nrl++;
			} while (k_nrl < 3);
			printf("\n\n");
			j_nrl++;
		} while (j_nrl <= 5);
		printf("\n\n");
		i_nrl++;
	} while (i_nrl <= 10);

	return(0);

}