#include <stdio.h>
#include <conio.h>

int main(void)
{
	//Varaible Declaratin 
	int i_nrl, j_nrl;

	//code 
	printf("\n\n");

	for (i_nrl = 1; i_nrl <= 20; i_nrl++)
	{
		for (j_nrl = 1; j_nrl <= 20; j_nrl++)
		{
			if (j_nrl > i_nrl)
			{
				break;
			}
			else
			{
				printf("*   ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	return (0);
}