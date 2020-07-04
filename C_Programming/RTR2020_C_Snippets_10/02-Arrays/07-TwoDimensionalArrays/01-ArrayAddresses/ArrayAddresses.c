#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	//Variabale Declarations
	int iArray_nrl[NUM_ROWS][NUM_COLUMNS];
	int i_nrl, j_nrl;

	//code
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
			iArray_nrl[i_nrl][j_nrl] = (i_nrl + 1) * (j_nrl + 1);

	}
	
	printf("\n\n 2D Integer Array Elements Along With Addrss : \n\n");
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
		{
			printf("iArray[%d][%d] = %d \t\t At Address : %p\n", i_nrl, j_nrl, iArray_nrl[i_nrl][j_nrl], &iArray_nrl[i_nrl][j_nrl]);
		}
		printf("\n\n");
	}
	return(0);
}