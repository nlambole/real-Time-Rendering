#include <stdio.h>

int main(void)
{
	//Variable Declarations
	double dArray_nrl[10];
	double* ptr_dArray_nrl = NULL;
	int i_nrl;

	//Code
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		dArray_nrl[i_nrl] = (float)(i_nrl + 1) * 1.333333f;

	// *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
	// *** HENCE, 'dArray' IS THE BASE ADDRESS OF ARRAY dArray[] OR 'dArray' IS THE ADDRESS OF ELEMENT dArray[0]
	// *** ASSIGNING BASE ADDRESS OF ARRAY 'dArray[]' To DOUBLE POINTER 'ptr_dArray' 

	ptr_dArray_nrl = dArray_nrl; //ptr_dArray = &dArray[0];


	printf("\n\n Elements Of The 'double' Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("dArray[%d] =%lf\n", i_nrl, *(ptr_dArray_nrl + i_nrl));

	printf("\n\n Elements Of The 'double' Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("dArray[%d] = %lf\t\t Address =%p\n", i_nrl, *(ptr_dArray_nrl + i_nrl), (ptr_dArray_nrl + i_nrl));
	return(0);
}