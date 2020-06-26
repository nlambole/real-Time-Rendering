#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Functions Prototypes
	void MyStrcpy(char[], char[]);

	// Variable Declarations
	char chArray_Original_nrl[MAX_STRING_LENGTH], chArray_Copy_nrl[MAX_STRING_LENGTH]; // A Character Array Is A String.

	//code

	// *** STRING INPUT ****
	printf("\n\n Enter A String : \n\n");
	gets_s(chArray_Original_nrl, MAX_STRING_LENGTH);

	// *** STRING COPY ***
	MyStrcpy(chArray_Copy_nrl, chArray_Original_nrl);

	// *** STRING OUTPUT ****
	
	printf("\n\n The Original String Entered By You (i. e. : 'chArray_Original[]') Is : \n\n");
	printf("%s\n", chArray_Original_nrl);

	printf("\n\n The Copied String (i.e. : 'chArray_Copy[]' Is : \n\n");
	printf("%s\n", chArray_Copy_nrl);

	return(0);
	
}

void MyStrcpy(char str_destination[], char str_source[])
{
	// Function Prototypes
	int MyStrlen(char[]);

	// Variables Declarations
	int iStringLength = 0;
	int j_nrl;

	//Code
	iStringLength = MyStrlen(str_source);
	for (j_nrl = 0; j_nrl < iStringLength; j_nrl++)
		str_destination[j_nrl] = str_source[j_nrl];

	str_destination[j_nrl] = '\0';
}

int MyStrlen(char str[])
{
	//Variable Declarationss
	int j_nrl;
	int string_length_nrl = 0;

	// Code
	// *** Determing Exact Length Of The String, By Detecting The FIRST OCCURENCE OF NULL TERMINATING CHARACTER (\0) ***

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;

		else
			string_length_nrl++;

	}

	return(string_length_nrl);
}