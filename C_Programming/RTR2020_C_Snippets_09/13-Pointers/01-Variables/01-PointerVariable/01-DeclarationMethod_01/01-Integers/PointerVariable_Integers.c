#include <stdio.h>

int main(void)
{
	// Variable Declarations
	int num_nrl;
	int *ptr = NULL; // Declarations Method 1 :- *ptr is variable of type 'int' 

	//code
	num_nrl = 10;

	printf("\n\n ");

	printf(" ****** Before ptr = &num *********\n\n");
	printf("Value Of 'num'             =%d\n\n", num_nrl);
	printf("Address Of 'num'           =%p\n\n", &num_nrl);
	printf("Vlaue At Address Of 'num' = %d\n\n", *(&num_nrl));


	//Assigning Adreess of Variable 'num' to pinter variable 'ptr'
	// 'ptr' now contains adress of 'num' ....hence, 'ptr' is SAME as '&num' 

	ptr = &num_nrl;

	printf(" ******* After ptr = &num ******\n\n");
	printf("Value Of 'num '            =%d\n\n", num_nrl);
	printf("Adress Of 'num'            =%p\n\n", ptr);
	printf("Vlaue At Adreess Of 'num'  = %d\n\n", *ptr);

	return(0);

}