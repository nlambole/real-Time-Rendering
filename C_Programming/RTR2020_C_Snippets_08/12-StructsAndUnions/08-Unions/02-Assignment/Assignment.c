#include <stdio.h>	

union MyUnion
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
	char c_nrl;

};

int main(void)
{
	//Variable Declarations
	union MyUnion u1_nrl, u2_nrl;

	//Code
	// *** MyUnion u2 ***
	printf("\n\n Members Of union u1 Are : \n\n");

	u1_nrl.i_nrl = 6;
	u1_nrl.f_nrl = 1.2f;
	u1_nrl.d_nrl = 8.33333;
	u1_nrl.c_nrl = 'S';

	printf("u1.i = %d\n\n", u1_nrl.i_nrl);
	printf("u1.f = %f\n\n", u1_nrl.f_nrl);
	printf("u1.d = %lf\n\n", u1_nrl.d_nrl);
	printf("u1.c = %c\n\n", u1_nrl.c_nrl);

	printf("Addresses Of Members Of Union u1 ARE : \n\n");
	printf("u1.i = %p\n\n", &u1_nrl.i_nrl);
	printf("u1.f = %p\n\n", &u1_nrl.f_nrl);
	printf("u1.d = %p\n\n	", &u1_nrl.d_nrl);
	printf("u1.c = %p\n\n", &u1_nrl.c_nrl);

	printf("MyUnions u1 = %p\n\n", &u1_nrl);

	// *** MyUnion u2 ****
	printf("\n\n Members of Unions u2 Are : \n\n");

	u2_nrl.i_nrl = 3;
	printf("u2.i = %d\n\n", u2_nrl.i_nrl);

	u2_nrl.f_nrl = 4.5f;
	printf("u2.i = %f\n\n", u2_nrl.f_nrl);

	u2_nrl.d_nrl = 5.12764;
	printf("u2.d = %lf\n\n", u2_nrl.d_nrl);

	u2_nrl.c_nrl = 'A';
	printf("u2.c = %c\n\n", u2_nrl.c_nrl);

	printf("Address Of Members Of Unions u2 Are : \n\n");
	printf("u2.i = %p\n\n", &u2_nrl.i_nrl);
	printf("u2.f = %p\n\n", &u2_nrl.f_nrl);
	printf("u2.d = %p\n\n", &u2_nrl.d_nrl);
	printf("u2.c = %p\n\n", &u2_nrl.c_nrl);

	printf("MyUnion u2 = %p\n\n		", &u2_nrl);

	return(0);

}