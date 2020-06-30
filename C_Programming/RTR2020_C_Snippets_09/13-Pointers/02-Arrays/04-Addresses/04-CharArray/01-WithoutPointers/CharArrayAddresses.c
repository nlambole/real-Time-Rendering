#include <stdio.h>

int main(void)
{
	//Variable Declarations
	char cArray_nrl[10];
	int i_nrl;

	//Code
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		cArray_nrl[i_nrl] = (char)(i_nrl + 65);

	printf("\n\n Elements Of The Character Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("cArray[%d] = %c\n", i_nrl, cArray_nrl[i_nrl]);

	printf("\n\n Elements Of The Character Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("cArray[%d] =%c\t\t Address  =%p\n\n", i_nrl, cArray_nrl[i_nrl], &cArray_nrl[i_nrl]);

	return(0);
}