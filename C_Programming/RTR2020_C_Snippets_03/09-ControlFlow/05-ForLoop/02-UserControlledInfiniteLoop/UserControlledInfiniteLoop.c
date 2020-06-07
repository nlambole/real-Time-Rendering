#include <stdio.h>

int main(void)
{
	//Varaible Declarations
	char option_nrl, ch_nrl = '\0';

	//code 
	printf("\n\n");
	printf("once The Infinite Loop Begins, Enter 'Q' or 'q' To Quit the Infinite For Loop : \n\n");
	printf("Enter 'Y' or 'y' To Infinite User Controlled Infinite Loop : ");
	printf("\n\n");
	option_nrl = getch();

	if (option_nrl == 'Y' || option_nrl == 'y')
	{
		for (;;) //Infinite Looop
		{
			printf("In Looop...\n");
			ch_nrl = getch();
			if (ch_nrl == 'Q' || ch_nrl == 'q')
				break; //User Controlled Existing From Infinite Loop
		}
	}

	printf("\n\n");
	printf("Existing User Controlled Infinite Lopp...");

	return(0);
}