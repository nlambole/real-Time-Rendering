#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Functions Prototypes
	int MyStrlen(char[]);
	void MyStrcpy(char[], char[]);

	// Variable Declarations
	char chArray_nrl[MAX_STRING_LENGTH]; // A Character Array Is A String
	int iStringLength;
	int i_nrl;
	int word_count = 0, space_count = 0;

	//CODE

	// *** STRING INPUT ***
	printf("\n\n Enter A String :\n\n ");
	gets_s(chArray_nrl, MAX_STRING_LENGTH);

	iStringLength = MyStrlen(chArray_nrl);

	for (i_nrl = 0; i_nrl < iStringLength; i_nrl++)
	{
		switch (chArray_nrl[i_nrl])
		{
		case 32: // 32 Is the ASCII Value For SPACE (' ') Character
			space_count++;
			break;
		default:
			break;
		}
	}

	word_count = space_count + 1;

	// *** String OutPut ***
	printf("\n\n String Entered By You Is : \n\n");
	printf("String Entered By Is : \n\n ");
	printf("%s\n", chArray_nrl);

	printf("\n\n Number Of Spaces In The Input String = %d\n\n", space_count);
	printf("Number Of Words In The Input String = %d\n\n", word_count);

	return(0);

}

int MyStrlen(char str[])
{
	// Variables Declarations
	int j_nrl;
	int string_length_nrl = 0;

	// Code
	// **** Determining Exact Length Of The String, By Detecting the First Occurence Of NULL-TERMINATING Character (\0	) ***
	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;
		else
			string_length_nrl++;

	}
	return(string_length_nrl);
}