#include <stdio.h>
#include <ctype.h> //For toupper()	

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Functions Prototype
	int MYStrlen(char[]);

	//Variable Declarations
	char chArray_nrl[MAX_STRING_LENGTH], chArray_CapitalizedFirstLetterOfEveryWord[MAX_STRING_LENGTH]; // A Character Array Is A String
	int iStringLength;
	int i_nrl, j_nrl;

	//CODE

	// *** STRING INPUT ***

	printf("\n\n Enter A String : \n\n ");
	gets_s(chArray_nrl, MAX_STRING_LENGTH);

	iStringLength = MyStrlen(chArray_nrl);
	j_nrl = 0;
	for (i_nrl = 0; i_nrl < iStringLength; i_nrl++)
	{
		if (i_nrl == 0)
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl] = toupper(chArray_nrl[i_nrl]);
		else if (chArray_nrl[i_nrl] == '  ')
		{
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl] = chArray_nrl[i_nrl];
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl + 1] = toupper(chArray_nrl[i_nrl + 1]);

			//Since, Already Teo Character (At Indices 'i' And i+1 have Been considered In This else-if...We Are Extra-incrementing 'i' and 'j' By 1)

			j_nrl++;
			i_nrl++;
		}
		else
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl] = chArray_nrl[i_nrl];
		j_nrl++;
	}

	chArray_CapitalizedFirstLetterOfEveryWord[j_nrl] = '\0';

		// *** STRING OUTPUT ***

	printf("\n\n String Entered By You : \n\n ");
	printf("String Entered By You Is : \n\n");
	printf("%s\n", chArray_nrl);

	printf("\n\n String After Capitalizing First Letter Of Envery Word : \n\n");
	printf("%s\n", chArray_CapitalizedFirstLetterOfEveryWord);

	return(0);

}


int MyStrlen(char str[])
{
	//Varible Declarations
	int j_nrl;
	int string_length_nrl = 0;

	// Code
	// *** Determining Exact Length Of the String, By Detecting The First Occurence Of Null-Termination charcter (\0) ***

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;
		else
			string_length_nrl++;

	}
	return(string_length_nrl);

}