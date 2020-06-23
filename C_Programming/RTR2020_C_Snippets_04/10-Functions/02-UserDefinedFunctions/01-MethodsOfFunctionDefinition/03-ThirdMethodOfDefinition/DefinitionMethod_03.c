#include <stdio.h> // 'stdio.h' contains delclarationns of 'printf()'

// Entry-Point Funtion => main() Valid Retrun Type (int) and 3 Paratmeters (int ) argc, char *argv[], char *argv[], char *envp[])

int main(int argc, char* argv[], char* envp[])
{
	// Function Prototype / Declaration / Signature
	void MyAddition_nrl(int, int);

	// Variable Declaration : Locar Variables To Main()
	int a_nrl, b_nrl;

	//Code
	printf("\n\n");
	printf("Enter Integer Value For 'A' :	");
	scanf("%d", &a_nrl);

	printf("\n\n");
	printf("Enter Integer Value For 'B' :	");
	scanf("%d", &b_nrl);

	MyAddition_nrl(a_nrl, b_nrl); // Function Call

	return(0);


}

// ** User Defined Function : Methods Of Defination 3 ****
// ** No Return Value, Vlaid Parameters (int, int) ***

void MyAddition_nrl(int a_nrl, int b_nrl) // Function Defination 
{
	//Variable Declaration : Local Variable to MyAddition()
	int sum_nrl;

	// Code 
	sum_nrl = a_nrl + b_nrl;
	printf("\n\n");
	printf("Sum Of %d And %d = %d \n\n", a_nrl, b_nrl, sum_nrl);

}

