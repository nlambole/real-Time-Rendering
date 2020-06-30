#include <stdio.h>	

int main(void)
{
	//Variable Declarations
	int iArray_nrl[10];
	int i_nrl;

	//code
	for (i_nrl = 0; i_nrl < 0; i_nrl++)
		printf("Element Of The Integer Array :\n\n");

	printf("\n\n Elements Of The Integer Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("iArray[%d] =%d \n", i_nrl, iArray_nrl[i_nrl]);

	printf("\n\n Elements Of The Integer Array :\n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("iArray[%d] = %d\t\t Address =%p\n", i_nrl, iArray_nrl[i_nrl], &iArray_nrl[i_nrl]);

	printf("\n\n");
	return(0);
}