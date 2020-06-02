#include <stdio.h>

int main(void)
{
	//variable declarations
	int a_nrl;
	int b_nrl;
	int x_nrl;

	//code
	printf("\n\n");
	printf("Enter a_nrl Number : ");
	scanf("%d", &a_nrl);

	printf("\n\n");
	printf("Enter another Number : ");
	scanf("%d", &b_nrl);

	printf("\n\n");

	//Since, In all The Following 5 Cases, The Operand on The Left 'a_nrl' Is Getting Repeated Immeiately On The Right (e.g : a_nrl = a_nrl + b_nrl or a_nrl = a_nrl -b_nrl),
	//We are Using Compound assignment Operators +=, -=, *=, /= and %=

	//Since, 'a_nrl' Will Be assigned The Value Of (a_nrl + b_nrl) at The Expression (a_nrl += b_nrl), We Must Save The Original Value Of 'a_nrl' To another Variable (x_nrl)
	x_nrl = a_nrl;
	a_nrl += b_nrl; // a_nrl = a_nrl + b_nrl
	printf("addition Of a_nrl = %d and B = %d Gives %d.\n", x_nrl, b_nrl, a_nrl);

	//Value Of 'a_nrl' altered In The above Expression Is Used Here...
	//Since, 'a_nrl' Will Be assigned The Value Of (a_nrl - b_nrl) at The Expression (a_nrl -= b_nrl), We Must Save The Original Value Of 'a_nrl' To another Variable (x_nrl)
	x_nrl = a_nrl;
	a_nrl -= b_nrl; // a_nrl = a_nrl - b_nrl
	printf("Subtraction Of a_nrl = %d and B = %d Gives %d.\n", x_nrl, b_nrl, a_nrl);

	//Value Of 'a_nrl' altered In The above Expression Is Used Here...
	//Since, 'a_nrl' Will Be assigned The Value Of (a_nrl * b_nrl) at The Expression (a_nrl *= b_nrl), We Must Save The Original Value Of 'a_nrl' To another Variable (x_nrl)
	x_nrl = a_nrl;
	a_nrl *= b_nrl; // a_nrl = a_nrl * b_nrl
	printf("Multiplication Of a_nrl = %d and B = %d Gives %d.\n", x_nrl, b_nrl, a_nrl);

	//Value Of 'a_nrl' altered In The above Expression Is Used Here...
	//Since, 'a_nrl' Will Be assigned The Value Of (a_nrl / b_nrl) at The Expression (a_nrl /= b_nrl), We Must Save The Original Value Of 'a_nrl' To another Variable (x_nrl)
	x_nrl = a_nrl;
	a_nrl /= b_nrl; // a_nrl = a_nrl / b_nrl 
	printf("Division Of a_nrl = %d and B = %d Gives Quotient %d.\n", x_nrl, b_nrl, a_nrl);

	//Value Of 'a_nrl' altered In The above Expression Is Used Here...
	//Since, 'a_nrl' Will Be assigned The Value Of (a_nrl % b_nrl) at The Expression (a_nrl %= b_nrl), We Must Save The Original Value Of 'a_nrl' To another Variable (x_nrl)
	x_nrl = a_nrl;
	a_nrl %= b_nrl; // a_nrl = a_nrl % b_nrl
	printf("Division Of a_nrl = %d and B = %d Gives Remainder %d.\n", x_nrl, b_nrl, a_nrl);

	printf("\n\n");

	return(0);
}
