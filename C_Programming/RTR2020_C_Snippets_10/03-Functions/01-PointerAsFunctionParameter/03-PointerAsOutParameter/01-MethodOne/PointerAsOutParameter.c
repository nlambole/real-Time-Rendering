#include <stdio.h>

int main(void)
{
	//function Declarations
	void MathematicalOperations(int, int, int*, int*, int*, int*, int*);

	//Variable Declarations
	int a_nrl;
	int b_nrl;
	int answer_sum_nrl;
	int answer_difference_nrl;
	int answer_product_nrl;
	int answer_quotient_nrl;
	int answer_remainder_nrl;

	//code
	printf("\n\n Enter Value Of 'A' : ");
	scanf("%d", &a_nrl);

	printf("\n\n Enter Value Of 'B' : ");
	scanf("%d", &b_nrl);

	// PASSING ADDRESSES TO FUNCTION ... FUNCTION WILL FILL THEM UP WITH VALUES ... HENCE, THEY GO INTO THE FUNCTION AS ADDRESS PARAMETERS AND COME OUT OF THE FUNCTION FILLED WITH VALID VALUES
	// THUS, (&answer_sum, &answer_difference, &answer_product, & answer_quotient, & answer_remainder) ARE CALLED "OUT PARAMETERS" OR "PARAMETERIZED RETURN VALUES" ... RETURN VALUES OF FUNCTIONS COMING VIA PARAMETERS
	// HENCE, ALTHOUGH EACH FUNCTION HAS ONLY ONE RETURN VALUE, USING THE CONCEPT OF "PARAMETERIZED RETURN VALUES", OUR FUNCTION "MathematicalOperations()" HAS GIVEN US 5 RETURN VALUES !!!

	MathematicalOperations(a_nrl, b_nrl, &answer_sum_nrl, &answer_difference_nrl, &answer_product_nrl, &answer_quotient_nrl, &answer_remainder_nrl);

	printf("\n\n ********** RESULTs ******** : \n\n");
	printf("Sum = %d\n\n ", answer_sum_nrl);
	printf("Difference = %d\n\n", answer_difference_nrl);
	printf("Product = %d\n\n", answer_product_nrl);
	printf("Quotient = %d\n\n", answer_quotient_nrl);
	printf("Remainder = %d\n\n", answer_remainder_nrl);
	return(0);
}

void MathematicalOperations(int x_nrl, int y_nrl, int* sum_nrl, int* difference_nrl, int* product_nrl, int* quotient_nrl, int* remainder_nrl)
{
	//code
	*sum_nrl = x_nrl + y_nrl;	//Value at Address sum= (x + y);
	*difference_nrl = x_nrl - y_nrl;	// Value at address 'difference' = (x - y
	*product_nrl = x_nrl * y_nrl;	// Value at address 'product' = (x * y)
	*quotient_nrl = x_nrl / y_nrl; // Value At Address Quotient = x/y
	*remainder_nrl = x_nrl % y_nrl; //Value At Address 'remainder' = (x % y);

}
