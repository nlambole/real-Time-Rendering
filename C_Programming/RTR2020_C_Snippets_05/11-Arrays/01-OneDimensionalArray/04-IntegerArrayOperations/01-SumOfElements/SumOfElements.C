#include <stdio.h>
#define NUM_ELEMENTS 10

int main(void)
{
	// Variables Declarations
	int iArray_nrl[NUM_ELEMENTS];
	int i_nrl, num_nrl, sum_nrl = 0;

	// Code
	printf("\n\n Enter Integer Elements For Array : \n\n");
	for (i_nrl = 0; i_nrl < NUM_ELEMENTS; i_nrl++)
	{
		scanf("%d", &num_nrl);
		iArray_nrl[i_nrl] = num_nrl;
	}

	for (i_nrl = 0; i_nrl < NUM_ELEMENTS; i_nrl++)
	{
		sum_nrl = sum_nrl + iArray_nrl[i_nrl];
	}

	printf("\n\n Sum Of All Elements Of Array = %d\n\n", sum_nrl);

	return(0);
}