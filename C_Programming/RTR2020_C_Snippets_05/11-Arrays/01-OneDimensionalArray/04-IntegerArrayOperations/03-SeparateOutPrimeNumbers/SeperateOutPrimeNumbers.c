#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
	// Variable Declarations
	int iArray_nrl[NUM_ELEMENTS];
	int i_nrl, num_nrl, j_nrl, count = 0;

	// Code
	printf("\n\n");

	// *** ARRAY ELEMENTS INPUT ****
	printf("Enter Integer Elements For Array : \n\n");
	for (i_nrl = 0; i_nrl < NUM_ELEMENTS; i_nrl++)
	{
		scanf("%d", &num_nrl);
		
		// If 'num' is negative (< 0), then convert it to positive (multiply by -1)

		if (num_nrl < 0)
			num_nrl = -1 * num_nrl;

		iArray_nrl[i_nrl] = num_nrl;
	}

	// **** PRINTING ENTIRE ARRAY ****

	printf("\n\n Array Elements Are : \n\n ");
	for (i_nrl = 0; i_nrl < NUM_ELEMENTS; i_nrl++)
		printf("%d\n", iArray_nrl[i_nrl]);

	// ***** SAPARATING OUT EVEN NUMBERS FROM Array ELements ***
	printf("Prime Numbers Amongst The Array Elements Are : \n\n");
	for (i_nrl = 0; i_nrl < NUM_ELEMENTS; i_nrl++)
	{
		for (j_nrl = 1; j_nrl < iArray_nrl[i_nrl]; j_nrl++)
		{
			if ((iArray_nrl[i_nrl] % j_nrl) == 0)
				count++;
		}

		// NUMBER ! IS NEITHER A PRIME NUMBER NOR A CONSONANT
		// IF A NUMBER IS PRIME, IT IS ONY DIVISIBLE BY 1, AND ITSELF.
		// HENCE, IF A NUMBER IS PRIME< THE VALUE OF 'count' WILL BE EXACTLY 2.
		// IF THE VALUE OF 'count' IS GREATER THAN 2, THE NUMBER IS DIVISIBLE BY NUMBERS OTHER THAN 1 AND ITSELF AND HENCE, IT IS NOT PRIME .
		//THE VALUE OF 'count' WILL BE 1 ONLY IF iArray_nrl[i_nrl] IS 1.
		if (count == 2)
			printf("%d \n", iArray_nrl[i_nrl]);

		count = 0; // RESET 'count' To 0 FOR CHECKING THE NEXT NUMBER...
	}

	return(0);
}