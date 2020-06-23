#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Functions Prototypes

	void MyStrcpy_nrl(char[], char[]);

	// Varaibles Declarations

	// *** A 'STRING' is an Array of ACharacters .... so char[] is A char ARRAY AND HENCE, char[] is A String ***
	// *** An Array of Char Arrays is An Array ANd Hence Of Strings  ***
	// *** Hence, char[] Is One char ARRAY Of char ARRAYS AND HENCE, Is An Array Of STRINGS ***

	// Here, the string array can allow a maximu number of 5 strings canhave only upto 10 charactes maximum (10 columns) 
	char strArray_nrl[6][10]; // 5 ROWS (0, 1, 2, 3, 4,) -> Strings (EACH STRING CAN HAVE A MAXIMUM OF 10 CHARCTERS	)

	char char_size_nrl;
	int strArray_size_nrl;
	int strArray_num_elements_nrl, strArray_num_rows_nrl, strArray_num_columns_nrl;
	int i_nrl;

	//code
	printf("\n\n");

	char_size_nrl = sizeof(char);

	strArray_size_nrl = sizeof(strArray_nrl);
	printf("SIze Of Two Dimensional (2D) Character Array (String Array) Is = %d \n\n", strArray_size_nrl);

	strArray_num_rows_nrl = strArray_size_nrl / sizeof(strArray_nrl[0]);
	printf("Number Of Rows (Strings) In Two Dimensional (2D0 Character Array (String Array) Is = %d \n\n", strArray_num_rows_nrl);

	strArray_num_columns_nrl = sizeof(strArray_nrl[0]) / char_size_nrl;
	printf("Number Of Columns In Two Dimensional (2D) Character Array (String Array) Is = %d \n\n", strArray_num_columns_nrl);

	strArray_num_elements_nrl = strArray_num_rows_nrl * strArray_num_columns_nrl;
	printf("Maximum Number of Elements (Characters) In Two Dimensional ( 2D ) Character Array(String Array) Is = % d\n\n", strArray_num_elements_nrl);


	// ******* Piece-Meal Assignment ***

	// ****** Row 1 / String 1 ******
	strArray_nrl[0][0] = 'M';
	strArray_nrl[0][1] = 'Y';
	strArray_nrl[0][2] = '\0';

	// ****** Row 2 / String 2 *****

	strArray_nrl[1][0] = 'N';
	strArray_nrl[1][1] = 'A';
	strArray_nrl[1][2] = 'M';
	strArray_nrl[1][3] = 'E';
	strArray_nrl[1][4] = '\0';

	// ***** Row 3 / String 3 *****
	strArray_nrl[2][0] = 'I';
	strArray_nrl[2][1] = 'S';
	strArray_nrl[2][2] = '\0';

	
	// ***** Row 4 / String 4 *****
	strArray_nrl[3][0] = 'N';
	strArray_nrl[3][1] = 'A';
	strArray_nrl[3][2] = 'N';
	strArray_nrl[3][3] = 'D';
	strArray_nrl[3][4] = 'L';
	strArray_nrl[3][5] = 'A';
	strArray_nrl[3][6] = 'L';
	strArray_nrl[3][7] = '\0';

	// ***** Row 5 / String 5 *****
	strArray_nrl[4][0] = 'L';
	strArray_nrl[4][1] = 'A';
	strArray_nrl[4][2] = 'M';
	strArray_nrl[4][3] = 'B';
	strArray_nrl[4][4] = 'O';
	strArray_nrl[4][5] = 'L';
	strArray_nrl[4][6] = 'E';
	strArray_nrl[4][7] = '\0';

	printf("\n\n");
	printf("The Strings In the 2D Character Array Are : \n\n");
	for (i_nrl = 0; i_nrl < strArray_num_rows_nrl; i_nrl++)
	printf("%s ", strArray_nrl[i_nrl]);
	printf("\n\n");

	return(0);
}


int MyStrlen_nrl(char str[])
{
	// Variable Declarations
	int j_nrl;
	int string_length_nrl = 0;

	// Code
	// *** Determining Exact Length Of The String,  By Detecting The First Occurence Of Null-Terminating Character (\0)

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl)
	{
		if (str[j_nrl] == '\0')
			break;
		else
			string_length_nrl++;		

	}
	return(string_length_nrl);
}



