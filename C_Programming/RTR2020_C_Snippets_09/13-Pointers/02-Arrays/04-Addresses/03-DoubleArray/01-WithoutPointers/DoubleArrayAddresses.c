#include <stdio.h>	

int main(void)
{
	//Variable Declarations
	double dArray_nrl[10];

	int i_nrl;

	//code
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		dArray_nrl[i_nrl] = (float)(i_nrl + 1) * 1.333333f;

	printf("\n\n Elements Of The 'double' Array :\n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("dArray[%d] = %lf\n", i_nrl, dArray_nrl[i_nrl]);

	printf("\n\n Elements Of The 'double' Array : \n\n");
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("dArray[%d] =%lf\t\t Address =%p\n\n", i_nrl, dArray_nrl[i_nrl], &dArray_nrl[i_nrl]);
	return(0);
}