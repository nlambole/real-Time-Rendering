#include <stdio.h>

int main(void)
{
	//Defining Struct 
	struct MyData
	{
		int i_nrl;
		float f_nrl;
		double d_nrl;
		char c_nrl;
	}data = { 5, 9.1f, 3.78623, 'N' };;

	// Displaying Values Of The Data Members of 'struct MyData'

	printf("\n\n Data Members Of 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data.i_nrl);
	printf("f = %f\n", data.f_nrl);
	printf("d = %lf\n", data.d_nrl);
	printf("c = %c\n\n", data.c_nrl);

	return(0);

}
