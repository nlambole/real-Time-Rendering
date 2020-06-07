#include <stdio.h>
int main(void)
{
	//Varaible Declarartions
	int i_nrl, j_nrl, c_nrl;

	//code 
	printf("\n\n");

	i_nrl = 0;
	do
	{
		j_nrl = 0;
		do
		{
			c_nrl = ((i_nrl & 0x8) == 0) ^ ((j_nrl & 0x8) == 0);

			if (c_nrl == 0)
				printf("	");

			if (c_nrl == 1)
				printf("*   ");
			
			j_nrl++;
		} while (j_nrl < 64);
		printf("\n\n");
		i_nrl++;
	} while (i_nrl < 64);
	return(0);
}