#include <stdio.h> //for printf()
#include <conio.h> //for getch()

int main(void)
{
	//Variable Declarations
	int a_nrl, b_nrl;
	int result_nrl;

	char option_nrl;
	char option_division_nrl;

	//code
	printf("\n\n");

	printf("Enter Value For 'A' : ");
	scanf("%d", &a_nrl);

	printf("Enter Vlaue For 'B' : ");
	scanf("%d", &b_nrl);

	printf("Enter Option In Character : \n\n");
	printf("'A' or 'a' For Addition : \n\n0");
	printf("'S' or  's' For Substraction : \n\n");
	printf("'M' or 'm' For Multiplication : \n\n");
	printf("'D' or 'd' For Division : \n\n");

	printf("Enter Option : ");
	option_nrl = getch();

	printf("\n\n");

	if (option_nrl == 'A' || option_nrl == 'a')
	{
		result_nrl = a_nrl + b_nrl;
		printf("Addition Of A = %d And B = %d Gives Result %d !!!\n\n", a_nrl, b_nrl, result_nrl);
	}
	else if (option_nrl == 'S' || option_nrl == 's')
	{
		if (a_nrl >= b_nrl)
		{
			result_nrl = a_nrl - b_nrl;
			printf("Substraction Of B = %d From A = %d Gives Result %d !!!\n\n", b_nrl, a_nrl, result_nrl);
		}
		else
		{
			result_nrl = b_nrl - a_nrl;
			printf("Substraction of A=%d From B= %d Gives Result % !!!\n\n", a_nrl, b_nrl, result_nrl);
		}
	}
	else if (option_nrl == 'M' || option_nrl == 'm')
	{
		result_nrl = a_nrl * b_nrl;
		printf("Multiplication Of A = %d And B=%d Gives Result %d !!!\n\n", a_nrl, b_nrl, result_nrl);
	}
	else if (option_nrl == 'D' || option_nrl == 'd')
	{
		printf("Enter Option In Character : \n\n");
		printf("'Q' or 'q' or '/' For Quotient Upon Division : \n");
		printf("'R' or 'r' or '%%' For Remainder Upon Division : \n");

		printf("Enter Option : ");
		option_division_nrl = getch();

		printf("\n\n");

		if (option_division_nrl == 'Q' || option_division_nrl == 'q' || option_division_nrl == '/')
		{
			if (a_nrl >= b_nrl)
			{
				result_nrl = a_nrl / b_nrl;
				printf("Division Of A = %d By B= %d Gives Quotient = %d !!!\n\n", a_nrl, b_nrl, result_nrl);
			}
			else
			{
				result_nrl = b_nrl / a_nrl;
				printf("Division Of A = %d By B = %d Gives Quotient = %d !!!\n\n", b_nrl, a_nrl, result_nrl);
			}
		}
		else if (option_division_nrl == 'R' || option_division_nrl == 'r' || option_division_nrl == '%')
		{
			if (a_nrl >= b_nrl)
			{
				result_nrl = a_nrl % b_nrl;
				printf("Division Of A = %d By B= %d Gives Remainder + %d !!!\n\n", a_nrl, b_nrl, result_nrl);
			}
			else
			{
				result_nrl = b_nrl % a_nrl;
				printf("Division Of B = %d By A=%d Gives Remainder = %d !!!\n\n", b_nrl, a_nrl, result_nrl);
			}
		}
		else
			printf("Invalid Character %c Entered For Division !!! Please Try Again... \n\n ", option_division_nrl);
		printf("If - Else If - Else Ladder Complete !!!\n");

		return(0);
	}
}