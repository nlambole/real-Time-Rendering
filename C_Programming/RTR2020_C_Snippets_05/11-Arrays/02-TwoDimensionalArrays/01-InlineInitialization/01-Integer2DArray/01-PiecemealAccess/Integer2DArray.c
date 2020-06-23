#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int iArray_nrl[5][3] = { {1, 2, 3,}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15} }; //In-Line Initialization

	int int_size_nrl;
	int iArray_size_nrl;
	int iArray_num_elements, iArray_num_rows, iArray_num_columns;

	// Code 
	printf("\n\n");

	int_size_nrl = sizeof(int);

	iArray_size_nrl = sizeof(iArray_nrl);
	printf("Size Of Two Dimentional (2D) Integer Array Is = %d\n\n", iArray_size_nrl);

	iArray_num_rows = iArray_size_nrl / sizeof(iArray_nrl[0]);
	printf("Number Of Rows In Two Dimentional (2D) Integer Array Is = %d\n\n", iArray_num_rows);

	iArray_num_elements = sizeof(iArray_nrl[0]) / int_size_nrl;
	printf("Number Of Columns In Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_num_columns);

	iArray_num_elements = iArray_num_rows * iArray_num_columns;
	printf("Number of Elements In Two Dimensional (2D) Integer Array Is = %d\n\n", iArray_num_elements);

	printf("\n\n");
	printf("Elements In The 2D Array : \n\n");

	// *** Array Indices Begins From 0, Hence, 1st Row Is Actually, 0th Row And 1st Column Is Actually 0th Column ***

	// *** ROW 1 ***

	printf("***** ROW 1 *****");
	printf("\niArray[0][0] = %d\n", iArray_nrl[0][0]); // *** COLUMN 1 *** (0th Elements) => 1
	printf("iArray[0][1] = %d\n", iArray_nrl[0][1]); // *** COLUMN 2 *** (1st Elements) => 2
	printf("iArray[0][2] = %d \n", iArray_nrl[0][2]); // *** COLUMN 3 *** (2nd Elements) => 3
	
	printf("\n\n");

	// *** ROW 2 ***
	printf("***** ROW 2 *****");
	printf("\niArray[1][0] = %d\n", iArray_nrl[1][0]); // *** COLUMN 1 *** (0th Elements) => 2
	printf("iArray[1][1] = %d\n", iArray_nrl[1][1]); // *** COLUMN 2 *** (1st Elements) => 4
	printf("iArray[1][2] = %d\n", iArray_nrl[1][2]); // *** COLUMN 3 *** (2nd Element) = > 6

	printf("\n\n");

	// *** ROW 3 ****
	printf("***** ROW 3 *****");
	printf("\niArray[2][0] = %d\n", iArray_nrl[2][0]); // *** COLUMN 1 *** (0th Elements) => 3
	printf("iArray[2][1] = %d\n", iArray_nrl[2][1]); // *** COLUMN 2 *** (1st Elements) => 6
	printf("iArray[2][2] = %d\n", iArray_nrl[2][2]); // *** COLUMN 3 *** (2nd Element) = > 9

	// *** ROW 4 ***
	printf("***** ROW 4 *****");
	printf("\niArray[3][0] = %d\n", iArray_nrl[3][0]); // *** COLUMN 1 *** (0th Elements) => 4
	printf("iArray[3][1] = %d\n", iArray_nrl[3][1]); // *** COLUMN 2 *** (1st Elements) => 8
	printf("iArray[3][2] = %d\n", iArray_nrl[3][2]); // *** COLUMN 3 *** (2nd Element) = > 12

	printf("\n\n");

	// *** ROW 5 ***
	printf("***** ROW 4 *****");
	printf("\niArray[4][0] = %d\n", iArray_nrl[4][0]); // *** COLUMN 1 *** (0th Elements) => 5
	printf("iArray[4][1] = %d\n", iArray_nrl[4][1]); // *** COLUMN 2 *** (1st Elements) => 10
	printf("iArray[4][2] = %d\n", iArray_nrl[4][2]); // *** COLUMN 3 *** (2nd Element) = > 15

	printf("\n\n");

	return(0);

}