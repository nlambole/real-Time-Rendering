#include <stdio.h>

int main(void)
{
	//Functions Declarations
	void SwapNumbers(int, int);

	//Variable Declarations
	int a_nrl;
	int b_nrl;

	//code
	printf("\n\n Enter Value For 'A' : ");
	scanf("%d", &a_nrl);

	printf("\n\n Enter Value For 'B' : ");
	scanf("%d", &b_nrl);

	printf("\n\n ********* BEFORE SWAPPING *********\n\n");
	printf("Value Of 'A' =%d\n\n", a_nrl);
	printf("Value Of 'B' =%d\n\n", b_nrl);

	SwapNumbers(a_nrl, b_nrl); // ******* ARGUMENTS PASSED 'BY VALUE'....****

	printf("\n\n ******** AFTER SWAPPING ********\n\n");
	printf("Value Of 'A' = %d\n\n", a_nrl);
	printf("Value Of 'B' = %d\n\n", b_nrl);

	return(0);
}

void SwapNumbers(int x, int y) // Value Of 'a' is copied into 'x' and Value Of 'b' is copied into 'y' ... swapping takes place between 'x' and 'y', not between 'a' and 'b'....
{
	//Variable Declations
	int temp_nrl;

	//code
	printf("\n\n ******** BEFORE SWAPPING *******\n\n");
	printf("vlaue Of 'X' = %d\n\n", x);
	printf("Value Of 'Y' =%d\n\n", y);

	temp_nrl = x;
	x = y;
	y = temp_nrl;

	printf("\n\n ******* AFTER SWAPPING *******\n\n");
	printf("Value Of 'X' =%d\n\n", x);
	printf("Value Of 'Y' =%d\n\n", y);


}