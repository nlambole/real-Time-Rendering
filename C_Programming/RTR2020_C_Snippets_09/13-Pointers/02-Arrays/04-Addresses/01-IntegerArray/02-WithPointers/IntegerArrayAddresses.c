#include <stdio.h>	

int main(void)
{
	// Variable Declarations
	int iArray_nrl[10];
	int *ptr_iArray_nrl = NULL;
	int i_nrl;

	// Code
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		iArray_nrl[i_nrl] = (i_nrl + 1) * 3;

	// *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
	// *** HENCE, 'iArray' Is THE BASE ADDRESS OF ARRAY iArray[] OR 'iArray' Is The Address Of Elemnet iArray[0] ***
	// *** Assigning Base Address Of Array 'iArray[]' To Integer Pointer 'ptr_iArray'

	ptr_iArray_nrl = iArray_nrl; // ptr_iArray = &iArray[0]

	printf("\n\n Elements Of The Integer Array :\n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("iArray[%d] = %d\n", i_nrl, *(ptr_iArray_nrl + i_nrl));

	printf("\n\n Elements  Of The Integer Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("iArray[%d] = %d \t\t Address =%p\n", i_nrl, *(ptr_iArray_nrl + i_nrl), (ptr_iArray_nrl + i_nrl));

	printf("\n\n");
	return(0);


}