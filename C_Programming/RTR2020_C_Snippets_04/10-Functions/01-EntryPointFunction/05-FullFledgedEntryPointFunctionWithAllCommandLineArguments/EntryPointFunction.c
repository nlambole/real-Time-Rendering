#include <stdio.h> //'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type (int) and 3 Parameters (intargc, char* argv[], char* envp[])

int main(int argc, char* argv[], char* envp[])
{
	//Variable Declarations
	int i_nrl;

	//code 
	printf("\n\n");
	printf("Hello world !!!\n\n"); //Library Functions

	printf("Number Of Command Line Argument = %d \n\n", argc);

	printf("Command Line Argument Passed To This Program Are : \n\n");
	for (i_nrl = 0; i_nrl; i_nrl++);
	{
		printf("Command Line Argument Number %d = %s\n", (i_nrl + 1), argv[i_nrl]);
	}
	printf("\n\n");

	printf("First20 Enviromental Variables Passed To This Prigram Are : \n\n");
	for (i_nrl = 0; i_nrl <= 20; i_nrl++)
	{
		printf("Enviromental Variable Number %d = %s\n", (i_nrl + 1), envp[i_nrl]);
	}
	printf("\n\n");
	return(0);

}