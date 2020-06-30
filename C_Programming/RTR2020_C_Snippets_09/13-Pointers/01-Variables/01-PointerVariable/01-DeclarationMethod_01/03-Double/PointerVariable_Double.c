#include <stdio.h>	

int main(void)
{
	//Variable Declarations
	double num_nrl;
	double* ptr = NULL; //Declarations Method 1 :- '*ptr' is a variable of type 'double'

	//code
	num_nrl = 2.34343434f;

	printf("\n\n");

	printf(" ******* BEDORE ptr = &num ********\n\n");
	printf("Value Of 'num'           =%f\n\n", num_nrl);
	printf("Address Of 'num'         =%p\n\n", &num_nrl);
	printf("Value At Address Of 'num'=%lf\n\n", *(&num_nrl));

	//Assigning address of variable 'num' to pointer variable 'ptr'
	//'ptr' now conatains address of 'num'....hence, 'ptr' is as '&num'

	ptr = &num_nrl;

	printf("\n\n");

	printf(" ******* After ptr = &num*****\n\n");
	printf("Value Of 'num' = %lf\n\n", num_nrl);
	printf("Address Of 'num' =%p\n\n", ptr);
	printf("Value At Address Of 'num' =%lf\n\n", *ptr);

	return(0);
}