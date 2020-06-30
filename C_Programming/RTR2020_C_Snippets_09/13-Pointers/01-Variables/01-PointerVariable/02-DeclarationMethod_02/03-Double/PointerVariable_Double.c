#include <stdio.h>

int main(void)
{
	//Variable Declarations
	double num_nrl;
	double* ptr = NULL; //Declarations Method 2:- 'ptr' is a Variable of Type 'double'
	
	//code
	num_nrl = 2.343434343343f;

	printf("\n\n");

	printf("******* BEFORE ptr = &num ***********\n\n");

	printf("Value of 'num' =%lf\n\n	", num_nrl);
	printf("Address Of 'num'=%p\n\n", &num_nrl);
	printf("Value At Address Of 'num' =%lf\n\n", *(&num_nrl));

	// Assigning Address of Variable 'num' to pointer varaible  'ptr'
	//'ptr' now contains address of 'num' ....hence, 'ptr' is SAME as '&num'

	ptr = &num_nrl;

	printf("******** AFTER ptr = &num ********\n\n");
	printf("Value Of 'num' =%lf\n\n", num_nrl);
	printf("Address Of 'num' =%p\n\n", ptr);
	printf("Value At Address Of 'num' = %lf\n\n", *ptr);

	return(0);

}