#include <stdio.h>

int main(void)
{
	//Variable Declarations
	char ch_nrl;
	char* ptr = NULL; //Declaration Method 2:- 'ptr' is a variable of type 'char'

	//code
	ch_nrl = 'A';

	printf("********* BEFORE ptr = &ch *******");

	printf("Value Of 'ch' =%c\n\n", ch_nrl);
	printf("Address Of 'ch' = %p\n\n", &ch_nrl);
	printf("Vlaue At Address Of 'ch' =%c\n\n", *(&ch_nrl));


	//Assigning Address Of Variable 'ch' to pointer variable 'ptr'
	//'ptr' now contains address of 'ch'....hence, 'ptr' is Same as '&ch'

	ptr = &ch_nrl;

	printf("\n\n ********* After ptr =&num *********\n\n");
	printf("Value Of 'ch' =%c\n\n	", ch_nrl);
	printf("Address Of 'ch' =%p\n\n", ptr);
	printf("Valur At Address 'ch' =%c\n\n", *ptr);

	return(0);

}