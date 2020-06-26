#include <stdio.h>	

int main(void)
{
	// Variable Declarations

	// In-Line Initializataion
	int iArray_nrl[5][3][2] = { { { 9, 18 }, { 27, 36 }, { 45, 54 } }, { { 8, 16 }, { 24, 32 }, { 40, 48 } }, { { 7, 14 }, { 21, 28 }, { 35, 42 } }, { { 6, 12 }, { 18, 24 }, { 30, 36 } }, { { 5, 10 }, { 15, 20 }, { 25, 30 } } };
	int int_size_nrl;
	int iArray_size_nrl;
	int iArray_num_elements_nrl, iArray_width_nrl, iArray_height_nrl, iArray_depth_nrl;
	int i_nrl, j_nrl, k_nrl;

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

	for (i_nrl = 0; i_nrl < iArray_width_nrl; i_nrl++)
	{
		printf("*********** ROW %d *********\n", (i_nrl + 1));
		for (j_nrl = 0; j_nrl < iArray_height_nrl; j_nrl++)
		{
			printf("************ COLUMN %d **********\n", (j_nrl + 1));
			for (k_nrl = 0; k_nrl < iArray_depth_nrl; k_nrl++)
			{
				printf("iArray[%d][%d][%d] = %d\n", i_nrl, j_nrl, k_nrl, iArray_nrl[i_nrl][j_nrl][k_nrl]);
			}
			printf("\n");

		}
		printf("\n\n");
	}
	return(0);
}