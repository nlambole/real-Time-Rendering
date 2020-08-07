#include <stdio.h>

struct MyData
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
	char c_nrl;
};

int main(void)
{
	//Varaible Declarations
	struct MyData data_nrl;

	//Code
	//Assigning Data Values To The Data Members of 'struct MyData'
	data_nrl.i_nrl = 30;
	data_nrl.f_nrl = 11.45f;
	data_nrl.d_nrl = 1.34343;
	data_nrl.c_nrl = 'A';

	//Displaying Values of The Data Members Of 'struct MyData'
	printf("\n\n Data Members of 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data_nrl.i_nrl);
	printf("f = %f\n", data_nrl.f_nrl);
	printf("d = %lf\n", data_nrl.d_nrl);
	printf("c = %c\n", data_nrl.c_nrl);

	printf("\n\n Address Of Data Members Of 'struct MyData' ARE : \n\n");
	printf("'i' Occupies Address From %p\n", &data_nrl.i_nrl);
	printf("'f' Occupies Address from %p\n", &data_nrl.f_nrl);
	printf("'d' Occupies Address from %p\n", &data_nrl.d_nrl);
	printf("'d' Occupies Address %p\n", &data_nrl.c_nrl); \

		printf("Starting Address Of 'struct MyData' variable 'data' = %p\n\n", &data_nrl);

	return(0);
}