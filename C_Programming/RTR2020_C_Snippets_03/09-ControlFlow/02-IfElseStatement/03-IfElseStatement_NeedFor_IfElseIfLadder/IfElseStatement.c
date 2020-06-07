#include<stdio.h>
int main(void)
{
	//Variable Declarations
	int num_nrl;

	//code
	printf("\n\n");

	printf("Enter Value For 'num' : ");
	scanf("%d", &num_nrl);

	if (num_nrl < 0) //'if' - 01
	{
		printf("Num = %d Is Less Than 0 (NEGATIVE) !!!\n\n", num_nrl);
	}
	else //'else' - 01
	{
		if ((num_nrl > 0) && (num_nrl <= 100)) // 'if' - 02
		{
			printf("Num %d Is Between 0 And 100 !!!\n\n", num_nrl);
		}
		else // 'else' - 02
		{
			if ((num_nrl > 100) && (num_nrl <= 200)) // 'if' - 03
			{
				printf("Num = %d Is Between 100 And 200 !!!\n\n", num_nrl);
			}
			else // 'else' - 03 
			{
				if ((num_nrl > 200) && (num_nrl <= 300)) // 'if' - 04
				{
					printf("Num = %d Is Between 200 And 300 !!!\n\n", num_nrl);
				}
				else // 'else' - 04
				{
					if ((num_nrl > 300) && (num_nrl <= 400)) //'if' - 05
					{
						printf("Num = %d Is Between 300 And 400 !!!\n\n", num_nrl);

					}
					else //'else' - 05
					{
						if ((num_nrl > 400) && (num_nrl <= 500)) // 'if' - 06
						{
							printf("Num = %d Is Between 400 And 500 !!!\n\n", num_nrl);
						}
						else // 'else' - 06
						{
							printf("Num = %d Is Greater Than 500 !!!\n\n", num_nrl);
						} //Closing brace of 'else' - 06
					}//Closing brace of 'else' - 05

				}//Closing brace of 'else' - 04
			}//Closing brace of 'else' - 03
		}//Closing brace of 'else' - 02
	}//Closing brace of 'else' - 01

	return (0);
}