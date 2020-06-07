#include <stdio.h>

int main(void)
{
	//variable declaration
	int a_nrl, b_nrl, p_nrl;

	//code 
	a_nrl = 9;
	b_nrl = 30;
	p_nrl = 30;

	printf("\n\n");

	if (a_nrl < b_nrl)
	{
		printf("A is Less than B !!!\n\n");
	}

	if (b_nrl != p_nrl)
	{
		printf("B is NOT equal to P !!!\n\n");
	}

	printf("Both Comparisons Have Been Done !!!\n\n");

	return(0);

}
