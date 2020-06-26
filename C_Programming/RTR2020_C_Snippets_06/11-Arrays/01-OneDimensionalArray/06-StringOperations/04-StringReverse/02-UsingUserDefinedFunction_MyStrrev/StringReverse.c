#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Functions Prototype
	void MyStrrev(char[], char[]);

	// Variables Declarations
	char chArray_Original_nrl[MAX_STRING_LENGTH], chArray_Reversed_nrl[MAX_STRING_LENGTH]; // A CHaracter Array Is A STRING

	//code

	// *** STRING INPUT ****
	printf("\n\n Enter A String : \n\n");
	gets_s(chArray_Original_nrl, MAX_STRING_LENGTH);

	// **** STRING REVERSE ****
	MyStrrev(chArray_Reversed_nrl, chArray_Original_nrl);

	// *** STRING OUTPUT ***
	printf("\n\n The Original String Entered By You (i. e. : 'chArray_Reversed[]') Is : \n\n");
	printf("%s\n", chArray_Original_nrl);

	printf("\n\n The Reveresed String (i. e. : 'chArray_Reversed[]') Is : \n\n");
	printf("%s\n", chArray_Reversed_nrl);

	return(0);
}

void MyStrrev(char str_destination[], char str_source[])
{
	// Function Prototypes
	int MyStrlen(char[]);

	// Variable Declarations
	int iStringLength = 0;
	int i_nrl, j_nrl, len_nrl;

	//code
	iStringLength = MyStrlen(str_source);

	// Array Indices Begin From 0, Hence, Last Index Will Always Be (Length - 1)
	len_nrl = iStringLength - 1;

	// We Need To Put The Character Which Is At Last Index Of 'str_source' To The First Index Of Of 'st_destination'
	// And Second-Last Character Of 'str_source' To The Second Character (\0) ***
	for (i_nrl = 0,j_nrl = len_nrl; i_nrl < iStringLength, j_nrl >= 0; i_nrl++, j_nrl--)
	{
		str_destination[i_nrl] = str_source[j_nrl];
	}

	str_destination[i_nrl] = '\0';

}

int MyStrlen(char str[])
{
	// Variable Declarations
	int j_nrl;
	int string_length_nrl = 0;

	// CODE
	// *** Determining Exact Length Of The String, By Detecting The First Occurence Of Null-Terminating Character (\0) ***

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;

		else
			string_length_nrl++;
	}

	return(string_length_nrl);
}
