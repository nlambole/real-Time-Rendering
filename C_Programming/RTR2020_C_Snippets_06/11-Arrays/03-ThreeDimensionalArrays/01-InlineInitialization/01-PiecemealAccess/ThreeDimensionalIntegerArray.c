#include <stdio.h>	

int main(void)
{
	// Variable Declarations

	// In-Line Initializataion
	int iArray_nrl[5][3][2] = { { { 9, 18 }, { 27, 36 }, { 45, 54 } }, { { 8, 16 }, { 24, 32 }, { 40, 48 } }, { { 7, 14 }, { 21, 28 }, { 35, 42 } }, { { 6, 12 }, { 18, 24 }, { 30, 36 } }, { { 5, 10 }, { 15, 20 }, { 25, 30 } } };
	int int_size_nrl;
	int iArray_size_nrl;
	int iArray_num_elements_nrl, iArray_width_nrl, iArray_height_nrl, iArray_depth_nrl;

	//Code
	printf("\n\n ");

	int_size_nrl = sizeof(int);

	iArray_size_nrl = sizeof(iArray_nrl);
	printf("Size Of Three Dimensional ( 3D ) Integer Array Is = %d\n\n", iArray_size_nrl);

	iArray_width_nrl = iArray_size_nrl / sizeof(iArray_nrl[0]);
	printf("Number of Rows (Width) In Three Dimensional ( 3D ) Integer Array Is = %d \n\n", iArray_width_nrl);

	iArray_height_nrl = sizeof(iArray_nrl[0]) / sizeof(iArray_nrl[0][0]);
	printf("Number Of Columns (Height) In Three Dimensional ( 3d ) Integer Array Is = %d \n\n", iArray_height_nrl);

	iArray_depth_nrl = sizeof(iArray_nrl[0][0]) / int_size_nrl;
	printf("Depth Of Elements In three Dimensional ( 3D ) Integer Array is = %d\n\n", iArray_depth_nrl);

	iArray_num_elements_nrl = iArray_width_nrl * iArray_height_nrl * iArray_depth_nrl;
	printf("Number of Elements In Three Dimensional ( 3D ) Integer Array is = %d\n\n", iArray_num_elements_nrl);

	printf("\n\n Elements In Integer 3D Array : \n\n");

	// ***** Piece-Meal Display ***
	//****** ROW 1 *****
	printf("*********** ROW 1 **********\n");
	printf("*********** COLUMN 1 **********\n");
	printf("iArray[0][0][0] = %d\n", iArray_nrl[0][0][0]);
	printf("iArray[0][0][1] = %d\n", iArray_nrl[0][0][1]);
	printf("\n");

	printf("*********** COLUMN 2 **********\n");
	printf("iArray[0][1][0] = %d\n", iArray_nrl[0][1][0]);
	printf("iArray[0][1][1] = %d\n", iArray_nrl[0][1][1]);
	printf("\n");

	printf("*********** COLUMN 3 **********\n");
	printf("iArray[0][2][0] = %d\n", iArray_nrl[0][2][0]);
	printf("iArray[0][2][1] = %d\n", iArray_nrl[0][2][1]);
	printf("\n");

	//****** ROW 2 *****
	printf("*********** ROW 2 **********\n");
	printf("*********** COLUMN 1 **********\n");
	printf("iArray[1][0][0] = %d\n", iArray_nrl[1][0][0]);
	printf("iArray[1][0][1] = %d\n", iArray_nrl[1][0][1]);
	printf("\n");

	printf("*********** COLUMN 2 **********\n");
	printf("iArray[1][1][0] = %d\n", iArray_nrl[1][1][0]);
	printf("iArray[1][1][1] = %d\n", iArray_nrl[1][1][1]);
	printf("\n");

	printf("*********** COLUMN 3 **********\n");
	printf("iArray[1][2][0] = %d\n", iArray_nrl[1][2][0]);
	printf("iArray[1][2][1] = %d\n", iArray_nrl[1][2][1]);
	printf("\n");

	//****** ROW 3 *****
	printf("*********** ROW 3 **********\n");
	printf("*********** COLUMN 1 **********\n");
	printf("iArray[2][0][0] = %d\n", iArray_nrl[2][0][0]);
	printf("iArray[2][0][1] = %d\n", iArray_nrl[2][0][1]);
	printf("\n");

	printf("*********** COLUMN 2 **********\n");
	printf("iArray[2][1][0] = %d\n", iArray_nrl[2][1][0]);
	printf("iArray[2][1][1] = %d\n", iArray_nrl[2][1][1]);
	printf("\n");

	printf("*********** COLUMN 3 **********\n");
	printf("iArray[2][2][0] = %d\n", iArray_nrl[2][2][0]);
	printf("iArray[2][2][1] = %d\n", iArray_nrl[2][2][1]);
	printf("\n");

	//****** ROW 4 *****
	printf("*********** ROW 4 **********\n");
	printf("*********** COLUMN 1 **********\n");
	printf("iArray[3][0][0] = %d\n", iArray_nrl[3][0][0]);
	printf("iArray[3][0][1] = %d\n", iArray_nrl[3][0][1]);
	printf("\n");

	printf("*********** COLUMN 2 **********\n");
	printf("iArray[3][1][0] = %d\n", iArray_nrl[3][1][0]);
	printf("iArray[3][1][1] = %d\n", iArray_nrl[3][1][1]);
	printf("\n");

	printf("*********** COLUMN 3 **********\n");
	printf("iArray[3][2][0] = %d\n", iArray_nrl[3][2][0]);
	printf("iArray[3][2][1] = %d\n", iArray_nrl[3][2][1]);
	printf("\n");

	//****** ROW 5 *****
	printf("*********** ROW 5 **********\n");
	printf("*********** COLUMN 1 **********\n");
	printf("iArray[4][0][0] = %d\n", iArray_nrl[4][0][0]);
	printf("iArray[4][0][1] = %d\n", iArray_nrl[4][0][1]);
	printf("\n");

	printf("*********** COLUMN 2 **********\n");
	printf("iArray[4][1][0] = %d\n", iArray_nrl[4][1][0]);
	printf("iArray[4][1][1] = %d\n", iArray_nrl[4][1][1]);
	printf("\n");

	printf("*********** COLUMN 3 **********\n");
	printf("iArray[4][2][0] = %d\n", iArray_nrl[4][2][0]);
	printf("iArray[4][2][1] = %d\n", iArray_nrl[4][2][1]);
	printf("\n");

	return(0);
}