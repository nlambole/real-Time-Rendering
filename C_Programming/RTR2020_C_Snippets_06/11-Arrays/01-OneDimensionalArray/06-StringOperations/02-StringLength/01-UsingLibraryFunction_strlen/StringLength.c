#include<stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Variable Declarations
	char chArray_nrl[MAX_STRING_LENGTH]; // A Character Array Is A String 

	int iStringLength_nrl = 0;

	// Code

	// **** STRING INPUT ****

	printf("\n\n Enter A String : \n\n");
	gets_s(chArray_nrl, MAX_STRING_LENGTH);

	// *** STRING OUTPUT ****
	printf("\n\n String Entered By YouUs : \n\n");
	printf("%s \n", chArray_nrl);

	// *** STRING LENGTH ***
	printf("\n\n ");
	iStringLength_nrl = strlen(chArray_nrl);
	printf("Length Of String Is = %d Characters !!!\n\n", iStringLength_nrl);

	return(0);
}