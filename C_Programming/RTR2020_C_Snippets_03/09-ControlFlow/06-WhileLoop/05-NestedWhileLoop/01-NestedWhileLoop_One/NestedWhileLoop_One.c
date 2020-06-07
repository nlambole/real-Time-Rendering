#include <stdio.h>
int main(void)
{
	// Variale Declaration 
	int i_nrl, j_nrl;

	//code 
	printf("\n\n");

	i_nrl = 1;
	while(i_nrl <= 10)
	{
		printf("i= %d \n", i_nrl);
		printf("-------------\n\n");

		j_nrl = 1;
		while (j_nrl <= 5)
		{
			printf("\t j = %d\n", j_nrl);
			j_nrl++;
		}
		i_nrl++;
		printf("\n\n");

	}
	return(0);
}