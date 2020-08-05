#include <stdio.h>
#include <conio.h>	

struct MyData
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
	char ch_nrl;

};

int main(void)
{
	//Variable Declarations
	struct MyData data; //Declarations a single struct variable 

	//Code
	// User Input For Values Of Data Members Of 'struct MyData'
	printf("\n\n Enter Integer Value For Data Member 'i' of 'struct MyData' :\n");
	scanf("%d", &data.i_nrl);

	printf("Enter Floating-Point Value For Data Member 'f' of 'struct MyData'\n");
	scanf("%f", &data.f_nrl);

	printf("Enter 'Double ' Value For Datra Member 'd' of 'struct MyData' : \n");
	scanf("%lf", &data.d_nrl);

	printf("Enter  Character Value FFor Data Member 'c' Of 'sturct MyData' : \n\n");
	data.ch_nrl = getch();

	//Display Value Of Data Members Of 'struct MyData'
	printf("\n\n Data Members of 'struct Mydata' ARE : \n\n");
	printf("i =%d\n", data.i_nrl);
	printf("f = %f\n", data.f_nrl);
	printf("d = %lf\n", data.d_nrl);
	printf("c = %c\n", data.ch_nrl);

	return(0);
}
