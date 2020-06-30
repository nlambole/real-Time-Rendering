#include <stdio.h>

int main(void)
{
	//Variable Declarations
	int num_nrl;
	int* ptr = NULL; // Declarations Method 2 :- 'ptr ' is a Variable of Type 'int*'

	//code
	num_nrl = 10;

	printf("\n\n");

	printf("\n ******** BEFORE ptr =&num ********\n\n");
	printf("Value Of 'num' =%d\n\n", num_nrl);
	printf("Address Of 'num' =%p\n\n", &num_nrl);
	printf("Value At Address Of 'num'=%d\n\n", num_nrl);


	//Asssigning Address of Variable 'num' o pointer variable 'ptr'
	//'ptr' now contains address of 'num'...hence, 'ptr' is SAME as '&num'

	ptr = &num_nrl;

	printf("\n\n");

	printf(" ******* AFTER ptr = &num *******\n\n");

	printf("Value Of 'num' =%d\n\n", num_nrl);
	printf("Adress Of 'num'=%p\n\n", ptr);
	printf("Value At Address Of 'num' =%d\n\n", *ptr);

	return(0);
}