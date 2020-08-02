#include <stdio.h>	
#include <stdarg.h>

int main(void)
{
	//Functions
	int CalculateSum_nrl(int, ...);

	//Variable Decalrations
	int answer_nrl;

	//Code
	printf("\n\n");

	answer_nrl = CalculateSum_nrl(5, 10, 20, 30, 40, 50);
	printf("Answer = %d\n\n", answer_nrl);

	answer_nrl = CalculateSum_nrl(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	printf("answer_nrl = %d\n\n", answer_nrl);

	answer_nrl = CalculateSum_nrl(0);
	printf("Answer = %d\n\n", answer_nrl);

	return(0);

}

int CalculateSum_nrl(int num, ...) //Variadic Functions
{
	//Variable Declarations
	int sum_total_nrl = 0;
	int n_nrl;

	va_list numbers_list_nrl;

	//Code
	va_start(numbers_list_nrl, num);

	while (num)
	{
		n_nrl = va_arg(numbers_list_nrl, int);
		sum_total_nrl = sum_total_nrl + n_nrl;
		num--;
	}
	va_end(numbers_list_nrl);
	return(sum_total_nrl);
}

