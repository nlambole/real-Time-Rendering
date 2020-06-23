#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int iArray_nrl[5][3] = {{ 1, 2, 3 }, { 2, 4, 6 }, { 3, 6, 9 }, { 4, 8, 12 }, { 5, 10, 15 }}; //IN-LINE INITIALIZATION
	int int_size_nrl;
	int iArray_size_nrl;
	int iArray_num_elements_nrl, iArray_num_rows_nrl, iArray_num_columns_nrl;
	int i_nrl, j_nrl;

	// Code
	printf("\n\n");

	int_size_nrl = sizeof(int);

	iArray_size_nrl = sizeof(iArray_nrl);
	printf("Size Of Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_size_nrl);

	iArray_num_rows_nrl = iArray_size_nrl / sizeof(iArray_nrl[0]);
	printf("Number Of Rows In Two Deimensional (2D) Integer Array Is = %d\n\n", iArray_num_rows_nrl);

	iArray_num_columns_nrl = sizeof(iArray_nrl[0]) / int_size_nrl;
	printf("Number Of Columns In Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_num_columns_nrl);

	iArray_num_elements_nrl = iArray_num_rows_nrl * iArray_num_columns_nrl;
	printf("Number Of Elements In Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_num_elements_nrl);

	printf("\n\n Elements In The 2D Array : \n\n");

	// *** Array Indices Begin From 0, Hence, 1st Row Is Actually 0th Row And 1st Column Is Actually 0th Column ***

	for (i_nrl = 0; i_nrl < iArray_num_rows_nrl; i_nrl++)
	{
		printf("******* Row %d *******", (i_nrl + 1));
		for (j_nrl = 0; j_nrl < iArray_num_columns_nrl; j_nrl++)
		{
			printf("\niArray[%d][%d] = %d\n", i_nrl, j_nrl, iArray_nrl[i_nrl][i_nrl]);
		}

		printf("\n\n");

	}
	return(0);
	
}
