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

int CalculateSum_nrl(int num, ...) //Varidiac Functions
{
	//Functions Prototype
	int va_CalculateSum_nrl(int, va_list);

	//Variable Declarations
	int sum_nrl = 0;
	va_list numbbers_list;

	//code
	va_start(numbbers_list, num);

	sum_nrl = va_CalculateSum_nrl(num,  numbbers_list);

	va_end(numbbers_list);
	return(sum_nrl);

}

int va_CalculateSum_nrl(int num, va_list list) 
{
	//Variable Declarations
	int n_nrl;
	int sum_total_nrl = 0;

	//Code
	while (num)
	{
		n_nrl = va_arg(list, int);
		sum_total_nrl = sum_total_nrl + n_nrl;
		num--;
	}

	return(sum_total_nrl);
}

