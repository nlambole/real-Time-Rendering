#include<stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Function Prototype
	int MyStrlen(char[]);

	// Variable Declarations
	// *** A 'STRING' IS AN ARRAY OF CHARACTERS ... so char[] IS A char ARRAY AND HENCE, char[] IS A 'STRING' * **
	// *** AN ARRAY OF char ARRAYS IS AN ARRAY OF STRINGS !!! ***
	// *** HENCE, char[] IS ONE char ARRAY AND HENCE, IS ONE STRING ***
	// *** HENCE, char[][] IS AN ARRAY OF char ARRAYS AND HENCE, IS AN ARRAY OF STRINGS * **
	//Here, the string array can allow a maximum number of 10 strings (10 rows) and each of these 10 strings can have only upto 15 characters maximum(15 columns)

	char strArray_nrl[10][15] = { "Hello !", "Welcome", "To", "Real", "Time", "Rendering", "Batch", "(2020-21", "Of", "ASTROMEDICOMP" }; // In-Line Initialization
	int char_size_nrl;	
	int strArray_size_nrl;
	int strArray_num_elements_nrl, strArray_num_rows_nrl, strArray_num_columns_nrl;
	int strActual_num_chars_nrl = 0;
	int i_nrl;

	// COde
	printf("\n\n");

	char_size_nrl = sizeof(char);

	strArray_size_nrl = sizeof(strArray_nrl);
	printf("Size Of Two Dimentional (2D) Character Array (String Array) Is = %d\n\n", strArray_size_nrl);

	strArray_num_rows_nrl = strArray_size_nrl / sizeof(strArray_nrl[0]);
	printf("Number Of Rows (strings) In Two Dimentional (2D) Character Array (String Array) Is = %d\n\n", strArray_num_rows_nrl);

	strArray_num_columns_nrl = sizeof(strArray_nrl[0]) / char_size_nrl;
	printf("Number Of Columns In Two Dimensional (2D) Character Array (String Array) Is = %d\n\n", strArray_num_columns_nrl);

	strArray_num_elements_nrl = strArray_num_rows_nrl * strArray_num_columns_nrl;
	printf("Maximum Number Of Elements (Character) In Two Dimensional (2D) Character Array (String Array) Is = %d\n\n", strArray_num_elements_nrl);

	for (i_nrl = 0; i_nrl < strArray_num_rows_nrl; i_nrl++)
	{
		strActual_num_chars_nrl = strActual_num_chars_nrl + MyStrlen(strArray_nrl[i_nrl]);
	}

	printf("Actual Number Of Elements (Characters) In Two Dimensional (2D) Character Array (String Array) Is = %d\n\n", strActual_num_chars_nrl);
	printf("\n\n Strings In The 2D Array : \n\n");

	// Since, char[][] is array of strings, Referencing only by the row Number (First []) will the row or the string 
	// The Column Number (Second []) is the particular character in that string / row.

	printf("%s", strArray_nrl[0]);
	printf("%s", strArray_nrl[1]);
	printf("%s", strArray_nrl[2]);
	printf("%s", strArray_nrl[3]);
	printf("%s", strArray_nrl[4]);
	printf("%s", strArray_nrl[5]);
	printf("%s", strArray_nrl[6]);
	printf("%s", strArray_nrl[7]);
	printf("%s", strArray_nrl[8]);
	printf("%s\n\n", strArray_nrl[9]);

	return(0);
	
}

int MyStrlen(char str[])
{
	// Variable Declarations
	int i_nrl, j_nrl;
	int string_length_nrl = 0;


	//code
	// *** Determining Exact Lenth Of The String, By Detecting The First Occurence Of Null-Terminanting Character (\0) ****

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++);
	{
		if (str[j_nrl] == '\0')
		{
			printf("\n");	
		}
		else
			string_length_nrl++;
	}
	return(string_length_nrl);
}

