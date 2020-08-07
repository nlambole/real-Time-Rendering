#include <stdio.h>

struct MyStruct
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
	char c_nrl;
};

union MyUnion
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
	char c_nrl;
};

int main(void)
{
	//Varaible Declarations
	struct MyStruct s_nrl;
	union MyUnion u_nrl;
	
	//Code
	printf("\n\n Size of MyStruct = %lu\n", sizeof(s_nrl));
	printf("\n\n Size of MyUnion = %lu\n", sizeof(u_nrl));

	return(0);
}