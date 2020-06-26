#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Functions Prototypes
	int MyStrlen(char[]);

	//Variable Declarations
	char chArray_nrl[MAX_STRING_LENGTH]; // A Character Array Is A String
	int iStringLength_nrl = 0;

	//code

	// **** STRING INPUT ****
	printf("\n\n Enter A String : \n\n	");
	gets_s(chArray_nrl, MAX_STRING_LENGTH);

	// *** STRING OUTPUT ***
	printf("\n\n String Entered BY You Is : \n\n");
	printf("%s\n", chArray_nrl);

	// *** STRING LENGTH ***
	printf("\n\n");
	iStringLength_nrl = MyStrlen(chArray_nrl);
	printf("Length Of String Is = %d Character !!!\n\n", iStringLength_nrl);

	return(0);
}

int MyStrlen(char str[])
{
	// Variables Declarations
	int j_nrl;
	int string_length_nrl = 0;

	// Code
	// *** Determining Exact Length Of The String , By Detecting The First Occurence Of Null Terminanting Character (\0	)

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;
		else
			string_length_nrl;
	}

	return(string_length_nrl);

}
