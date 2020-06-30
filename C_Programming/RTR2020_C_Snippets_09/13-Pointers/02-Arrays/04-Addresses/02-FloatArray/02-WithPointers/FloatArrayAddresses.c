#include <stdio.h>

int main(void)
{
	//Variable Declarations
	float fArray_nrl[10];
	float *ptr_fArray_nrl = NULL;
	int i_nrl;

	//code
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		fArray_nrl[i_nrl] = (float)(i_nrl + 1) * 1.5f;

	// *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
	// *** HENCE, 'fArray' IS THE BASE ADDRESS OF ARRAY fArray[] OR 'fArray' IS THE ADDRESS OF ELEMENT fArray[0] * **
	// *** ASSIGNING BASE ADDRESS OF ARRAY 'fArray[]' TO FLOAT POINTER'ptr_fArray'

	ptr_fArray_nrl =fArray_nrl; // ptr_fArray = &fArray[0];

	printf("\n\n Elements Of The 'float' Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("fArray[%d] = %f\n", i_nrl, *(ptr_fArray_nrl + i_nrl));


	printf("\n\n Elements Of The 'float' Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("fArray[%d] = %f \t \t Address = %p\n\n", i_nrl, *(ptr_fArray_nrl + i_nrl), (ptr_fArray_nrl + i_nrl));


	return(0);
}