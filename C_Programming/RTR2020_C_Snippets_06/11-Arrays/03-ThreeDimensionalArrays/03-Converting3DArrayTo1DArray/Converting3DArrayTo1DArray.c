#include <stdio.h>	

#define NUM_ROWS 5	
#define NUM_COLUMNS 3
#define DEPTH 2

int main(void)
{
	// Variable Declarations

	// In-Line Initializataion
	int iArray_nrl [NUM_ROWS][NUM_COLUMNS][DEPTH]= { { { 9, 18 }, { 27, 36 }, { 45, 54 } }, { { 8, 16 }, { 24, 32 }, { 40, 48 } }, { { 7, 14 }, { 21, 28 }, { 35, 42 } }, { { 6, 12 }, { 18, 24 }, { 30, 36 } }, { { 5, 10 }, { 15, 20 }, { 25, 30 } } };
	int i_nrl, j_nrl, k_nrl;

	int iArray_1D_nrl[NUM_ROWS * NUM_COLUMNS * DEPTH]; // 5 * 3 * 2 Elements => 30 Elections In 1D Array

	//code

	// *** DISPLAY 3D Array ***
	printf("\n\n Elements In the 3D Array : \n\n");
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		printf("********** ROW %d *********\n", (i_nrl + 1));
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++);
		{
			printf("********** COLUMNS %d *********\n", (j_nrl + 1));
			for (k_nrl = 0; k_nrl < DEPTH; k_nrl++)
			{
				printf("iArray[%d][%d][%d] = %d\n", i_nrl, j_nrl, k_nrl, iArray_nrl[i_nrl][j_nrl][k_nrl]);

			}
			printf("\n");
		}
		printf("\n\n");
	}


	// **** COVERTING 3D To 1D *********
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++);
		{
			for (k_nrl = 0; k_nrl < DEPTH; k_nrl++)
			{
				iArray_1D_nrl[(i_nrl * NUM_COLUMNS * DEPTH) + (j_nrl * DEPTH) + k_nrl] = iArray_nrl[i_nrl][j_nrl][k_nrl];


			}
		}
	}

	// *********DISPLAY 1D ARRAY *********
	printf("\n\n\n\n Elements In The 1D Array : \n\n");
	for (i_nrl = 0; i_nrl < (NUM_ROWS * NUM_COLUMNS * DEPTH); i_nrl++);
	{
		printf("iArray_1D[%d] = %d\n", i_nrl, iArray_1D_nrl[i_nrl]);
	}

	return(0);

}