#include <stdio.h>
#include<string.h> // for strrev()

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Variables Declarations 
	char chArray_Original_nrl[MAX_STRING_LENGTH]; // A Character Array Is A String 

	// Code

	// *** STRING INPUT ****

	printf("\n\n Enter A String : \n\n");
	gets_s(chArray_Original_nrl, MAX_STRING_LENGTH);

	// *** STRING LENGTH ***
	printf("\n\n The Original String Entered By You (i.e. : 'chArray_Original[]') Is :  \n\n");
	printf("%s\n", chArray_Original_nrl);

	printf("\n\n The Reversed String (i.e. : 'chArray_Reverse[]') Is : \n\n");
	printf("%s\n", strrev(chArray_Original_nrl));

	return(0);

}