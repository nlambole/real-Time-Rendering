#include <stdio.h>

int main(void)
{
	//Variable Declarationns
	float num_nrl;
	float *ptr = NULL; // Declaration Method 1 :- '*ptr' is a Variable of Type 'float'

	//code
	num_nrl = 6.9f;

	printf("\n\n");

	printf("******* BEFORE ptr = &num *****\n\n");
	printf("Value Of 'num'           =%f\n\n", num_nrl);
	printf("Address Of 'num'         =%p\n\n", &num_nrl);
	printf("Value At Adress Of 'num' =%f\n\n", *(&num_nrl));


	//Assigning Adrress of Variable 'num' to pointer Variable 'ptr' 
	//'ptr' now contains address of 'num'...hence, 'ptr' is SAME a '&num'

	ptr = &num_nrl;

	printf("\n\n");

	printf(" ******** AFTER ptr = &num ******\n\n");
	printf("Value Of 'num'          =%f\n\n", num_nrl);
	printf("Adress Of 'num'         =%p\n\n", ptr);
	printf("Value At Address Of 'num'=%f\n\n", *ptr);

	return(0);


}