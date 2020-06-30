#include <stdio.h>

int main(void)
{
	// Variable Declarations
	float num_nrl;
	float* ptr = NULL; //Declarations Method 2 :- 'ptr' is a variable of type 'float*'


	//code
	num_nrl = 6.9f;

	printf("\n\n");


	printf(" ******** BEFORE ptr =&num ***********\n\n");
	printf("Value Of 'num' =%f\n\n", num_nrl);
	printf("Address Of 'num' =%p\n\n", &num_nrl);
	printf("Vlaue At Address Of 'num' =%f\n\n", *(&num_nrl));

	//Assingning Address OF Variable 'num' to pointer variable 'ptr' 
	//'ptr'now contians address of 'num'...hence 'ptr' is SAME as '&num'

	ptr = &num_nrl;

	printf("\n\n");

	printf(" ********* AFTER ptr =&num *******\n\n");

	printf("Value Of 'num' =%f\n\n", num_nrl);
	printf("Address Of 'num' =%p\n\n", ptr);
	printf("Value At Address Of 'num' =%f\n\n", *(ptr));

	return(0);
}