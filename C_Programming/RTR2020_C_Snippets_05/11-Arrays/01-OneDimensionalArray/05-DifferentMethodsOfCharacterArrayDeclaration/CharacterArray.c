#include <stdio.h>

int main(void)
{
	// Variable Declarations
	char chArray_01_nrl[] = { 'A','S', 'T', 'R', 'O', 'M', 'M', 'E', 'D', 'I', 'C','O','M','P' }; // Must give \0 Explicitly For Proper Initializatios
	char chArray_02_nrl[] = { 'W', 'E','L', 'C', 'O','M','E', 'S','\0' }; // Must give \0 Explicitly For Proper Initialization
	char chArray_03_nrl[] = { 'Y', 'O', 'U', '\0' }; // Must Give \0 Explicitly For Proper Initialization
	char chArray_04_nrl[] = "To"; // \0 is assumed size is given as 3, although string has only 2 characters.
	char chArray_05_nrl[] = "REAL TIME RENDERING BATCH OF 2020-21"; // \0 is assumed , size is given as 40, although string has 39 characters

	char chArray_WithoutNullTerminator[] = { 'H', 'e', 'l', 'l','o' };

	// Code
	printf("\n\n");
	printf("Size Of chArray_01 : %lu\n\n", sizeof(chArray_01_nrl));
	printf("Size Of chArray_02 : %lu\n\n", sizeof(chArray_02_nrl));
	printf("Size Of chArray_03 : %lu\n\n", sizeof(chArray_03_nrl));
	printf("Size Of chArray_04 : %lu\n\n", sizeof(chArray_04_nrl));
	printf("Size Of chArray_05 : %lu\n\n", sizeof(chArray_05_nrl));

	printf("\n\n");

	printf("The Strings Are : \n\n");
	printf("chArray_01 : %s\n\n", chArray_01_nrl);
	printf("chArray_02 : %s\n\n", chArray_02_nrl);
	printf("chArray_03 : %s\n\n", chArray_03_nrl);
	printf("chArray_04 : %s\n\n", chArray_04_nrl);
	printf("chArray_05 : %s\n\n", chArray_05_nrl);

	printf("\n\n");
	printf("Size Of chArray_WithoutNullTerminator : %lu\n\n", sizeof(chArray_WithoutNullTerminator));
	printf("chArray_WithoutNullTerminator : %s\n\n", chArray_WithoutNullTerminator);
	// Will Display Garbage Value at the end of string due to absence of \0

	return(0);

}