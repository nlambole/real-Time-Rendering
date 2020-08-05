#include <stdio.h>	

int main(void)
{
	//Variable Declarations
	int iArray_One_nrl[5];
	int iArray_Two_nrl[5][3];
	int iArray_Three_nrl[100][100][5];

	int num_rows_2D_nrl;
	int num_columns_2D_nrl;

	int num_rows_3D_nrl;
	int num_columns_3D_nrl;
	int depth_3D_nrl;

	//Code
	printf("\n\n Size of 1-D Integers Array iArray_One = %lu\n", sizeof(iArray_One_nrl));
	printf("Number of Elments in 1-D Integer array iArray_One =%lu\n", (sizeof(iArray_One_nrl) / sizeof(int)));

	printf("\n\n Size of 2-D integer array iArray_Two = %lu\n", sizeof(iArray_Two_nrl));
	printf("Number of ele rows in 2-D integer array iArray_Two = %lu\n	",(sizeof (iArray_Two_nrl) / sizeof(iArray_Two_nrl[0])));

	num_rows_2D_nrl = (sizeof(iArray_Two_nrl) / sizeof(iArray_Two_nrl[0]));

	printf("Number Of Elements (columns) in each row in 2-D integer array iArray_Two = %ly\n", (sizeof(iArray_Two_nrl[0]) / sizeof(iArray_Two_nrl[0][0])));

	num_columns_2D_nrl = (sizeof(iArray_Two_nrl[0]) / sizeof(iArray_Two_nrl[0][0]));

	printf("Number of elements in total in 2-D Array iArray_Two = %d\n", (num_rows_2D_nrl * num_columns_2D_nrl));

	printf("\n\n\n\n Size of 3-D integer arrray iArray_Three = %lu\n", sizeof(iArray_Three_nrl));

	printf("Number rows in 3-D integer array iArray_Three = %lu\n", (sizeof(iArray_One_nrl) / sizeof(iArray_Three_nrl[0])));
	
	num_columns_3D_nrl = (sizeof(iArray_Three_nrl[0]) / sizeof(iArray_Three_nrl[0][0]));

	printf("Number of elements (depth) in one column in one row in2-D integer array iArray_Three =%lu\n", (sizeof(iArray_Three_nrl[0][0]) / sizeof(sizeof(iArray_Three_nrl[0][0][0]) / sizeof(iArray_Three_nrl[0][0][0]))));

	depth_3D_nrl = (sizeof(iArray_Three_nrl[0][0]) / sizeof(iArray_Three_nrl[0][0][0]));

	printf("Number of elements in total in 3-D Array iArray_Three = %d\n", (num_rows_3D_nrl * num_columns_3D_nrl * depth_3D_nrl));

	printf("\n\n");

	return(0);


}
