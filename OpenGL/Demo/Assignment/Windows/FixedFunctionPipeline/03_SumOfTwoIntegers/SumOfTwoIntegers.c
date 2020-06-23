#include <stdio.h>

int main(void)
{
	int SumOfTwoIntegers(int, int);

	//Variable  Declarations

	int num1, num2, num3;

	//code

	num1 = 75;
	num2 = 25;
	num3 = SumOfTwoIntegers(num1, num2);

	printf("%d\n\n", num3);

	printf("%d\n\n", SumOfTwoIntegers(175, 125));

	SumOfTwoIntegers(275, 225);

	return(0);
}

int SumOfTwoIntegers(int a, int b)
{
	int Sum;
	
	Sum = a + b;

	printf("%d \n\n", Sum);

	return(0);
}