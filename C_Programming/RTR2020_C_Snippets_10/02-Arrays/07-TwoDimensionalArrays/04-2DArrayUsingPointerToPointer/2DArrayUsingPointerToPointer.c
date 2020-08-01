#include <stdio.h>	
#include <stdlib.h>

int main(void)
{
	//Varaibel Declarations
	int** ptr_iArray_nrl = NULL;

	int i_nrl, j_nrl;
	int num_rows_nrl, num_columns_nrl;

	//Code

	// *** Accept Number Of Rows 'num_rows' From User ***
	printf("\n\n Enter Number Of Rows : ");
	scanf("%d", &num_rows_nrl);

	// *** Accept Number Of Columns 'num_columns' From User ***
	printf("\n\n Enter Number Of Columns : ");
	scanf("%d", &num_columns_nrl);

	// *** Allocatting Memory To 1D Array Consisting Of Base Of Address Of Rows **
	printf("\n\n ******* Memory Allocating To 2D Integr Array ******\n\n");

		ptr_iArray_nrl = (int**)malloc(num_rows_nrl * sizeof(int*));
		if (ptr_iArray_nrl == NULL)
		{
			printf("Failed To Allocate Memory To %d Rows Of 2D Integer array !!! Exitting Now..\n\n", num_rows_nrl);
			exit(0);

		}
		else
			printf("Memory Allocation To %d Rows Of 2D Integer Array Succeeded !!! \n\n", num_rows_nrl);
	
		// *** Allocating Memory TO Each Row Which Is A 1D Array Containing Consisting Of Columns Which Contain The Actual Integers ***
		for (i_nrl = 0; i_nrl < num_rows_nrl; i_nrl++)
		{
			ptr_iArray_nrl[i_nrl] = (int*)malloc(num_columns_nrl * sizeof(int)); //Allocating Memory (Number Of Columns * size of 'int') To Row 'i'
			if (ptr_iArray_nrl[i_nrl] == NULL) //Row 'i' Memory Allocated ?
			{
				printf("Failed TO Allocate Memory To Columns Of Rowscanf %d Of 2D Integer Array !!! Exiting Now...\n\n", i_nrl);
				exit(0);
			}
			else
			{
				printf("Memory Allocations To Columns Of ROw %d Of 2D Integer Array Succeede !!\n\n", i_nrl);
			}

		}

		// *** Filling Up Values ***
		for (i_nrl; i_nrl < num_rows_nrl; i_nrl)
		{
			for (j_nrl = 0; j_nrl < num_columns_nrl; j_nrl++)
			{
				printf("ptr_iArray[%d][%d] = %d \t At Address : %p\n", i_nrl, j_nrl, ptr_iArray_nrl[i_nrl][j_nrl], &ptr_iArray_nrl[i_nrl][j_nrl]); //Can Also Use *(*(ptr_iArray + i) + j) for Value and *(ptr_iArray + i_nrl) + j for Address 

			}
				printf("\n");
		}

		// *** Freeing Mmeory Allocated TO Each Row ***
		for (i_nrl = (num_rows_nrl - 1); i_nrl >= 0; i_nrl--)
		{
			if (ptr_iArray_nrl[i_nrl])
			{
				free(ptr_iArray_nrl[i_nrl]);
				ptr_iArray_nrl[i_nrl] = NULL;
				printf("Memory Allocated To Row %d Has Been Successfully Freed !!!\n\n", i_nrl);
			}
		}

		// *** Freeing Memory Allocated TO 1D Array Consisting Of Base Address Of Rows ***
		if (ptr_iArray_nrl)
		{
			free(ptr_iArray_nrl);
			ptr_iArray_nrl = NULL;
			printf("Memory Allocated TO ptr_iArray Hass Been Successfully Freed !!! \n\n");
		}
	return(0);
}
