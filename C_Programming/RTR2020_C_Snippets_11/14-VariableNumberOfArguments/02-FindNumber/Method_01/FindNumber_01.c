#include <stdio.h>
#include <stdarg.h>	

#define NUM_TO_BE_FOUND 3
#define NUM_ELEMENTS 10


int main(void)
{
	//Functions Prototypes
	void FindNumber(int, int, ...);

	//Code
	printf("\n\n");

	FindNumber(NUM_TO_BE_FOUND, NUM_ELEMENTS, 3, 5, 9, 2, 3, 6, 9, 3, 1, 3);

	return(0);

}

void FindNumber(int num_to_be_found, int num, ...)//Variadic Functions
{
	//Variable Declarations
	int count_nrl = 0;
	int n_nrl;
	va_list numbers_list;

	//Code
	va_start(numbers_list, num);

	while (num)
	{		
		n_nrl = va_arg(numbers_list, int);
		if (n_nrl == num_to_be_found)
			count_nrl++;
		num--;
	}
	
	if (count_nrl == 0)
		printf("Number %d Could Not Be Found !!!\n\n", num_to_be_found);
	else
		printf("Number %d Found %d Times !!!\n\n", num_to_be_found, count_nrl);

	va_end(numbers_list);
}

