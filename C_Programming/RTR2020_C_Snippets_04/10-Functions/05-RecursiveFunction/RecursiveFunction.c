//
//  RecursiveFunction.c
//
// Created y AstroMediComp on 31/05/2020

#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	// Variable Declarations
	unsigned int num_nrl;

	// Function Prototypes
	void recursive(unsigned int);

	// code
	printf("\n\n Enter ANy Number : \n\n ");
	scanf("%u", &num_nrl);

	printf("\n\n Output Of Recursive Function : \n\n");

	recursive(num_nrl);

	printf("\n\n");

	return(0);
}

void recursive(unsigned int n_nrl)
{
	// code
	printf("n = %d \n", n_nrl);

	if (n_nrl > 0)
	{
		recursive(n_nrl - 1);
	}
}
