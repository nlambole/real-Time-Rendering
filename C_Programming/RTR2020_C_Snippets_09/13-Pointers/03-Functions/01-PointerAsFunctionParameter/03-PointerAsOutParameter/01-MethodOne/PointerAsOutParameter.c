#include <stdio.h>

int main(void)

{
	//Functions Declarations
	void MathematicalOperations(int, int, int*, int*, int*, int*, int*);

	//Variable Declarations
	int a_nrl;
	int b_nrl;
	int answer_sum_nrl;
	int answer_difference_nrl;
	int answer_product_nrl;
	int answer_quotient_nrl;
	int answer_remainder_nrl;

	//Code
	printf("\n\n Enter Value Of 'A' : ");
	scanf("%d", &a_nrl);

	printf("\n\n Enter Value Of 'B' : ");
	scanf("%d", &b_nrl);

	// PASSING ADDRESS TO FUNCTION....FUNCTION WILL FILL THEM UP WITH VALUE....Hence, They, Go Into The Functions As Address Parametrs and COME Out OF The Functions FILLED WITH Values

	//THUS, (&answer_sum, &answer_diffrenece, &answer_product, &answer_quotient, &answer_remainder) ARE CALLED 'OUT PARAMETRS' OR PARAMETERIZED RETURN VALUE" ...RETURN VALUES OF FUNCTIONS COMING VIA PARAMETERS .
	//HENCE, ALTHOUGH EACH FUNCTION HAS ONLY ONE RETURN VALUE, USING THE CONCEPT HAS GIVEN US 5 RETURN VALUE", OUR FUNCTION 'MathecalOperations()" HAS GIVEN US 5 RETURN Values !!!

	MathematicalOperations(a_nrl, b_nrl, &answer_sum_nrl, &answer_difference_nrl, &answer_product_nrl, &answer_quotient_nrl, &answer_remainder_nrl);

	printf("\n\n ******** RESULT ******* \n\n");
	printf("Sum =%d\n\n	", answer_sum_nrl);
	printf("Difference =%d\n\n", answer_product_nrl);
	printf("Product = %d\n\n", answer_quotient_nrl);
	printf("Remainder = %\n\n", answer_remainder_nrl);

	return(0);

}

void MathematicalOperations(int x, int y, int* sum, int* difference, int* product, int* quotient, int* remainder)
{
	*sum = x + y; //Value at address 'sum' = (x + y)
	*difference = x - y; //value at Address 'difference' = (x -y)
	*product = x * y; //Value at Addresss 'priduct' = (x *y)
	*quotient = x / y; //Value At Address 'quotient' = (x /y)
	*remainder = x % y; // Value at Address 'Remainder' = (x % y)
}