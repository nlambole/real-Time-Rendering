#include <stdio.h>
int main(void)
{
	//Variable Declarations
	char option_nrl, ch_nrl = '\0';

	//code 
	printf("\n\n");
	printf("Once The Infinite Loop Begins, Enter 'Q' or 'q' To Quite The Infinite For Loop : \n\n");

	do
	{
		do
		{
			printf("\n");
			printf("In Loop..\n	");
			ch_nrl = getch(); //Control Flow Waits For Character Input..
		} while (ch_nrl != 'Q' && ch_nrl != 'q');
		printf("\n\n");
		printf("Existing User Controlled Infinite Loop...");

		printf("\n\n");
		printf("Do You Want To Begin User Controlled Infinite Loop Again ? \t (Y/y Yes, Any Other Key - No");
		option_nrl = getch();

	} while (option_nrl == 'Y' || option_nrl == 'y');

	return (0);
}