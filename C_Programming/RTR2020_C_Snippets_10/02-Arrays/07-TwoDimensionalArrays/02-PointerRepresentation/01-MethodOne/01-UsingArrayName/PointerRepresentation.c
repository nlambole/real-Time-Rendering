#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	//Variable Declarations
	int iArray_nrl[NUM_ROWS][NUM_COLUMNS];
	int i_nrl, j_nrl;

	//Code
	// *** Every Row Of A 2D Array Is An Integer Array Itself Comprising Of 'NUM_COLUMNS' Integer Elements ***
	// *** There Are 5 Rows And 3 Columns In A 2D Integer Array . Each Of The ROws Is A 1D Array Of 2 Inteeger.
	// *** Hence, Each Of These 5 Rows Themselves Being Arrays, Will Be The Base Address Of Their Respective Rows ***

	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
		{
			*(iArray_nrl[i_nrl] + j_nrl) = (i_nrl + 1) * (j_nrl + 1); // 'iArray[i] Can Be Treated As 1D Array Using Pointers..
			
		}
		
	}
	printf("\n\n 2D Integer Array Elements Along With Addresses : \n\n");
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++ )
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
		{
			printf("*(iArray[%d] + %d) = %d \t\t At Address (iArray[i_nrl] + j) : %p\n", i_nrl, j_nrl, *(iArray_nrl[i_nrl] + j_nrl), (iArray_nrl[i_nrl] + j_nrl));

		}
		printf("\n\n");
	}
	return(0);
}