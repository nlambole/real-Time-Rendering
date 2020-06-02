#include <stdio.h>

int main(void)
{
	//variable declarations
	int a_nrl = 5;
	int b_nrl = 10;

	//code
	printf("\n\n");
	printf("A = %d\n", a_nrl);
	printf("A = %d\n", a_nrl++);
	printf("A = %d\n", a_nrl);
	printf("A = %d\n\n", ++a_nrl);

	printf("B = %d\n", b_nrl);
	printf("B = %d\n", b_nrl--);
	printf("B = %d\n", b_nrl);
	printf("B = %d\n\n", --b_nrl);

	return(0);
}
