#include <stdio.h>

int main(void)
{
	//Variable Declarations
	float f_nrl;
	float f_num_nrl = 1.7f; //Simply Change This Value Only tto Get Different outputs..

	//code
	printf("\n\n");

	printf("Printing Numbers %f to %f : \n\n", f_num_nrl, (f_num_nrl * 10.0f));

	f_nrl = f_num_nrl;
	while (f_nrl <= (f_num_nrl * 10.0f))
	{
		printf("\t %f \n", f_nrl);
		f_nrl = f_nrl + f_num_nrl;
	}

	printf("\n\n");

	return(0);
}