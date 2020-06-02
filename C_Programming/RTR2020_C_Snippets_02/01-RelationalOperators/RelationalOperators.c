#include <stdio.h>
int main(void)
{
	//variable declarations
	int a_nrl;
	int b_nrl;
	int result;
	//code
	printf("\n\n");
	printf("Enter One Integer : ");
	scanf("%d", &a_nrl);
	printf("\n\n");
	printf("Enter Another Integer : ");
	scanf("%d", &b_nrl);
	printf("\n\n");
	printf("If Answer = 0, It Is 'FALSE'.\n");
	printf("If Answer = 1, It Is 'TRUE'.\n\n");
	result = (a_nrl < b_nrl);
	printf("(a_nrl < b_nrl) A = %d Is Less Than B = %d \t Answer = %d\n",
		a_nrl, b_nrl, result);
	result = (a_nrl > b_nrl);
	printf("(a > b_nrl) A = %d Is Greater Than B = %d \t Answer = %d\n",
		a_nrl, b_nrl, result);
	result = (a_nrl <= b_nrl);
	printf("(a <= b_nrl) A = %d Is Less Than Or Equal To B = %d \t Answer = %d\n",
		a_nrl, b_nrl, result);
	result = (a_nrl >= b_nrl);
	printf("(a_nrl >= b_nrl) A = %d Is Greater Than Or Equal To B = %d \t Answer = %d\n",
		a_nrl, b_nrl, result);
	result = (a_nrl == b_nrl);
	printf("(a_nrl == b_nrl) A = %d Is Equal To B = %d \t Answer = %d\n",
		a_nrl, b_nrl, result);
	result = (a_nrl != b_nrl);
	printf("(a_nrl != b_nrl) A = %d Is NOT Equal To B = %d \t Answer = %d\n",
		a_nrl, b_nrl, result);
	return(0);
}