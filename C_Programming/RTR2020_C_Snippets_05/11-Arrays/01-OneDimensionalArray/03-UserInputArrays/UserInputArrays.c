#include <stdio.h>

// MACRO CONSTANT USED AS ARRAY SIZE IN SUBSCRIPT AND AS ARRAY LENGHT.
// HENCE, THIS PROGRAM'S ARRAYS ' SIZES CAN BE SIMPLY CHANGED BY CHANGING THESE FOLLOWING 3 GLOBAL MACRO CONSTANT VALUES, BEFORE COMPILING, LINKING AND EXECUTING THE PROGRAM !!!

#define INT_ARRAY_NUM_ELEMENTS 5
#define FLOAT_ARRAY_NUM_ELEMENTS 3
#define CHAR_ARRAY_NUM_ELEMENTS 15

int main(void)
{
	// Variables Declarations
	int iArray_nrl[INT_ARRAY_NUM_ELEMENTS];
	float fArray_nrl[FLOAT_ARRAY_NUM_ELEMENTS];
	char cArray_nrl[CHAR_ARRAY_NUM_ELEMENTS];
	int i_nrl, num_nrl;

	// CODE

	// ******* Array Elements Input ******
	printf("\n\n Enter Elements For 'Integer' Array : \n");
	for (i_nrl = 0; i_nrl < INT_ARRAY_NUM_ELEMENTS; i_nrl++)
		scanf("%d", &iArray_nrl[i_nrl]);

	printf("\n\n Enter Elements For 'Floating-Point' Array : \n");
	for (i_nrl = 0; i_nrl < FLOAT_ARRAY_NUM_ELEMENTS; i_nrl++)
		scanf("%f", &fArray_nrl[i_nrl]);

	printf("\n\n Enter Elemetns For 'Character' Array : \n");
	for (i_nrl = 0; i_nrl < CHAR_ARRAY_NUM_ELEMENTS; i_nrl++)
	{
		cArray_nrl[i_nrl] = getch();
		printf("%c\n", cArray_nrl[i_nrl]);
	}

	// ****** Array Elements OUTPUT *****

	printf("\n\n Integer Array Entered By You : \n\n");
	for (i_nrl = 0; i_nrl < INT_ARRAY_NUM_ELEMENTS; i_nrl++)
		printf("%d\n", iArray_nrl[i_nrl]);

	printf("\n\n Floating-Point Array Entered By Ypu : \n\n");
	for (i_nrl = 0; i_nrl < FLOAT_ARRAY_NUM_ELEMENTS; i_nrl++)
		printf("%f\n", fArray_nrl[i_nrl]);

	printf("\n\n Character Array Entered By  You : \n\n");
	for (i_nrl = 0; i_nrl < CHAR_ARRAY_NUM_ELEMENTS; i_nrl++)
		printf("%c\n", cArray_nrl[i_nrl]);

	return(0);

}