#include <stdio.h>
int main(void)
{
	// Variable Declarations
	int iArray_nrl[3][5]; // 3 ROWS (0, 1, 2) AND 5 COLUMNS (0, 1, 2, 3, 4)
	int int_size_nrl;
	int iArray_size_nrl;
	int iArray_num_elements_nrl, iArray_num_rows_nrl, iArray_num_columns_nrl;
	int i_nrl, j_nrl;

	// CODE
	printf("\n\n");
	int_size_nrl = sizeof(int);

	iArray_size_nrl = sizeof(iArray_nrl);
	printf("Size Of Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_size_nrl);

	iArray_num_rows_nrl = iArray_size_nrl / sizeof(iArray_nrl[0]);
	printf("Number of Rows In Two Dimensional ( 2D) Integer Array Is = %d\n\n", iArray_num_rows_nrl);

	iArray_num_columns_nrl = sizeof(iArray_nrl[0]) / int_size_nrl;
	printf("Number of Columns In Two Dimensional 9 2D0 Integer Array Is = %d\n\n", iArray_num_columns_nrl);

	iArray_num_elements_nrl = iArray_num_rows_nrl * iArray_num_columns_nrl;
	printf("Number Of Elements In Two Dimensional (2D ) Integer Array Is = %d \n\n", iArray_num_elements_nrl);

	printf("\n\n Elements In The 2D Array : \n\n	");

	// ***** Piece-Meal Assignment *****
	// **** ROW 1 ***
	iArray_nrl[0][0] = 21;
	iArray_nrl[0][1] = 42;
	iArray_nrl[0][2] = 63;
	iArray_nrl[0][3] = 84;
	iArray_nrl[0][4] = 105;

	// **** ROW 2 ****
	iArray_nrl[1][0] = 22;
	iArray_nrl[1][1] = 44;
	iArray_nrl[1][2] = 66;
	iArray_nrl[1][3] = 88;
	iArray_nrl[1][4] = 110;
	// ****** ROW 3 ******
	iArray_nrl[2][0] = 23;
	iArray_nrl[2][1] = 46;
	iArray_nrl[2][2] = 69;
	iArray_nrl[2][3] = 92;
	iArray_nrl[2][4] = 115;

	//*** DISPLAY ***

	for (i_nrl = 0; i_nrl < iArray_num_rows_nrl; i_nrl++)
	{
		printf("******* ROW %d ******\n", (i_nrl + 1));
		for (j_nrl = 0; j_nrl < iArray_num_columns_nrl; j_nrl++)
		{
			printf("iArray[%d][%d] = %d \n", i_nrl, j_nrl, iArray_nrl[i_nrl][j_nrl]);
		}
		printf("\n\n");
	}

	return(0);
}
