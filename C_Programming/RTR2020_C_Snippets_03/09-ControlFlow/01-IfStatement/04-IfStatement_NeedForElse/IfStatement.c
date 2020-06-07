#include <stdio.h>
int main(void)
{
	//Variable Declarations
	int age_nrl;

	//code
	printf("\n\n");
	printf("Enter Age : ");
	scanf("%d", &age_nrl);
	if (age_nrl >= 18)
	{
		printf("You Age Eligible For Voting !!!.\n\n");
	}
	if (age_nrl <18)
	{
		printf("You Are NOT Eligible For Voting !!!.\n\n");
	}
	return(0);
}
