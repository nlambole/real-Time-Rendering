#include<stdio.h>
int main(void)
{
	//Variable Declarations
	int age_nrl;

	//code
	printf("\n\n");
	printf("Enter Age : ");
	scanf("%d", &age_nrl);
	printf("\n\n");

	if (age_nrl >= 18)
	{
		printf("Entering if-block...\n\n");
		printf("You Are Eligible For Voting !!!\n\n");
	}
	else
	{
		printf("Entering else-block....\n\n");
		printf("You Are NOT Eligible For Voting !!!\n\n");
	}
	printf("Bye !!!\n\n");
	return(0);

}