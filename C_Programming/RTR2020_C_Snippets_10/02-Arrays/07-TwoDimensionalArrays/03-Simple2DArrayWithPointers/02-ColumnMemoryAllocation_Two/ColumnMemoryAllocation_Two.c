#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS_ONE 3
#define NUM_COLUMNS_TWO 8

int main(void)
{
	//Variable Declarations
	int* iArray_nrl[NUM_ROWS]; // A 2D Array which will have 5 rows and number of columns can be decided latter on..
	int i_nrl, j_nrl;

		/// *** One (ALLOCATING MEMORY FOR AN ARRAY OF 3 INTEGERS PER ROW ) ******
		printf("\n\n ******** FIRST MEMORY ALLOCATION TO 2D INTEGER ARRAY ********\n\n");
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		iArray_nrl[i_nrl] = (int*)malloc(NUM_COLUMNS_ONE * sizeof(int));
		if (iArray_nrl[i_nrl] == NULL)
		{
			printf("Failed To Allocate Memory To Row %d Of 2D Integer Array !!! Exiting Now...\n\n", i_nrl);
			exit(0);
		}
		else
			printf("memory Allocation To Row %d Of  2D Integer Array Succeeded !!\n\n", i_nrl);
	}

	//ASSIGNING VALUED TO 2D ARRAY....
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS_ONE; j_nrl++)
		{
			printf("iArray[%d][%d] = %d\n", i_nrl, j_nrl, iArray_nrl[i_nrl][i_nrl]);
		}
		printf("\n\n");
	}
	printf("\n\n");	
	
	//Freeing Memory Assigned To 2D ARRAY (Must Be Done In Reverse Order	)
	for (i_nrl = (NUM_ROWS - 1); i_nrl >= 0; i_nrl--)
	{
		free(iArray_nrl[i_nrl]);
		iArray_nrl[i_nrl] = NULL;
		printf("Memmory Allocarted To Row %d Of 2D Integer Array Has Been Successfully Freed !!!\n\n", i_nrl);
	}

	// *** Two (Allocating Memory For An Array Of 8 Integers Per Row) ****
	printf("\n\n ********** SECOND MEWmeory Allocation To 2D Integer Array ******\n\n");
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		iArray_nrl[i_nrl] = (int*)malloc(NUM_COLUMNS_TWO * sizeof(int));
		if (iArray_nrl[i_nrl] == NULL)
		{
			printf("Failed To Allocate Memory To Row %d Of 2D Integer Array !!! Exiting Now....\n\n", i_nrl);

		}
		else
			printf("Memory Allocation To Row %d Of 2D InTEGER Array !!! Exitting Now..\n\n ", i_nrl);
		exit(0);
	}

	// Assinging Values To 2D Array ....
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS_ONE; j_nrl++)
		{
			iArray_nrl[i_nrl][j_nrl] = (i_nrl = 1) * (j_nrl + 1);
		}
	}

	//Displaying 2D Array..
	printf("\n\n DISPLAYING 2D ARRAY : \n\n");
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS_ONE; j_nrl++)
		{
			printf("iArray[%d][%d] = %d\n", i_nrl, j_nrl, iArray_nrl[i_nrl][j_nrl]);
		}
		printf("\n\n");
	}
	printf("\n\n");

	//FREEING MEMORY ASSIGNED TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER )
	for (i_nrl = (NUM_ROWS - 1); i_nrl >= 0; i_nrl--)
	{
		free(iArray_nrl[i_nrl]);
		iArray_nrl[i_nrl] = NULL;

		printf("Memory Allocated To To Row %d Of 2D Integer Array Hass Been Successfully Freed !!!\n\n", i_nrl);
	}
	return (0);
}
