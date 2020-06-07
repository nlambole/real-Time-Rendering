#include <stdio.h>
#include <stdio.h>
int main(void)
{
	//Variable Declaration 

	int i_nrl;
	char ch_nrl;

	//code 
	printf("\n\n");

	printf("Printing Even Numbers From 1 to 100 For Every User Input. Exixting the Loop when User Enters Character 'Q' or 'q' : \n\n");
	printf("Enter Character 'Q' or 'q' To Exit Loop : \n\n");


	for (i_nrl = 1; i_nrl <= 100; i_nrl++)
	{
		printf("\t%d\n", i_nrl);
		ch_nrl = getch();
		if (ch_nrl == 'Q' || ch_nrl == 'q')
		{
			break;
		}
	}

	printf("\n\n");
	printf("Existing Loop...");
	printf("\n\n");

	return(0);
}