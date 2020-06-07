#include <stdio.h>

int main(void)
{
	//Variable Declarations
	int i_nrl, j_nrl, c_nrl;

	//code
	printf("\n\n");
	for (i_nrl = 0; i_nrl < 64; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < 64; j_nrl++)
		{
			c_nrl = ((i_nrl & 0x8) == 0) ^ ((j_nrl & 0x8) == 0);

			if (c_nrl == 0)
				printf("   ");

			if (c_nrl == 1)
				printf("*  ");
		}
		printf("\n\n");
	}
	return(0);
}