#include <stdio.h>

int main(void)
{
	//Variable Declarations

	int num_nrl;
	int *ptr = NULL;
	int *copy_ptr = NULL;

	//code
	num_nrl = 5;
	ptr = &num_nrl;

	printf("\n\n *************** BEFORE copy_ptr = ptr*************\n\n");
	printf("num           =%d\n", num_nrl);
	printf("&num			=%p\n", &num_nrl);
	printf(" *(&num)      =%d\n", *(&num_nrl));
	printf(" ptr          =%p\n", ptr);
	printf(" *ptr         %d\n", *ptr);


	// 'ptr' is an integer pointer variable....that it it can hold the address of any integer variable only
	//'copy_ptr' is another integer pointer variable 
	//If ptr = &num ....'ptr' will contain address of integer variable 'num' 
	//If 'ptr' is Assigned to 'copy_ptr', 'copy_ptr' will also contains address of integer variable 'num' 
	//Hence, Now both 'ptr' and 'copy_ptr' will point to 'num'....

	copy_ptr = ptr; // copy_ptr = ptr =&num

	printf("\n\n *************** AFTER copy_ptr = ptr ***********\n\n");
	printf("  num           =%d\n", num_nrl);
	printf(" &num           =%p\n", &num_nrl);
	printf("  *(&num)       =%d\n", *(&num_nrl));
	printf(" ptr            =%p\n", ptr);
	printf(" *ptr           =%d\n", *ptr);

	printf("  copy_ptr      =%p\n", copy_ptr);
	printf(" *copy_ptr      =%d\n", *copy_ptr);

	return(0);
}