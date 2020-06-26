#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Variable Declarations
	char chArray_Original_nrl[MAX_STRING_LENGTH], chArray_copy_nrl[MAX_STRING_LENGTH]; // A Character Array Ins A String
	
	// code
	
	// *** STRING INPUT ***

	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_Original_nrl, MAX_STRING_LENGTH);

	// *** STRING COPY ***
	strcpy(chArray_Original_nrl, chArray_Original_nrl);

	// **** STRING OUTPUT ***
	printf("\n\n The Original String Entred By You (i.e : 'chArray_Original[[]') Is : \n\n");
	printf("%s \n", chArray_Original_nrl);

	printf("\n\n The Copied String (i. e. : 'chArray_Copy[]' Is : \n\n	");
	printf("%s\n", chArray_Original_nrl);

	return(0);

}