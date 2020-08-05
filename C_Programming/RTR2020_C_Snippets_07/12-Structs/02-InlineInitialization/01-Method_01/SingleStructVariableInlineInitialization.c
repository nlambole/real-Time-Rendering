#include <stdio.h>	

//Definfing Struct
struct MyData
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
	char c_nrl;

}data = { 30, 4.5f, 11.451995, 'A' }; // Inline initialization of struct 'data'of type 'struct MyData'

int main(void)
{
	//Code
	//Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n Data Members Of 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data.i_nrl);
	printf("f = %f\n", data.f_nrl);
	printf("d = %lf\n", data.d_nrl);
	printf("c = %c\n\n", data.c_nrl);

	return(0);
}
