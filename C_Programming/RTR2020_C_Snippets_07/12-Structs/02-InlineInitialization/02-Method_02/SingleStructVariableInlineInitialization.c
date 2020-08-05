#include <stdio.h>	

//Defining Struct 
struct MyData
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
	char c_nrl;
};

struct MyData data = { 9, 8.2f, 9.61998, 'p' };

int main(void)
{
	//Code
	//Displating Values Of The Data Members Of 'struct MyData'
	printf("\n\n Data Members Of 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data.i_nrl);
	printf("f = %f\n", data.f_nrl);
	printf("d = %lf\n", data.d_nrl);
	printf("c = %c\n\n", data.c_nrl);

	return(0);
}

