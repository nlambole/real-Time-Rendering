#include <stdio.h>

int main(void)
{
	//variable declarations
	int a_nrl;
	int b_nrl;
	int result;

	//code
	printf("\n\n");
	printf("Enter A Number : ");
	scanf("%d", &a_nrl);

	printf("\n\n");
	printf("Enter Another Number : ");
	scanf("%d", &b_nrl);

	printf("\n\n");

	// *** The Following Are The 5 Arithmetic Operators +, -, *, / and % ***
	// *** Also, The Resultants Of The Arithmetic Operations In All The Below Five Cases Have Been Assigned To The Variable 'result' Using the Assignment Operator (=) ***
	result = a_nrl + b_nrl;
	printf("Addition Of A = %d And B = %d Gives %d.\n", a_nrl, b_nrl, result);

	result = a_nrl - b_nrl;
	printf("Subtraction Of A = %d And B = %d Gives %d.\n", a_nrl, b_nrl, result);

	result = a_nrl * b_nrl;
	printf("Multiplication Of A = %d And B = %d Gives %d.\n", a_nrl, b_nrl, result);

	result = a_nrl / b_nrl;
	printf("Division Of A = %d And B = %d Gives Quotient %d.\n", a_nrl, b_nrl, result);

	result = a_nrl % b_nrl;
	printf("Division Of A = %d And B = %d Gives Remainder %d.\n", a_nrl, b_nrl, result);

	printf("\n\n");

	return(0);
}
