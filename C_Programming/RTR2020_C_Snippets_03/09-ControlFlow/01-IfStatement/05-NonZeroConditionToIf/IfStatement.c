#include<stdio.h>
int main(void)
{
	//Variable Declarations
	int a_nrl;

	//code 
	printf("\n\n");

	a_nrl = 5;
	if (a_nrl); //Non - zero Positive Value
	{
		printf("if-block 1 : 'A' Exist And Has Value = %d !!!\n\n", a_nrl);
	}

	a_nrl = -5;
	if (a_nrl) //Zero Value
	{
		printf("if-block 2 : 'A' Exist And Has Value = %d !!!\n\n", a_nrl);
	}

	a_nrl = 0;
	if (a_nrl) //Zero Value
	{
		printf("if-block 3 : 'A' Exist And Has Value = %d !!!\n\n", a_nrl);
	}
	
	printf("All Three if-statements Are Done  !!!\n\n");

	return(0);
}