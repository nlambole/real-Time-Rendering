#include <stdio.h>

int main(void)
{
	//Varaible Declaration

	int i_nrl, j_nrl, k_nrl;

	//code 
	printf("\n\n");

	i_nrl = 1;
	while (i_nrl <= 10)
	{
		printf("i = %d \n", i_nrl);
		printf("----------\n\n");

		j_nrl = 1;
		while (j_nrl <= 5)
		{
			printf("\t j = %d \n", j_nrl);
			printf("--------\n\n");
			
			k_nrl = 1;
			while (k_nrl <= 3)
			{
				printf("\n\n");
				k_nrl++;
			}
			printf("\n\n");
			j_nrl++;
		}
		printf("\n\n");
		i_nrl++;
	}
	return(0);
}