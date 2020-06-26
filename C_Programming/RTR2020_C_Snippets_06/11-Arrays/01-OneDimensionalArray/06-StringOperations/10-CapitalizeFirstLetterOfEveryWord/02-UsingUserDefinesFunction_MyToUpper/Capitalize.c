#include <stdio.h>

#define MAX_STRING_LENGTH 512

#define SPACE '  '

#define FULLSTOP '.'
#define COMMA ','
#define EXCLAMATIONS '!'
#define QUESTION_MARK '?'

int main(void)
{
	// Functions Prototypes
	int MyStrlen(char[]);
	char MyToUpper(char);

	// Varibles Declarations
	char chArray_nrl[MAX_STRING_LENGTH], chArray_CapitalizedFirstLetterOfEveryWord[MAX_STRING_LENGTH]; // A Characte Array Is A String 
	int iStringLength;
	int i_nrl, j_nrl;

	//Code
	// *** STRING INPUT ***

	printf("\n\n Enter A String : \n\n");
	gets_s(chArray_nrl, MAX_STRING_LENGTH);

	iStringLength = MyStrlen(chArray_nrl);
	j_nrl = 0;
	for (i_nrl = 0; i_nrl < iStringLength; i_nrl++)
	{
		if (i_nrl == 0) // First Letter Of Any Sentence Must Be A Capital Letter 
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl] = MyToUpper(chArray_nrl[i_nrl]);
		else if (chArray_nrl[i_nrl] == SPACE) // First Letter Of Every Word In The Sentence Must Be A Capital Letter. Words are Separated By Spaces.
		{
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl] = chArray_nrl[i_nrl];
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl + 1] = MyToUpper(chArray_nrl[i_nrl + 1]);

			// Since, Already Two Characters ( At Indices 'i' And i + 1 have Been Considered I This else-if Vlock... We re Extra-Incrementing 'i' And 'j' By 
			j_nrl++;
			i_nrl++;
		}

		else if ((chArray_nrl[i_nrl] == FULLSTOP || chArray_nrl[i_nrl] == COMMA || chArray_nrl[i_nrl] == EXCLAMATIONS || chArray_nrl[i_nrl] == QUESTION_MARK && chArray_nrl[i_nrl] != SPACE)) //First Letter Of Every Word After Punctualtions Mark, In the Sentence Must Be A Capital Letter. Words Are Separated By Punctuations.
		{
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl] = chArray_nrl[i_nrl];
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl + 1] = SPACE;
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl + 2] = MyToUpper(chArray_nrl[i_nrl + 1]);

			j_nrl = j_nrl = 2;
			i_nrl++;
		}
		else
			chArray_CapitalizedFirstLetterOfEveryWord[j_nrl] = chArray_nrl[i_nrl];
		j_nrl++;
	}

	chArray_CapitalizedFirstLetterOfEveryWord[j_nrl] = '\0';

	// *** STRING OUTPUT ***
	printf("\n\n String Entered By You Is : \n\n");
	printf("String Afte Capitalizing First Letter Of Every Word : \n\n");
	printf("%s\n", chArray_CapitalizedFirstLetterOfEveryWord);

	return(0);

}

int MyStrlen(char str[])
{
	// Varible Delcarations
	int j_nrl;
	int string_length_nrl = 0;

	//code
	// *** Determinig Exact Length Of the String, By Detecting The First Occurrence Of Null-Terminating Charcter (\0) ****
	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;
		else string_length_nrl++;

	}
	return(string_length_nrl);
}

char MyToUpper(char ch)
{
	//Variabale Declarations
	int num_nrl;
	int c_nrl;

	//CODE
	//ASCII Value of 'a' (97) - ASCII VALUE OF 'A' (65) = 32
	// This Substraction Will Give The Exact Defference Between The Upper And Lower Case COUNTERPARIS Of each Letter Of The Alphabet.
	// ASCII VALUES OF 'a' to 'z' => 97 TO 122
	// ASCII VALUES OF 'A' to 'Z' => 65 TO 90

	num_nrl = 'a' - 'A';

	if ((int)ch >= 97 && (int)ch <= 122)
	{
		c_nrl = (int)ch - num_nrl;
		return((char)c_nrl);
	}
	else
		return(ch);
}