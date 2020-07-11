#include <stdio.h>	

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
	//Variable Declareations
	int iArray_nrl[NUM_ROWS][NUM_COLUMNS];
	int i_nrl, j_nrl;

	//Code
	// *** Name Of An Array Itself Is Its Base Address **	
	// *** Hence, 'iArray' Is Base Address Of 2D Integer Array iArray[][]

	// iArray[5][3] => iArray Is A 2D Array Having 5 Rows And 3 Columns. Each  Of These 5 Rows Is A 1D Integer Array Of 3 Integers Array of 3 Integers ***
	// iArray[0] = Is The 0th Row...Hence, is The Base Address Of ROW 0..
	// iArray[1] = Is The 0th Row...Hence, is The Base Address Of ROW 1..
	// iArray[4] = Is The 0th Row...Hence, is The Base Address Of ROW 4..

	// (iArray[0] + 0) => Address Of 0th Integer From Base Address Of 0th Row (iArray[0][0])
	// (iArray[0] + 1) => Address Of 0th Integer From Base Address Of 0th Row (iArray[0][1])
	// (iArray[0] + 2) => Address Of 0th Integer From Base Address Of 0th Row (iArray[0][2])

	// (iArray[1] + 0) => Address Of 0th Integer From Base Address Of 0th Row (iArray[1][0])
	// (iArray[1] + 1) => Address Of 0th Integer From Base Address Of 0th Row (iArray[1][1])
	// (iArray[1] + 2) => Address Of 0th Integer From Base Address Of 0th Row (iArray[1][2])

	// iArray[0], iArray[1] .. Are 1D Integer Arrays And Hence Can be Treated As 1D Integer Arrays Using Pointers

	// 'iArray' Is The Name And Base Address of 2D Integers Array ***
	// (*iArray + 0) + 0) =(iArray[0] + 0) = Address if 0th Element From Base Address of 0th Row = (iArray[0] + 0) = (iArray[0][0])
	// (*iArray + 0) + 0) =(iArray[0] + 0) = Address if 0th Element From Base Address of 0th Row = (iArray[0] + 1) = (iArray[0][1])
	// (*iArray + 0) + 0) =(iArray[0] + 0) = Address if 0th Element From Base Address of 0th Row = (iArray[0] + 2) = (iArray[0][2])

	// (*(iArray + 1) + 0) = (iArray[1] + 0) = ADDRESS OF 0TH ELEMENT FROM BASE	ADDRESS OF 1ST ROW = (iArray[1] + 0) = (iArray[1][0])
	// (*(iArray + 1) + 1) = (iArray[1] + 1) = ADDRESS OF 1ST ELEMENT FROM BASE	ADDRESS OF 1ST ROW = (iArray[1] + 1) = (iArray[1][1])
	// (*(iArray + 1) + 2) = (iArray[1] + 2) = ADDRESS OF 2ND ELEMENT FROM BASEADDRESS OF 1ST ROW = (iArray[1] + 2) = (iArray[1][2])

	for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)

		{
			*(*(iArray_nrl + i_nrl) + j_nrl) = (i_nrl + 1) * (j_nrl + 1); // iArray[i] can be Treated As 1D Array Using Pointers
		}
	}

		printf("\n\n 2D Integer Array Elements Along With Address : \n\n");
		for (i_nrl = 0; i_nrl < NUM_ROWS; i_nrl++)
		{
			for (j_nrl = 0; j_nrl < NUM_COLUMNS; j_nrl++)
			{
				printf("*(*(iArray + %d) + %d)= %d \t \t At Address (*(iArray + %d) + % d) : % p\n\n\n", i_nrl, j_nrl, *(*(iArray_nrl + i_nrl) + j_nrl), i_nrl, j_nrl, (*(iArray_nrl + i_nrl) + j_nrl));
				
			}
		}
	return (0);
}