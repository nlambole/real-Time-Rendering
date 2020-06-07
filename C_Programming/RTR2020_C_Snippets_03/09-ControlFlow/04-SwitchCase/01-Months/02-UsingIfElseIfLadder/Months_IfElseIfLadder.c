#include <stdio.h>
int main(void)
{
	//Variable declarations
	int num_month_nrl;

	//code 
	printf("\n\n");

	printf("Enter Number Of Month (1 to 12 : ");
	scanf("%d", &num_month_nrl);

	//If - Else - If Ladder Begins From Here...
	if (num_month_nrl == 1) //like 'case 1'
		printf("Month Number %d Is JANUARY !!!\n\n", num_month_nrl);

	else if (num_month_nrl == 2) //like 'case 2'
		printf("Month Number %d Is FEBRUARY !!!\n\n", num_month_nrl);

	else if (num_month_nrl == 3) //like 'case 3'
		printf("Month Number %d Is MARCH !!!\n\n", num_month_nrl);

	else if (num_month_nrl == 4) //like 'case 4'
		printf("Month Number %d Is APRIL !!!\n\n", num_month_nrl);

	else if (num_month_nrl == 5) //like 'case 5'
		printf("Month Number %d Is MAY !!!\n\n", num_month_nrl);

	else if (num_month_nrl == 6) //like 'case 6'
		printf("Month Number %d Is JUN !!!\n\n", num_month_nrl);

	else if (num_month_nrl == 7) //like 'case 7'
		printf("Month Number %d Is JULY !!!", num_month_nrl);

	else if (num_month_nrl == 8) //like 'case 8'
		printf("Month Number %d Is AUGUST !!!\n\n", num_month_nrl);

	else if (num_month_nrl == 9) //like 'case 9'
		printf("Month Number %d Is SEPTEMBER !!!\n\n", num_month_nrl);

	else if (num_month_nrl == 10) //like 'case 10'
		printf("Month Number %d Is OCTOBER !!!\n\n", num_month_nrl);

	else if (num_month_nrl == 11)// like 'case 11'
		printf("Month Number %d Is NOVEMBER !!!\n\n", num_month_nrl);

	else if (num_month_nrl == 12) //like 'case 12'
		printf("Month Number %d Is DECEMBER !!!\n\n", num_month_nrl);

	else //like default...just like 'default' is optional in switch, so is 'else' in the if-else the if-else ladder...

		printf("Invalid Month Number %d Entered !!! Please Try Again...\n\n", num_month_nrl);

	printf("If - Else _ Else Ladder Complete !!!\n\n");
	return(0);


}