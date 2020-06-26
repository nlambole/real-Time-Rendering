#include <stdio.h>

#define MAX_STRING_LENGTH	512

int main(void)
{
	// FUnction Prototypes
	int MyStrlen(char[]);
	void MyStrcpy(char[], char[]);

	//Variables Declarations
	char chArray_nrl[MAX_STRING_LENGTH], chArray_SpacesRemoved_nrl[MAX_STRING_LENGTH]; // A Character Array Is A String
	int iStringLength;
	int i_nrl, j_nrl;

	//CODE

	// *** STRING INPUT ***
	printf("\n\n Enter A String : \n\n");
	gets_s(chArray_nrl, MAX_STRING_LENGTH);

	iStringLength = MyStrlen(chArray_nrl);
	j_nrl = 0;
	for (i_nrl = 0; i_nrl < iStringLength; i_nrl++)
	{
		if (chArray_nrl[i_nrl] == ' ')
			continue;
		else
		{
			chArray_SpacesRemoved_nrl[j_nrl] = chArray_nrl[i_nrl];
			j_nrl++;

		}
	}

	chArray_SpacesRemoved_nrl[j_nrl] = '\0';

	// *** STRING OUTPUT ***
	printf("\n\n String Entered By You Is : \n\n");
	printf("%s\n", chArray_nrl);

	printf("\n\n String After Removal Of Spaces Is : \n\n");
	printf("%s\n", chArray_SpacesRemoved_nrl);

	return(0);
}

int MyStrlen(char str[])
{
	// Variable Declarations
	int j_nrl;
	int string_length_nrl = 0;

	//CODE
	//** Determining Exact Length Of The String, By Detecting the First Occurence Of Null-Terminating Charcter (\0	) **
	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;
		else
			string_length_nrl++;
	}

	return(string_length_nrl);
}
