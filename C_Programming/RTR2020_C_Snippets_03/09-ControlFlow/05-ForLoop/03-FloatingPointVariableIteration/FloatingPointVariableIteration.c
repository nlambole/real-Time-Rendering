#include <stdio.h>

int main(void)
{
	//Variable Declararations
	float f_nrl;
	float f_num = 1.7f; //Simply Change This value ONLY to Get Different Outputs..

	//code
	printf("n\n");
	printf("Printing Numbers %f to %f : \n\n", f_num, (f_num * 10.0f));

	for (f_nrl = f_num; f_nrl <= (f_num * 10.0f); f_nrl = f_nrl + f_num)
	{
		printf("\t%f\n", f_nrl);
	}

	printf("\n\n");

	return(0);
}