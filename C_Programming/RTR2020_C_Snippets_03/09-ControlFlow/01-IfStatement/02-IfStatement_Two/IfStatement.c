#include <stdio.h>

int main(void)
{
	//Variable Declaration
	int age_nrl;

	//code
	printf("\n\n");
	printf("Enter age : ");
	scanf("%d", &age_nrl);

	if (age_nrl >= 18 )
	{
		printf("You Are Eligible For Voting !!!!\n\n");
	}

	else
	{
		printf("You Are not Eligible For Voting !!!!\n\n");
	}
	return(0);
}