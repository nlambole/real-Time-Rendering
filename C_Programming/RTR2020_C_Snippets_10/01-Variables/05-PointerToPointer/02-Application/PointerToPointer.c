#include <stdio.h>

int main(void)
{
	//Variable Declartions
	int num_nrl;
	int* ptr = NULL;
	int** pptr = NULL; //Declarations Method 1:- **pptr Is A Variable O Type 'int'

	//Code
	num_nrl = 10;

	printf("\n\n ******** BEFORE ptr = &num *********\n\n");
	printf("Value Of 'num'            =%d\n\n", num_nrl);
	printf("Address Of 'num'          =%p\n\n", &num_nrl);
	printf("Value At Address Of 'num' =%d\n\n", *(&num_nrl));

	//Assigning Address of Variable 'num' to pointer varaible 'ptr'
	//'ptr' now contains address of 'num' ....hence , 'ptr' is SAME '&num'
	ptr = &num_nrl;

	printf("\n\n ******** AFTER ptr =&num *******\n\n");
	printf("Value Of 'num'            =%d\n\n", num_nrl);
	printf("Address Of 'num'          =%p\n\n", ptr);
	printf("Value At Address Of 'num' =%d\n\n", *ptr);

	// Assigning address of variable 'ptr' to poointer-to-pointer variable 'pptr' 
	// 'pptr' now contains the address of 'ptr' which in turn contains the address of 'num'

	//Hence, 'pptr' is SAME as '&ptr'
	//'ptr' is SAME as '&num' 
	//Hence, pptr = &ptr = &(&num)
	//If ptr =&num and *ptr = *(num) = value at address of 'num'
	//Then, pptr =&ptr and *pptr = *(&ptr) =ptr = Value at address of 'ptr' i.e. 'ptr' i.e. : address of 'num'
	//Then, **ptr = **(&ptr) = *(*(&ptr)) = *ptr =*(&num) = num = 10
	//Hence, num = *(&num) == *(ptr = *(*pptr) = **pptr

	pptr = &ptr;

	printf("\n\n ******* AFTER pptr = &ptr ******\n\n");
	printf("Vlaue Of 'num'                  =%d\n\n", num_nrl);
	printf("Address Of 'num' (ptr)          =%p\n\n", ptr);
	printf("Address Of 'ptr' (pptr)         =%p\n\n", pptr);
	printf("Value At Address Of 'ptr' (*pptr) =%p\n\n", *pptr);
	printf("Value At Address Of 'num' (*ptr) (*pptr)=%d\n\n", **pptr);

	return(0);



}