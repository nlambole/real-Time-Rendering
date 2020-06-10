#include <stdio.h> //'stdio.h' Contains declaration of 'printf()'
#include <ctype.h> //ctype.h contains declrations of 'atoi()'
#include <stdlib.h> // 'stdlib.h' contains declaration of 'exit()'

int main(int argc, char* argv[], char* envp[])
{
	//Variable Declarations
	int i_nrl;
	int num_nrl;
	int sum_nrl = 0;

	//Code
	if (argc == 1)
	{
		printf("\n\n");
		printf("No Numbes Given Addintion !!! Exitting Now....\n\n");
		printf("Usasge : CommandLineArgumentsApplication <first number> <second number> ....\n\n");
		exit(0);
	}

	// *** This Programs Add All Command Linr Arguments Given In Integer Form Only and Outputs The Sum **
	// *** Due To Use of atoi(), All Command Line arguments of Types Other Than 'int' Are Ignored ***

	printf("\n\n");
	printf("Sum Of All Integer command Line Arguments Is : \n\n");
	for (i_nrl = 1; i_nrl < argc; i_nrl++) // Loop start i=1 because , i =0 will result in 'argv[i]' = 'argv[0] which is the name of the program itself i.e. :
	{
		num_nrl = atoi(argv[i_nrl]);
		sum_nrl = sum_nrl + num_nrl;
	}

	printf("Sum = %d\n\n", sum_nrl);

	return(0);
}