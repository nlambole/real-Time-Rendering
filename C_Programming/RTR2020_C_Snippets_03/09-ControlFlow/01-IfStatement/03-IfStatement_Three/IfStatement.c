#include <stdio.h>

int main(void)
{
	//Variable Declaration
	int num_nrl;

	//code 
	printf("\n\n");

	printf("Enter Value For 'num_nrl' : ");
	scanf("%d", &num_nrl);

	if (num_nrl < 0)
	{
		printf("Num = %d Is Less Than 0 (NEGATIVE). \n\n", num_nrl);
	}

	if ((num_nrl > 0) && (num_nrl <= 100))
	{
		printf("Num = %d Is Between 0 And 100 \n\n", num_nrl);
	}

	if ((num_nrl > 100) && (num_nrl <= 200))
	{
		printf("Num = %d Is Between 100 And 200. \n\n", num_nrl);
	}
	if ((num_nrl > 200) && (num_nrl <= 300))
	{
		printf("Num = %d Is Between 200 And 300. \n\n", num_nrl);
	}
	if ((num_nrl > 300) && (num_nrl <= 400))
	{
		printf("Num =%d Is Between 300 And 400. \n\n", num_nrl);
	}
	if ((num_nrl > 400) && (num_nrl <= 500))
	{
		printf("Num = %d Is Between 400 And 500. \n\n", num_nrl);
	}

	if (num_nrl > 500)
	{
		printf("Num = %d Is Greater Than 500. \n\n", num_nrl);
	}

	return(0);
}