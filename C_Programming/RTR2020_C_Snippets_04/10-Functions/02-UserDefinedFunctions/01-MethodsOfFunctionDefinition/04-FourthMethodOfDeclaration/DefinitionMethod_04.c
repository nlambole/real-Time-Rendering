#include <stdio.h> // 'stdio.h' Contains Declaration of 'printf()'

// ENtry_Point Function = > main() => Valid Return Type (int) and 3 Parametrs (int argc, char *argc, char *argv, char *envp)

int main(int argc, char* argv[], char* envp[])
{
	// Function Prototype / Declaration / Signature
	int MyAddition_nrl(int, int);

	// Variable Declaration : Lcar Variable To main()
	int a_nrl, b_nrl, result_nrl;

	//code
	printf("\n\n");
	printf("Enter Integer Value  For 'A' : ");
	scanf("%d", &a_nrl);

	printf("\n\n");
	printf("Enter Integer Value For 'B' : ");
	scanf("%d", &b_nrl);

	result_nrl = MyAddition_nrl(a_nrl, b_nrl); // Function Call
	printf("\n\n");
	printf("Sun of %d And %d = %d\n\n", a_nrl, b_nrl, result_nrl);

	return(0);
}

/// *** User Defined Function : Method Of Defination **
// *** Valid (int) Return Value , Vlaid Parameters (int =, int)

int MyAddition_nrl(int a_nrl, int b_nrl)
{
	// Variable Declaration : Local Variable to MyAdditon()
	int sum_nrl;

	// Code
	sum_nrl = a_nrl + b_nrl;

	return(sum_nrl	);
}
