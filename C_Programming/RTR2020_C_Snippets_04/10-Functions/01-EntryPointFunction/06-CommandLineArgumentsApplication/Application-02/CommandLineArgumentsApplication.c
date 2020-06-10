#include <stdio.h> //'stdio.h' contains declarartion of 'printf()'
#include <stdlib.h> //'stdlib' contains declaration of 'exit()

int main(int argc, char* argv[], char* envp[])
{
	//Variable Declarations
	int i_nrl;

	//COde
	if (argc != 4) //Program name + first name + middle name + surname = 4 command line arguments are required
	{
		printf("\n\n");
		printf("Invalid Usage !!! Exiting Now..\n\n");
		printf("Usage : CommandLineArgumwntsApplication <first name> <middle name> <surname>\n\n");
		exit(0);

	}

	// ** this programs Prtints Your Full Nae As Entered In The Command Line Arguments  ***
	printf("\n\n");
	printf("Your Full Name Is : ");
	for (i_nrl = 1; i_nrl <= argc; i_nrl++) //loop starts from i = 1 will result in 'argv[i] = argv[i] Which is the name of the program itself i. e. 'CommandLineArgumentsApplication.exe
	{
		printf("%s", argv[i_nrl]);

	}
	printf("\n\n");

	return(0);
}