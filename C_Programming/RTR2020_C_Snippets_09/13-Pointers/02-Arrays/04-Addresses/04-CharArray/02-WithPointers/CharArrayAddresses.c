#include <stdio.h>	

int main(void)
{
	//Variable Declarations
	char cArray_nrl[10];
	char* ptr_cArray_nrl = NULL;
	int i_nrl;

	//Code
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		cArray_nrl[i_nrl] = (char)(i_nrl + 65);

	// *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
	// *** HENCE< 'cArray' IS THE BASE ADDRESS OF ARRAY cArray[] OR 'cArray' IS THE ADDRESS OF ELEMENT cArray[0] ***
	// *** ASSIGNING BASE ADDRESS OF 'cArray[]' TO CHAR POINTER 'ptr_cArray' 

	ptr_cArray_nrl = cArray_nrl; // ptr_cArray = &cArray[0]

	printf("\n\n Elements Of The Character Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("cArray[%d] = %c\n", i_nrl, *(ptr_cArray_nrl + i_nrl));

	printf("\n\n Elements Of The Character Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("cArray[%d] =%c \t\t Address =%p\n\n\n", i_nrl, *(ptr_cArray_nrl + i_nrl), (ptr_cArray_nrl +1));

	return(0);

}