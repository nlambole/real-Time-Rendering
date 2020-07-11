#include <stdio.h>	
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	//Variable Declarations
	int* iArray_nrl[NUM_ROWS]; // A 2D Array which will have 5 rows and number of columns canbe decided later on..
	int i_nrl, j_nrl;
	
	//code
	printf("\n\n ");
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		iArray_nrl[i_nrl] = (int*)malloc(NUM_COLUMNS * sizeof(int));
		if (iArray_nrl[i_nrl] == NULL)
		{
			printf("Failed To Allocate Memory To Row %d Of 2D Integer Array !!! Exiting Now.. \n\n", i_nrl);
			exit(0);

		}
		else
		{
			printf("Memory Allocation To Row %d Of 2D Integer Array Succeded !!!\n\n", i_nrl);
		}
	}

	// *** Assigning Vlaue To 2D Array..
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
		{
			iArray_nrl[i_nrl][j_nrl] = (i_nrl + 1) * (j_nrl + 1);
		}
	}

	// Displaying 2D Array...
	printf("\n\n Displaying 2D Aray : \n\n");

	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
		{
			printf("iArray[%][%d] = %d\n", i_nrl, j_nrl, iArray_nrl[i_nrl][j_nrl]);
		}
		printf("\n\n");

	}
	printf("\n\n");

	//Freeing Memory Assigned To 2D Array (MUst Be Done In Reverse Order )
	for (i_nrl = (NUM_ROWS - 1); i_nrl >= 0; i_nrl--)
	{
		free(iArray_nrl[i_nrl]);
		iArray_nrl[i_nrl] = NULL;
		printf("Memory Allocated To Row %d Of 2D Integer Array Has Been Succesfyllu Freed !!!\n\n", i_nrl);
	}
	return(0);
}