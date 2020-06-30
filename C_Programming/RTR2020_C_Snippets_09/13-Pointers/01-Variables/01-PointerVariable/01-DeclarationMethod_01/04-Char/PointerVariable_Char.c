#include <stdio.h>	

int main(void)
{
	//Variable Declarations
	char ch_nrl;
	char *ptr = NULL;

	//code
	ch_nrl = 'N';

	printf("\n\n******* BFORE ptr = &ch********\n\n");
	
	printf("Value of 'ch' =%c\n\n", ch_nrl);
	printf("Address of 'ch' = %p\n\n", &ch_nrl);
	printf("Value of 'ch' =%c\n\n", *(&ch_nrl));

	//Assignning Adreess of variable 'ch' to pointer variable 'ptr'
	//'ptr' now contains address of 'ch' ...hence, 'ptr' is SAME as '&ch'

	ptr = &ch_nrl;

	printf("\n\n ******** AFTER ptr = &ch *******\n\n");

	printf("Value of 'ch' =%c\n\n", ch_nrl);
	printf("Address of 'ch' =%p\n\n	", ptr);
	printf("Value of 'ch' =%c\n\n", *(ptr));


	return(0);
}