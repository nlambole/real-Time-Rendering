#include <stdio.h>
int main(void)
{
	//Variable declarations
	int a_nrl, b_nrl, p_nrl;

	//code
	a_nrl = 9;
	b_nrl = 30;
	p_nrl = 30;

	// *** First if-else PAIR ***
	printf("\n\n");
	if (a_nrl < b_nrl)
	{
		printf("Entering First if-block...\n\n");
		printf("A Is Less Than B !!!\n\n");
	}
	else
	{
		printf("Entering First else-block....\n\n");
		printf("A Is NOT Less Than B !!!\n\n");
	}
	printf("First if-else Pair Done !!!\n\n");

	// *** SECOND if-else PAIR ***
	printf("\n\n");
	if (b_nrl != p_nrl)
	{
		printf("Entering Scond if-Block...\n\n");
		printf("B Is NOT Equal To P !!!\n\n");
	}
	else
	{
		printf("Entering Second esle-block....\n\n");
		printf("B Is Equal To P !!!!\n\n");
	}
	printf("Second if-else Pair Done !!!\n\n");

	return(0);
}