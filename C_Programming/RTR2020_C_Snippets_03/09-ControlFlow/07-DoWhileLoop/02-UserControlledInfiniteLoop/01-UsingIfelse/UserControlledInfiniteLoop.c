#include <stdio.h>
int main(void)
{
	//Variable Declaration
	char option_nrl, ch_nrl = '\0';

	//code
	printf("\n\n");

	printf("Once The Infinite Loop Begins, Enter 'Q' or 'q' To Quit The Infinite For Loop : \n\n");
	printf("Enter 'Y' or 'y' To Initiate User Controlled Infinite Loop : ");
	printf("\n\n");

	option_nrl = getch();
	if (option_nrl == 'Y' || option_nrl == 'y')
	{
	do
	{
		printf("In Loop...\n\n");
		ch_nrl = getch(); // Control Flow waits For Character Inputs...
		if (ch_nrl == 'Q' || ch_nrl == 'q')
		break; //User Controlled Existing Form Infinite Loop..
	} while (1); // Infinite Loop

	printf("\n\n");
	printf("Existing User Controlled Infinite Looop...");
	printf("\n\n");
	}
	else
		printf("You Must Press 'Y' or 'y' To Indicate The User Controlled Infinite Loop...Please Try Again..\n\n");
	return(0);
}