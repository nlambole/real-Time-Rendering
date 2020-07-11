#include <stdio.h>	
#include <stdlib.h>	

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	//Variable Declarations
	int i_nrl, j_nrl;
	int** ptr_iArray_nrl = NULL;

	//Code
	// *** Every Row Of A 2D Array Is An Integer Array Itself Comparising Of NUM_COLUMNS Integer Elements ***
	// *** There Are 5 Rows And 3 Columns In A 2D Integer Array, Array. Each Of The 5 Rows Is A 1D Array Of 3 Integers.
	// *** Hence, Each Of These 5 Row Themselves Bieng Arrays, Will Be The Base Address Of Their Respective Rpows **
	printf("\n\n");

	// ****** MEMORY ALLOCATION ****
	ptr_iArray_nrl = (int**)malloc(NUM_ROWS * sizeof(int*)); // ptr_iArray is the name and vase addrss of 1D Array containing 5 integer pointers to 5 integer arrays.... so it is an aray containing elements of data type (int *)

	if (ptr_iArray_nrl == NULL)
	{
		printf("Memory Allocation To The 1D Array Of Base Address of %d ROWS Failed !!! Exitting Now..\n\n", NUM_ROWS);
		exit(0);
	}
	else
	{
		printf("Memory Allocation To The 1D ARRAY of Base Address Of %d Rows Has Succedded !!!!!! \n\n", NUM_ROWS);
	}
		// *** ALLOCATING MEMORY TO EACH ROW ****
		for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
		{
			ptr_iArray_nrl[i_nrl] = (int*)malloc(NUM_COLUMNS * sizeof(int)); // ptr_iArray[i] is the base address of ith row..
			if (ptr_iArray_nrl == NULL)
			{
				printf("Memory Allocation To The Columns Of ROW %d FAILED !!! EXITING Now....\n\n", i_nrl);

			}
			else
			{
				printf("Memmory Allocation To the Columns of Rows %d Has Succeded !!!\n\n", i_nrl);

			}
		}
		//*** Assigning Values ***
		for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
		{
			for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
			{
				*(*(ptr_iArray_nrl + i_nrl) + i_nrl) = (i_nrl + 1) * (j_nrl + 1);

			}
		}
	
		// **** DISPLAYOING VALUES ***

		printf("\n\n 2D Integer Array Elements Along With Addresses : \n\n");
		for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
		{
			for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
			{
				printf("ptr_iArray_Row[%][%d] = %d \t\t At Address &ptr_iArray_Row[%d][%d] : %p \n	", i_nrl, j_nrl, ptr_iArray_nrl[i_nrl][j_nrl], i_nrl, j_nrl, ptr_iArray_nrl[i_nrl][j_nrl]);
			}
			printf("\n\n");
		}

		// *** FREEING ALLOCATED MEMORY ***
		// *** FREEING MEMORY OF EACH ROW ***
		for (i_nrl = (NUM_ROWS - 1); i_nrl >= 0; i_nrl--)
		{
			if (*(ptr_iArray_nrl + i_nrl))
			{
				free(*(ptr_iArray_nrl + i_nrl)); // free(ptr_iarray[i]
				*(ptr_iArray_nrl + i_nrl);//ptr_iArray[i] = NULL;
				printf("Memory Allocated To Row %d Has Been Successfully Freed !!!\n\n", i_nrl);
			}
		}

		// *** Freeing Memory Of ptr_iArray Which Is The Array Of 5 Integer Pointers...That it, It Is An Array Having 5 Integer Address (Type int*)
		
		if (ptr_iArray_nrl)
		{
			free(ptr_iArray_nrl);
			ptr_iArray_nrl = NULL;
			printf("Memory Allocated To ptr_iArray Has Been SUCCESSFULLY FREED !!! \n\n");

		}
		return 0;

}