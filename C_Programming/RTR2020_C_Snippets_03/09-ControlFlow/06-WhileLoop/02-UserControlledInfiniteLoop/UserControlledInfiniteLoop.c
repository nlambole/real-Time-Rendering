#include <stdio.h>
int main(void)
{
	//Variable Declarations
	char option_nrl, ch_nrl = '\0';

	//code
	printf("\n\n");
	printf("Once The Infinite Loop Begins, Enter 'Q' or 'q' To Quit The Infinite For Loop : \n\n");
	printf("Enter 'Y' or 'y' To Initiate User Contrilled Infinite Loop : ");
	printf("\n\n");
	option_nrl = getch();
	if (option_nrl == 'Y' || option_nrl == 'y')
	{
		while (1) //Infinite LOop
		{
			printf("In Looop...\n");
			ch_nrl = getch();
			if (ch_nrl == 'Q' || ch_nrl == 'q')
				break; // User Controlled Existing From Infinite Loop
		}

		printf("\n\n");
		printf("Exiting User Controlled Infinite Loop...");
		printf("\n\n");
	}
	else
		printf("You Must Press 'Y' or 'y' To Initiate Use controlled Infinite Loop...Please Try Again...\n\n");

	return(0);
}