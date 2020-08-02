#include <stdio.h>	

//Defining Struct 
struct MyData
{
	int* ptr_i_nrl;
	int i_nrl;

	float* ptr_f_nrl;
	float f_nrl;

	double* ptr_d_nrl;
	double d_nrl;
};

int main(void)
{
	//Variable Declarations
	struct MyData data_nrl;

	//Code
	data_nrl.i_nrl = 9;
	data_nrl.ptr_i_nrl = &data_nrl.i_nrl;

	data_nrl.f_nrl = 11.45f;
	data_nrl.ptr_f_nrl = &data_nrl.f_nrl;

	data_nrl.d_nrl = 20.121995;
	data_nrl.ptr_d_nrl = &data_nrl.d_nrl;

	printf("\n\n i = %d\n", *(data_nrl.ptr_i_nrl));
	printf("Address Of 'i' = %p\n", data_nrl.ptr_i_nrl);

	printf("\n\n f = %f\n", *(data_nrl.ptr_f_nrl));
	printf("Address Of 'f' =%p\n", (data_nrl.ptr_f_nrl));

	printf("\n\n d = %lf\n", *(data_nrl.ptr_d_nrl));
	printf("Address Of 'd' = %p\n	", data_nrl.ptr_d_nrl);
	

	return(0);

}
