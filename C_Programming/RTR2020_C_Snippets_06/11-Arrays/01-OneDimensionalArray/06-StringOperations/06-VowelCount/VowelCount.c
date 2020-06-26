#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Functions Prototype
	int MyStrlen(char[]);

	// Variable Declarartions
	char chArray_nrl[MAX_STRING_LENGTH]; // A CHaracter Array Is A String
	int iStringLength_nrl;
	int count_A = 0, count_E = 0, count_I = 0, count_O = 0, count_U = 0; // Initial Counts =0
	int i_nrl;

	//CODE

	// *** STRING INPUT****

	printf("\n\n Enter A String : \n\n");
	gets_s(chArray_nrl, MAX_STRING_LENGTH);

	// *** STRING OUTPUT ***
	printf("\n\n String Entered By You Is : \n\n ");
	printf("%s\n", chArray_nrl);

	iStringLength_nrl = MyStrlen(chArray_nrl);

	for (i_nrl = 0; i_nrl < iStringLength_nrl; i_nrl++)
	{
		switch (chArray_nrl[i_nrl])
		{
		case 'A':
		case 's':
			count_A++;
			break;
		case 'E':
		case 'e':
			count_E++;
			break;
		case 'I':
		case 'i':
			count_I++;
			break;
		case 'O':
		case 'o':
			count_O++;
			break;
		case 'U':
		case 'u':
			count_U++;
			break;
		default:
			break;
		}
	}

	printf("\n\n In The String Entered By You, The Viwels And The Number Of Their Occurences Are Follows : \n\n");

	printf("'A' Has Occured = %d Times !!!\n\n", count_A);
	printf("'E' Has Occured = %d Times !!!\n\n", count_E);
	printf("'I' Has Occured = %d Times !!!\n\n", count_I);
	printf("'O' Has Occured = %d Times !!!\n\n", count_O);
	printf("'U' Has Occured = %d Times !!!\n\n", count_U);
	
	return(0);
}

int MyStrlen(char str[])
{
	// Variables Declarations
	int j_nrl;
	int string_length_nrl =0;
	
	//CODE
	// *** Determining Exact Length Of The String, BY Detecting The First Occurence Of Null terminanting Character (\0	) ***

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;
		else
			string_length_nrl++;
	}
	return(string_length_nrl);

}