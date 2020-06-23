#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
	// Variables Declarations
	int iArray_nrl[NUM_ELEMENTS];
	int i_nrl, num_nrl, sum_nrl = 0;

	// Code
	printf("\n\n ");

	// ***** ARRAY ELEMENTS INPUT *****
	printf("Enter Integer Elements For Array : \n\n");
	for (i_nrl = 0; i_nrl < NUM_ELEMENTS; i_nrl++)
	{
		scanf("%d", &num_nrl);
		iArray_nrl[i_nrl] = num_nrl;
	}
	// *** Separating Out Even Numbers From Array Elements ***
	printf("\n\n Even Numbers Amongst the Array Elements Are : \n\n ");
	for (i_nrl = 0; i_nrl < NUM_ELEMENTS; i_nrl++)
	{
		if ((iArray_nrl[i_nrl] % 2) == 0)
			printf("%d\n", iArray_nrl[i_nrl]);
	}

	// **** Separating Out Odd Numbers From Array Elements ***
	printf("\n\n Odd Numbers Amongst The Array Elements Are : \n\n");
	for (i_nrl = 0; i_nrl < NUM_ELEMENTS; i_nrl++)
	{
		if ((iArray_nrl[i_nrl] % 2) != 0)
			printf("%d\n", iArray_nrl[i_nrl]);
	}

	return(0);
	
}