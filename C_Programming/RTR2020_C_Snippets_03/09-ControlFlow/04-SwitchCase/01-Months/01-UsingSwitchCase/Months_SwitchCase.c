#include<stdio.h>
int main(void)
{
	//Variable declarations
	int num_month_nrl;

	//code
	printf("\n\n");

	printf("Enter Number Of Month (1 to 12 ): ");
	scanf("%d", &num_month_nrl);

	printf("\n\n");
	switch (num_month_nrl)
	{
	case 1 : //like 'if'
		printf("Month Number %d Is JANUARY !!!\n\n", num_month_nrl);
		break;
	
	case 2: //like 'else if'
		printf("Month Number %d Is FEBRUARY !!!\n\n", num_month_nrl);
		break;

	case 3: //like 'else if'
		printf("Month Number %d Is MARCH !!!\n\n", num_month_nrl);
		break;

	case 4: //like 'else if'
		printf("Month Number %d Is APRIL !!!\n\n", num_month_nrl);
		break;

	case 5: //like 'else if'
		printf("Month Number %d Is  MAY !!!\n\n", num_month_nrl);
		break;

	case 6: //like 'else if'
		printf("Month Number %d Is JUN !!!\n\n", num_month_nrl);
		break;

	case 7: //like 'else if '
		printf("Month Number %d Is JULY !!!\n\n", num_month_nrl);
		break;

	case 8: //like 'else if'
		printf("Month Number %d Is AUGUST !!!\n\n", num_month_nrl);
		break;

	case 9: //like 'else if'
		printf("Month Number %d Is SEPTEMBER !!!\n\n", num_month_nrl);
		break;

	case 10: //like 'else if '
		printf("Month Number %d Is OCTOBER !!!\n\n", num_month_nrl);
		break;

	case 11: //like 'else if'
		printf("Month Number %d Is NOVEMBER !!!\n\n", num_month_nrl);
		break;

	case 12: //like 'else if'
		printf("Month Number %d Is DECMBER !!!\n\n", num_month_nrl);
		break;

	default : //like ending OPTIONAL 'else'...just like terminating 'else' is optional in if - else if - else ladder, so is the 'default' case optional in switch - case
		printf("Invalid Month Number %d Entered !!! Please Try Again...\n\n", num_month_nrl);
		break;
	}
	printf("Switch Case Block Complete !!!\n\n");
	return(0);
}