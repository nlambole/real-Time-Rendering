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
	//Variable Declararations
	struct MyStruct s_nrl;
	union MyUnion u_nrl;

	//Code
	printf("\n\n Members Of Struct Are : \n\n");

	s_nrl.i_nrl = 9;
	s_nrl.f_nrl = 8.7f;
	s_nrl.d_nrl = 1.2334;
	s_nrl.c_nrl = 'P';

	printf("s.i = %d\n\n", s_nrl.i_nrl);
	printf("s.f = %f\n\n", s_nrl.d_nrl);
	printf("s.d = %lf\n\n", s_nrl.d_nrl);
	printf("s.c = %c\n\n", s_nrl.c_nrl);

	printf("Adderessess Of Members Of Struct ARE : \n\n");
	printf("s.i = %p\n\n", &s_nrl.i_nrl);
	printf("s.d = %p\n\n", &s_nrl.d_nrl);
	printf("s.c = %p\n\n", &s_nrl.c_nrl);

	printf("MyStruct s = %p\n\n", &s_nrl);

	printf("\n\n Members Of Union Are : \n\n");

	u_nrl.i_nrl = 3;
	printf("u.i = %d\n\n", u_nrl.i_nrl);

	u_nrl.f_nrl = 4.5f;
	printf("u.f =%f\n\n", u_nrl.f_nrl);

	u_nrl.d_nrl = 5.12764;
	printf("u.d =%lf\n\n", u_nrl.d_nrl);

	u_nrl.c_nrl = 'A';
	printf("u.c = %c \n\n", u_nrl.c_nrl);

	printf("Addressess Of Members Of Union ARE : \n\n");
	printf("u.i = %p\n\n", &u_nrl.i_nrl);
	printf("u.f = %p\n\n", &u_nrl.f_nrl);
	printf("u.d = %p\n\n", &u_nrl.d_nrl);
	printf("u.c = %p\n\n", &u_nrl.c_nrl);

	printf("MyUnion u = %p\n\n", &u_nrl);

	return(0);
}
