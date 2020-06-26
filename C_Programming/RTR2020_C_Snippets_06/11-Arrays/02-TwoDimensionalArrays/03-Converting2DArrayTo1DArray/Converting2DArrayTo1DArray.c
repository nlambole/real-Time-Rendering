#include <stdio.h>


#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	// Varaible Declarations
	int iArray_2D_nrl[NUM_ROWS][NUM_COLUMNS]; // Total Number of Elements = NUM_ROWS * NUM_COLUMNS
	int iArray_1D_nrl[NUM_ROWS * NUM_COLUMNS];
	int i_nrl, j_nrl;
	int num_nrl;

	//CODE
	printf("Enter Elements Of You Choise To Fill Up The Integer 2D Array : \n\n ");
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		printf("For ROW NUMBER %d : \n", (i_nrl + 1));
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
		{
			printf("Enter Element Number %d : \n", (j_nrl + 1));
			scanf("%d", &num_nrl);
			iArray_2D_nrl[i_nrl][j_nrl] = num_nrl;
		}
	}
	printf("\n\n");

	// **** DISPLAY OF 2D ARRAY ***
	printf("\n\n Two_Dimensional (2D) Array Of Integers : \n\n");

	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		printf("******** ROW %d *********\n", (i_nrl + 1));
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl)
		{
			printf("iArray_2D[%d][%d] = %d\n", i_nrl, j_nrl, iArray_2D_nrl[i_nrl][j_nrl]);
		}
		printf("\n\n");

	}

	// *** Converting 2D Integer Array To 1D Integer Array ****
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
		{
			iArray_1D_nrl[(i_nrl * NUM_COLUMNS) + j_nrl] = iArray_2D_nrl[i_nrl][j_nrl];
		}
	}

	// ***** PRINTING 1D Array*****
	printf("\n\n One_Dimensional (1D) Array Of Integers : \n\n");

	for (i_nrl = 0; i_nrl < (NUM_ROWS * NUM_COLUMNS); i_nrl++)
	{
		printf("iArray_1D[%d] = %d \n\n", i_nrl, iArray_1D_nrl[i_nrl]);
	}
	printf("\n\n");
	return(0);
}
