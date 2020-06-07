#include <stdio.h>

int main(void)
{
	//Variable Declarations
	int i_nrl, j_nrl;

	//code 
	printf("\n\n");
	for (i_nrl = 1; i_nrl <= 10; i_nrl++)
	{
		printf("i = %d\n", i_nrl);
		printf("--------------\n\n");

		for (j_nrl = 1; j_nrl <= 5; j_nrl++)
		{
			printf("\tj = %d \n", j_nrl);
		}
		printf("\n\n");

		return(0);
	}
}