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
	char strArray_nrl[5][10]; // 5 ROWS (0, 1, 2, 3, 4,) -> Strings (EACH STRING CAN HAVE A MAXIMUM OF 10 CHARCTERS	)

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

	

}


