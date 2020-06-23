#include <stdio.h>
int main(void)
{
	// Variable Declarations
	int iArray_nrl[] = { 9, 30, 6, 12, 98, 95, 20, 23, 2, 45 };
	int int_size_nrl;
	int iArray_size_nrl;
	int iArray_num_elements_nrl;

	float fArray_nrl[] = { 1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f,7.8f,8.9f };
	int float_size_nrl;
	int fArray_size_nrl;
	int fArray_num_elements_nrl;

	char cArray_nrl[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P' };
	int char_size_nrl;
	int cArray_size_nrl;
	int cArray_num_elements_nrl;

	// Code
	
	// *** iArray[] ****

	printf("\n\n In-Line Initialization And Piece-meal Display Of Elements of Array 'iArra[]' : \n\n");
	printf("iArray[0] (1st Element) = %d\n", iArray_nrl[0]);
	printf("iArray[1] (2nd Element) = %d\n", iArray_nrl[1]);
	printf("iArray[2] (3rd Element) = %d\n", iArray_nrl[2]);
	printf("iArray[3] (4th Element) = %d\n", iArray_nrl[3]);
	printf("iArray[4] (5th Element) = %d\n", iArray_nrl[4]);
	printf("iArray[5] (6th Element) = %d\n", iArray_nrl[5]);
	printf("iArray[6] (7th Element) = %d\n", iArray_nrl[6]);
	printf("iArray[7] (8th Element) = %d\n", iArray_nrl[7]);
	printf("iArray[8] (9th Element) = %d\n", iArray_nrl[8]);
	printf("iArray[9] (10th Element) = %d\n", iArray_nrl[9]);

	int_size_nrl = sizeof(int);
	iArray_size_nrl = sizeof(iArray_nrl);
	iArray_num_elements_nrl = iArray_size_nrl / int_size_nrl;

	printf("Size Of Data Types 'int' = %d bytes\n", int_size_nrl);
	printf("Number Of Elements In 'int' Array 'iArray[]' = %d Elements \n", iArray_num_elements_nrl);
	printf("Size Of Array 'iArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", iArray_num_elements_nrl, int_size_nrl, iArray_size_nrl);

	// **** fArray[] ****
	printf("\n\n In-Line Initialization And Piece-meal Display Of Elements of Array 'fArray[]' : \n\n");
	printf("fArray[0] (1st Element) = %f\n\n", fArray_nrl[0]);
	printf("fArray[1] (2nd Element) = %f \n\n", fArray_nrl[1]);
	printf("fArray[2] (3rd Element) = %f \n\n", fArray_nrl[2]);
	printf("fArray[3] (4th Element) = %f \n\n", fArray_nrl[3]);
	printf("fArray[4] (5th Element) = %f \n\n", fArray_nrl[4]);
	printf("fArray[5] (6th Element) = %f \n\n", fArray_nrl[5]);
	printf("fArray[6] (7th Element) = %f \n\n", fArray_nrl[6]);
	printf("fArray[7] (8th Element) = %f \n\n", fArray_nrl[7]);
	printf("fArray[8] (9th Element) = %f \n\n", fArray_nrl[8]);
	printf("fArray[9] (10th Element) = %f \n\n", fArray_nrl[9]);

	float_size_nrl = sizeof(float);
	fArray_size_nrl = sizeof(fArray_nrl);
	fArray_num_elements_nrl = fArray_size_nrl / float_size_nrl;

	printf("Size Of Data Type 'Float' = %d Bytes \n", float_size_nrl);
	printf("Number Of Elements In 'float' Array 'fArray[]' = %d Elements \n ", fArray_num_elements_nrl);
	printf("Size Of Array 'fArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", fArray_num_elements_nrl, float_size_nrl, fArray_size_nrl);


	// ***** cArray[] ****

	printf("\n\n In-line Initialization And Piece-meal Display Of Elements of Array 'cArray[]' : \n\n");
	printf("cArray[0] (1st Element) = %c\n", cArray_nrl[0]);
	printf("cArray[1] (2nd Element) = %c\n", cArray_nrl[1]);
	printf("cArray[2] (3rd Element) = %c\n", cArray_nrl[2]);
	printf("cArray[3] (4th Element) = %c\n", cArray_nrl[3]);
	printf("cArray[4] (5th Element) = %c\n", cArray_nrl[4]);
	printf("cArray[5] (6th Element) = %c\n", cArray_nrl[5]);
	printf("cArray[6] (7th Element) = %c\n", cArray_nrl[6]);
	printf("cArray[7] (8th Element) = %c\n", cArray_nrl[7]);
	printf("cArray[8] (9th Element) = %c\n", cArray_nrl[8]);
	printf("cArray[9] (10th Element) = %c\n", cArray_nrl[9]);
	printf("cArray[10] (11th Element) = %c\n", cArray_nrl[10]);
	printf("cArray[11] (12th Element) = %c\n", cArray_nrl[11]);
	printf("cArray[12] (13th Element) = %c\n", cArray_nrl[12]);

	char_size_nrl = sizeof(char);
	cArray_size_nrl = sizeof(cArray_nrl);
	cArray_num_elements_nrl = cArray_size_nrl / char_size_nrl;

	printf("Size Of Data type 'char' = %d bytes \n", char_size_nrl);
	printf("Number Of Elements In 'char' Array 'cArray[] = %d Elements\n", cArray_num_elements_nrl);
	printf("Size Of Array 'cArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n	", cArray_num_elements_nrl, char_size_nrl, cArray_size_nrl);

	return(0);

}