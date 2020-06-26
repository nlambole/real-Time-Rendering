// *** This Program Replaces ALL Vowels In The Input String With The * (asterisk) SYMBOL ***
// *** For Example, Original String 'Dr. Vijay Dattatray Gokhale ASTROMEDICOMP' Will Become 'Dr. V*j*y D*tt*tr*y G*kh*le *STROM*D*C*MP'

#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Functions Prototype
	int MyStrlen(char[]);
	void MyStrcpy(char[], char[]);

	// Variable Declarations
	char chArray_Original_nrl[MAX_STRING_LENGTH], chArray_VowelsReplaced_nrl[MAX_STRING_LENGTH];

	int iStringLength;
	int i_nrl;

	// *** STRING INPUT ***
	printf("\n\n");
	printf("Enter A String : \n\n");
	gets_s(chArray_Original_nrl, MAX_STRING_LENGTH);

	// *** STRING OUTPUT ***
	MyStrcpy(chArray_VowelsReplaced_nrl, chArray_Original_nrl);

	iStringLength = MyStrlen(chArray_VowelsReplaced_nrl);

	for (i_nrl = 0; i_nrl < iStringLength; i_nrl++)
	{
		switch (chArray_VowelsReplaced_nrl[i_nrl])
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			chArray_VowelsReplaced_nrl[i_nrl] = '*';
			break;
		default:
			break;

		}
	}

	// *** STRING OUTPUT ***
	printf("\n\n String Entered By You Is : \n\n ");
	printf("%s\n", chArray_Original_nrl);

	printf("\n\n String After Replacement Of Vowels By * Is : \n\n");
	printf("%s\n", chArray_VowelsReplaced_nrl);
	return(0);

}

int MyStrlen(char str[])
{
	// Varaible Declarations 
	int j_nrl;
	int string_length_nrl = 0;

	// Code

	// *** Determining Exact Length O the String, By Detecting The First Occurence Of Null-Terminanting Charcter (\0)
	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;
		string_length_nrl++;
	}
	return(string_length_nrl);
}

void MyStrcpy(char str_destination[], char str_source[])
{
	// Functions Prototype
	int MyStrlen(char[]);

	//Variable Declarations
	int iStringLength = 0;
	int j_nrl;

	// Code
	iStringLength = MyStrlen(str_source);
	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
		str_destination[j_nrl] = str_source[j_nrl];

	str_destination[j_nrl] = '\0';
}


