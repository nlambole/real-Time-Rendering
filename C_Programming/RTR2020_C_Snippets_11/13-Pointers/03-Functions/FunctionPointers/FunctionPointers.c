#include <stdio.h>	

int main(void)
{
	//Functions Declaration
	int AddIntegers(int, int);
	int SubtractIntegers(int, int);
	float AddFloats(float, float);

	//Varaible Declarations
	typedef int (*AddIntsFnPtr)(int, int);
	AddIntsFnPtr ptrAddTwoIntegers_nrl = NULL;
	AddIntsFnPtr ptrFunc = NULL;

	typedef float(*AddFloatsFnPtr)(float, float);
	AddFloatsFnPtr ptrAddTwoFloats_nrl = NULL;

	int iAnswer_nrl = 0;
	float fAnswer_nrl = 0.0f;

	//Code
	ptrAddTwoIntegers_nrl = AddIntegers;
	iAnswer_nrl = ptrAddTwoIntegers_nrl(9, 30);
	printf("\n\n Sum Of Integers = %d\n\n ", iAnswer_nrl);

	ptrFunc = SubtractIntegers;
	iAnswer_nrl = ptrFunc(9, 30);
	printf("\n\n Substraction Of Integers = %d\n\n ", iAnswer_nrl);

	ptrAddTwoFloats_nrl = AddFloats;
	fAnswer_nrl = ptrAddTwoFloats_nrl(11.45f, 8.2f);
	printf("\n\n Sum Of Floating-Point Numbers = %f\n\n", fAnswer_nrl);

	return(0);

}

int AddIntegers(int a_nrl, int b_nrl)
{
	//Variable Declarations
	int c_nrl;

	//Code
	c_nrl = a_nrl + b_nrl;
	return(c_nrl);

}

int SubtractIntegers(int a_nrl, int b_nrl)
{
	//Variable Declarations
	int c_nrl;

	//Code
	if (a_nrl > b_nrl)
	{
		c_nrl = a_nrl - b_nrl;
	}
	else
	{
		c_nrl = a_nrl - b_nrl;
	}
	return(c_nrl);
}

float AddFloats(float f_num1, float f_num2)
{
	//Variable Declarations
	float ans_nrl;

	//Code
	ans_nrl = f_num1 + f_num2;

	return(0);

}
