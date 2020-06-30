#include <stdio.h>

int main(void)
{
	//Functions Declaration
	void SwapNumbers(int*, int*);

	//Variable Declarations
	int a_nrl;
	int b_nrl;


	//Code
	printf("\n\n Enter vlaue For 'A' : ");
	scanf("%d", &a_nrl);

	printf("\n\n Enter Value For 'B' : ");
	scanf("%d", &b_nrl);

	printf("\n\n ********** BEFORE SWAPPING ********\n\n");
	printf("Value Of 'A' =%d\n\n", a_nrl);
	printf("Value Of 'B' =%d\n\n", b_nrl);

	SwapNumbers(&a_nrl, &b_nrl); // ******* ARGUMENTS PASSED 'BY REFFERENCE / ADDRESS'.... ********

	printf("\n\n ********** AFTER SWAPPING *********\n\n");
	printf("vlaue Of 'A' =%d\n\n", a_nrl);
	printf("value Of 'B' =%d\n\n", b_nrl);

	return(0);

}

// Address Of 'a' is copied int 'x' and Address of 'b' is copied into 'y' .... So, '&a' and 'x' are pointing to ONE and the SAME address and '&b' and 'y' are pointing to ONE and the SAME address...
// Swapping takes place between 'value at address of x (value at &a i.e. : 'a') and 'Value At Address of Y' (Value at &b) ....
// Hence, Swapping in this case takes place between '*x' and '*y' and '*y' AS WELL AS BETWEEN 'a' and 'b'...

void SwapNumbers(int *x, int* y)
{
	//Variable Declarations
	int temp;

	//code
	printf("\n\n ******* BEFORE SWAPPING *****\n\n");
	printf("Value Of 'X' =%d\n\n", *x);
	printf("Value Of 'Y' =%d\n\n", *y);

	temp = *x;
	*x = *y;
	*y = temp;

	printf("\n\n ******** AFTER SWAPPING ******\n\n		");
	printf("Value Of 'X' =%d\n\n", *x);
	printf("Value Of 'Y' =%d\n\n", *y);
	

}