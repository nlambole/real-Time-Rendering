#include <stdio.h> //'stdio.h' contains declaration of 'printf()'

//Entry-Point Function => main() => Valid Return Type (int argc , char *argv[])

int main(int argc, char* argv[])
{
	//Variable Declaration 
	int i_nrl;

	//Code 
	printf("\n\n");
	printf("Hello World !!!\n\n"); //Library Function
	printf("Number Of Command Line arguments = %d \n\n", argc);
	for (i_nrl = 0; i_nrl <= argc; i_nrl++)
	{
		printf("Command Line Argument number %d = %s \n", (i_nrl + 1), argv[i_nrl]);
	}
	printf("\n\n");
	return(0);
}


