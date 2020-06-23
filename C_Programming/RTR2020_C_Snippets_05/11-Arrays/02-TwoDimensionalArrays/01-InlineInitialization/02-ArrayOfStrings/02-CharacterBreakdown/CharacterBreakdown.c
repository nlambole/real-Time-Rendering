#include<stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Function Prototype
	int MyStrlen_nrl(char[]);

	// Variable Declarations
	// *** A 'STRING' IS AN ARRAY OF CHARACTERS ... so char[] IS A char ARRAY AND HENCE, char[] IS A 'STRING' * **
	// *** AN ARRAY OF char ARRAYS IS AN ARRAY OF STRINGS !!! ***
	// *** HENCE, char[] IS ONE char ARRAY AND HENCE, IS ONE STRING ***
	// *** HENCE, char[][] IS AN ARRAY OF char ARRAYS AND HENCE, IS AN ARRAY OF STRINGS * **
	//Here, the string array can allow a maximum number of 10 strings (10 rows) and each of these 10 strings can have only upto 15 characters maximum(15 columns)

	char strArray_nrl[10][15] = { "Hello !", "Welcome", "To", "Real", "Time", "Rendering", "Batch", "(2020-21", "Of", "ASTROMEDICOMP" }; // In-Line Initialization
	int iStrLength_nrl[10]; // 1D Iteger Array - Stores lengths of those strings at corresponding indices in 'strArray[]' e.g
	int strArray_size_nrl;
	int strArray_num_rows_nrl;
	int i_nrl, j_nrl;

	//Code
	strArray_size_nrl = sizeof(strArray_nrl);
	strArray_num_rows_nrl = strArray_size_nrl / sizeof(strArray_nrl[0]);

	// Storing in lengths of all the string...
	for (i_nrl = 0; i_nrl < strArray_num_rows_nrl; i_nrl++)
		iStrLength_nrl[i_nrl] = MyStrlen_nrl(strArray_nrl[i_nrl]);

	printf("\n\n The Entrire String Array : \n\n");
	for (i_nrl = 0; i_nrl < strArray_num_rows_nrl; i_nrl++)
		printf("%s", strArray_nrl[i_nrl]);

	printf("\n\n");
	printf("Strings In the 2D Array : \n\n");

	//Since, char[][] is an array of strings, referencing only by the row number (first[]) will give the row or the string
	//The Column Number (second []) is the particular character in that string /row

	for (i_nrl = 0; i_nrl < strArray_num_rows_nrl; i_nrl++)
	{
		printf("String Number %d => %s \n\n", (i_nrl + 1), strArray_nrl[i_nrl]);
		for (j_nrl = 0; j_nrl < iStrLength_nrl[i_nrl]; j_nrl++)
		{
			printf("Character %d = %c \n", (j_nrl + 1), strArray_nrl[i_nrl][j_nrl]);
		}
		printf("\n\n");
	}
	return(0);
}

int MyStrlen_nrl(char str[])
{
	// Variable Declarations
	int j_nrl;
	int string_length_nrl = 0;

	// CODE
	// *** Determining Exact Lenght Of the String, By Detecting The First Occurence Of Null-Terminating Character (\0) ***

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\n')
			break;
		else
			string_length_nrl++;
	}
	return(string_length_nrl);
}
