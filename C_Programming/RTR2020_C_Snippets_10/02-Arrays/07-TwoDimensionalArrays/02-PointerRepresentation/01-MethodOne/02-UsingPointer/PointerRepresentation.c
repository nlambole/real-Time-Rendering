#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	//Variable Declarations
	int iArray_nrl[NUM_ROWS][NUM_COLUMNS];
	int i_nrl, j_nrl;

	int* ptr_iArray_row_nrl = NULL;

	//Code
	// *** Every Row of A 2D Array Is An Iteger Array Itself Conprising Of 'NUM_COLUMNS' Integer Elements..
	// *** There Are 5 Row And 3 Columns In A 2D Integer Array. Each Of The 
	// ** Hence, Each of Thes 5 Row Themselves being arrays, will be the BASE address  of their Respective Rows

	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		ptr_iArray_row_nrl = iArray_nrl[i_nrl]; // 'iArray[i]' IS THE BASE ADDRESS OF ith ROW ...
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
			*(ptr_iArray_row_nrl + j_nrl) = (i_nrl + 1) * (j_nrl + 1); // 'ptr_iArray_Row' (That is, 'iArray[i]' Can Be Treated As 1D Array	Using Pointers) ...
		
	}

	printf("\n\n 2D Integer Array Elements Along With Addresses : \n\n");


	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		ptr_iArray_row_nrl = iArray_nrl[i_nrl];
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
		{
			printf("*(ptr_iArray_Row + %d) = %d \t\t At Address (pre_iArray_Row + j) : %p\n", j_nrl, *(ptr_iArray_row_nrl + j_nrl), (ptr_iArray_row_nrl + j_nrl));

		}
		printf("\n\n");

	}
	return(0);
}