#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 5

int main(void)
{
	//Variable Declarations
	int* iArray_nrl[NUM_ROWS]; // A 2D Array Which Will Have 5 rows and number of columns can be decided later on...
	int i_nrl, j_nrl;

	//Code
	printf("\n\n ********* MEMORY ALLOCATION TO 2D INTERGER ARRAY **********\n\n");
	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		//ROW 0 WILL HAVE (NUM_COLUMNS - 0) = (5 - 0) = 5 COLUMNS...
		//ROW 1 WILL HAVE (NUM_COLUMNS - 1) = (5 - 1) = 4 COLUMNS...
		//ROW 2 WILL HAVE (NUM_COLUMNS - 2) = (5 - 2) = 3 COLUMNS...
		//ROW 3 WILL HAVE (NUM_COLUMNS - 3) = (5 - 3) = 2 COLUMNS...
		//ROW 4 WILL HAVE (NUM_COLUMNS - 4) = (5 - 4) = 1 COLUMNS...

		//Beacause Of This, There Is No Contiguos Memory Allocation.....Hence, ALTHOUGH WE MAY USE THE DATA AS A 2D ARRAY, IT Is NOT Really, A 2D Array In Memory...

		iArray_nrl[i_nrl] = (int*)malloc((NUM_COLUMNS - i_nrl) *sizeof(int));
		if (iArray_nrl[i_nrl] == NULL)
		{
			printf("Failed To Allocate Memory Memory To Row %d Of 2D Integer Array !!! Exitting Now...\n\n", i_nrl);
			exit(0);
		}
		else
			printf("Memory Allocation Row %d Of 2D Integer Aray Succeede !!!\n\n", i_nrl);
	}

	for (i_nrl = 0; i_nrl < 5; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < (NUM_COLUMNS - i_nrl); j_nrl++)
		{
			printf("iArray[%d][%d] = %d \t At Address : %p \n	", i_nrl++, j_nrl++, iArray_nrl[i_nrl][j_nrl], &iArray_nrl[i_nrl][j_nrl]);
		}
		printf("\n\n");
	}

	for (i_nrl = (NUM_ROWS - 1); i_nrl >= 0; i_nrl--)
	{
		if (iArray_nrl[i_nrl])
		{
			free(iArray_nrl[i_nrl]);
			iArray_nrl[i_nrl] = NULL;
			printf("Memory Allocated To Row %d Has Been Successfully Freed !!!\n\n",i_nrl);
		}
	}

	return(0);
}