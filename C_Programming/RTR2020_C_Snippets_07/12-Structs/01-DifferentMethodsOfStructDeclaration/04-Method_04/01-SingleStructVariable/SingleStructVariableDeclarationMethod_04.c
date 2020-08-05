#include <stdio.h>	

//Defining StrucT..
struct MyData
{
	int i_nrl;
	float f_nrl;
	double d_nrl;

};

struct MyData data; //Declararing a single struct variable of type 'struct MyData' globally...

int main(void)
{
	//Varaible Declarations
	struct MyData data;

	int i_size_nrl;
	int f_size_nrl;
	int d_size_nrl;
	int struct_MyData_size_nrl;

	//Code
	//Assigning Data Values To The Data Members Of 'struct MyData'
	data.i_nrl = 30;
	data.f_nrl = 11.45f;
	data.d_nrl = 1.29995;

	//Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n Data Members Of 'struct MyData' ARE : \n\n");
	printf("i = %d\n", data.i_nrl);
	printf("f = %f\n", data.f_nrl);
	printf("d = %lf\n", data.d_nrl);

	//Calculating Sizes Of The Data Members Of 'struct MyData'
	i_size_nrl = sizeof(data.i_nrl);
	f_size_nrl = sizeof(data.f_nrl);
	d_size_nrl = sizeof(data.d_nrl);

	//Displaying Sizes Of The Data Members Of 'struct MyData'
	printf("\n\n Size Of Data Members Of 'struct MyData' ARE : \n\n");
	printf("Size of 'i' = %d bytes \n", i_size_nrl);
	printf("Size of 'f = %d bytes\n", f_size_nrl);
	printf("Size of 'd' = %d bytes\n", d_size_nrl);

	//Calculating Size Of the entire struct Mydata
	struct_MyData_size_nrl = sizeof(struct MyData); //Can also give struct name->sizeof(MyData

	//Displaying Size Of The entrire 'struct MyData'
	printf("\n\n Size of 'struct MyData' : %d bytes \n\n", struct_MyData_size_nrl);

	return(0);
}
