#include <stdio.h> //'stdio.h' Contains Declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type (int) and 3 Prameters (int) argc, char * argv[], char *envp[])

int main(int argc, char* argv[], char* envp[])
{
	//Function Prototype / declaration / signature 
	int MyAddition_nrl(void);

	// Variable Declaration : Locar Variable to main()
	int result_nrl;

	// Code
	result_nrl = MyAddition_nrl(); // Function Call 

	printf("\n\n");
	printf("Sum = %d\n\n", result_nrl);
	return(0);

}


// *** User Defined Function : Method Of Definition 2 ***
// ** Valid (int) Return Value, No Parameters

int MyAddition_nrl(void) //Function Defination
{
	//Variable Declaration : Local Variable to MyAddition_nrl()
	int a_nrl, b_nrl, sum_nrl;

	// Code
	printf("\n\n");
	printf("Enter Integer Value For 'A' : ");
	scanf("%d", &a_nrl);

	printf("\n\n");
	printf("Enter Integer Value For 'B' : ");
	scanf("%d", &b_nrl);

	sum_nrl = a_nrl + b_nrl;

	return(sum_nrl);
}

