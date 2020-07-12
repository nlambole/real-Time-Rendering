#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//Function Declarations
	void MathematicalOperations(int, int, int*, int*, int*, int*, int*);

	//Variable Declarations
	int a_nrl;
	int b_nrl;
	int* answer_sum_nrl = NULL;
	int* answer_difference_nrl = NULL;
	int* answer_product_nrl = NULL;
	int* answer_quotient_nrl = NULL;
	int* answer_remainder_nrl = NULL;

	//code
	printf("\n\n Enter Value Of 'A' :" );
	scanf("%d", &a_nrl);

	printf("Enter Value 'B' : ");
	scanf("%d", &b_nrl);

	// PASSING ADDRESSES TO FUNCTION ... FUNCTION WILL FILL THEM UP WITH VALUES ... HENCE, THEY GO INTO THE FUNCTION AS ADDRESS PARAMETERS AND COME OUT OF THE FUNCTION FILLED WITH VALID VALUES
	// THUS, (&answer_sum, &answer_difference, &answer_product, & answer_quotient, & answer_remainder) ARE CALLED "OUT PARAMETERS" OR "PARAMETERIZED RETURN VALUES" ... RETURN VALUES OF FUNCTIONS COMING VIA PARAMETERS
	// HENCE, ALTHOUGH EACH FUNCTION HAS ONLY ONE RETURN VALUE, USING THE CONCEPT OF "PARAMETERIZED RETURN VALUES", OUR FUNCTION "MathematicalOperations()" HAS GIVEN US 5 RETURN VALUES !!!

	answer_sum_nrl = (int*)malloc(1 * sizeof(int));
	if (answer_sum_nrl == NULL)
	{
		printf("Coult Not Allocate Memory For 'answer_diffenece'. Exitting Now..\n\n");
		exit(0);
	}

	answer_difference_nrl = (int*)malloc(1 * sizeof(int));
	if (answer_difference_nrl == NULL)
	{
		printf("Coult Not Allocate Memory For 'answer_diffenece'. Exitting Now..\n\n");
		exit(0);
	}

	answer_product_nrl = (int*)malloc(1 * sizeof(int));
	if (answer_product_nrl == NULL)
	{	
		printf("Coulf Not Allocate Memory For 'answer_product'. Exitting Now...\n\n");
		exit(0);
	}

	answer_quotient_nrl = (int*)malloc(1 * sizeof(int));
	if (answer_quotient_nrl == NULL)
	{
		printf("Could Not Allocate Memory For 'amswer_remainder'. Exiting Now..\n\n");
		exit(0);
	}

	answer_remainder_nrl = (int*)malloc(1 * sizeof(int));
	if (answer_remainder_nrl == NULL)
	{
		printf("Could Not Allocate Memory For 'answer_remaider'. Exitting Now..\n\n");
		exit(0);

	}

	MathematicalOperations(a_nrl, b_nrl, answer_sum_nrl, answer_difference_nrl, answer_product_nrl, answer_quotient_nrl, answer_remainder_nrl);

	printf("\n\n *********RESULT *******\n\n");
	printf("Sum =%d\n\n", *answer_sum_nrl);
	printf("Difference = %d\n\n", *answer_difference_nrl);
	printf("Product = %d\n\n", *answer_product_nrl);
	printf("Quotient = %d\n\n", *answer_quotient_nrl);
	printf("Remainder = %d\n\n", *answer_remainder_nrl);

	if (answer_remainder_nrl)
	{
		free(answer_remainder_nrl);
		answer_remainder_nrl = NULL;
		printf("Memory Allocated For 'answer_remainder' Successfully Freed !!!\n\n");
	}

	
	if (answer_quotient_nrl)
	{
		free(answer_quotient_nrl);
		answer_quotient_nrl = NULL;
		printf("Memoty Allocated For 'answer_quotient' Successfully Freed !!! \n\n");
	}

	if (answer_product_nrl)
	{
		free(answer_product_nrl);
		answer_product_nrl = NULL;
		printf("Memory Allocated For 'answer_product' Successfully Freed !!!\n");
	}

	if (answer_difference_nrl)
	{
		free(answer_difference_nrl);
		answer_difference_nrl = NULL;
		printf("Memory Allocated For 'answer_difference' !!!\n");
	}
	if (answer_sum_nrl)
	{
		free(answer_sum_nrl);
		answer_sum_nrl = NULL;
		printf("Memory Allocated For 'answer_sum' Successfully Freed !!!\n\n");
	}

	return(0);
}

void MathematicalOperations(int x_nrl, int y_nrl, int* sum_nrl, int* difference_nrl, int* product_nrl, int* quotient_nrl, int* remainder_nrl)
{
	//code
	*sum_nrl = x_nrl + y_nrl;
	*difference_nrl = x_nrl - y_nrl;
	*product_nrl = x_nrl * y_nrl;
	*quotient_nrl = x_nrl / y_nrl;
	*remainder_nrl = x_nrl % y_nrl;

}
