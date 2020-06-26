#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Variable Declarations 
	char chArray_nrl[MAX_STRING_LENGTH]; // A Character Array Is A String 

	// Code
	printf("\n\n Enter A String : \n\n");
		gets_s(chArray_nrl, MAX_STRING_LENGTH);

	printf("\n\n String Entered By You Is : \n\n");
	printf("%s \n", chArray_nrl);
	return(0);
}