#include <stdio.h>	

int main(void)
{
	//Variable Declarations
	float fArray_nrl[10];
	int i_nrl;

	//Code
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		fArray_nrl[i_nrl] = (float)(i_nrl + 1) * 1.5f;

	printf("\n\n Elements Of The 'float' Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("fArray[%d] = %f\n", i_nrl, fArray_nrl[i_nrl]);

	printf("\n\n Elements Of The 'float' Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("fArray[%d] =%f\t\t Address =%p\n", i_nrl, fArray_nrl[i_nrl], &fArray_nrl[i_nrl]);
	printf("\n\n");

	return(0);

}