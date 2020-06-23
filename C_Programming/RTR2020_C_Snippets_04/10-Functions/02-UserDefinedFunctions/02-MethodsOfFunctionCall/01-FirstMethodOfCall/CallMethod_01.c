#include <stdio.h> // 'stdio.h' Contains Declaration of 'printf()'

// ** User Defined Function = Method Of Calling Function 1 ***
// ** Claling All Function In main() Directly ****

//Entry-Point Function => main() => Vlid Return Type (int) and 3 Parameters (int argc, char *argv[], int *envp[])

int main(int argc, char *argv[], char *envp[])
{
	// Function Prototypes or Declarations
	void MyAddition(void);
	int MySubstraction(void);
	void MyMultiplication(int, int);
	int MyDivision(int, int);

	//Variable Declaraions
	int result_substraction_nrl;
	int a_multiplication_nrl, b_multiplication_nrl;
	int a_division_nrl, b_division_nrl, result_division_nrl;

	// Code

	// *** ADDITION ****
	MyAddition(); ///Function Call

	// *** SUBSTRACTION ***
	result_substraction_nrl = MySubstraction(); // Function Call
	printf("\n\n");
	printf("Substraction Yields Result = %d \n\n", result_substraction_nrl);

	// *** MULTIPLICATION ***
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Multiplication : ");
	scanf("%d", &a_multiplication_nrl);

	printf("\n\n");
	printf("Enter Integer Valsue For 'B' For Multiplicarion : ");
	scanf("%d", &b_multiplication_nrl);

	MyMultiplication(a_multiplication_nrl, b_multiplication_nrl); //Function Call

	// ** DIVISION **
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Division : ");
	scanf("%d", &a_division_nrl);

	printf("\n\n");
	printf("Enter Integer Vlaue For 'B' For Division : ");
	scanf("%d", &b_division_nrl);

	result_division_nrl = MyDivision(a_division_nrl, b_division_nrl); // Function Call
	printf("\n\n");
	printf("Division Of %d and %d Gives %d (Quotient) \n", a_division_nrl, b_division_nrl, result_division_nrl);

	printf("\n\n");

	return(0);

}

// *** Function Definition Of MyAddition() ****

void MyAddition(void) //Function Definantion
{
	//Variable Declaration : Local Variables To MyAddition()
	int a_nrl, b_nrl, sum_nrl;

	// Code 
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Addition :	");
	scanf("%d", &a_nrl);

	printf("\n\n");
	printf("Enter Integer Value For 'B' For Addition : ");
	scanf("%d", &b_nrl);


	sum_nrl = a_nrl + b_nrl;

	printf("\n\n");
	printf("Sum Of %d And %d = %d \n\n", a_nrl, b_nrl, sum_nrl);

}

// *** Function Definition Of MySubtraction() ******
int MySubstraction(void) //function definition
{
	//variable declarations : local variables to MySubtraction()
	int a_nrl, b_nrl, subtraction;
	//code
	printf("\n\n");
	printf("Enter Integer Value For 'A' For Subtraction : ");
	scanf("%d", &a_nrl);
	printf("\n\n");
	printf("Enter Integer Value For 'B' For Subtraction : ");
	scanf("%d", &b_nrl);
	subtraction = a_nrl - b_nrl;
	return(subtraction);
}

// *** Function Defination Of MyMultiplication() ****
void MyMultiplication(int a_nrl, int b_nrl) // Function Definition
{
	//Variable Declaration : local Variables to MyMultiplication()

	int multiplication;

	//Code
	multiplication = a_nrl * b_nrl;

	printf("\n\n Multiplication Of %d And %d = %d \n\n", a_nrl, b_nrl, multiplication);

}

//** Function Definition Of MyDivision() ****
int MyDivision(int a_nrl, int b_nrl) //Funnction Declaration
{
	//Variable Declaration : Local Variables to MyDivivsion()
	int division_quotient;

	//code
	if (a_nrl > b_nrl)
		division_quotient = a_nrl / b_nrl;
	else
		division_quotient = b_nrl / a_nrl;
	return(division_quotient);
}
