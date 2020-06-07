#include <stdio.h>
int main(void)
{
	//Variable Declarations
	int i_nrl, j_nrl, c_nrl;

	//code 
	printf("\n\n");

	i_nrl = 0;
	while (i_nrl < 64)
	{
		j_nrl = 0;
		while (j_nrl < 64)
		{
			c_nrl = ((i_nrl & 0x8) == 0) ^ ((j_nrl & 0x8) == 0);
			if (c_nrl == 0)
				printf("    ");

			if (c_nrl == 1)
				printf("*    ");

			j_nrl++;
		}
		printf("\n\n");
		i_nrl++;
	}
	return(0);
}