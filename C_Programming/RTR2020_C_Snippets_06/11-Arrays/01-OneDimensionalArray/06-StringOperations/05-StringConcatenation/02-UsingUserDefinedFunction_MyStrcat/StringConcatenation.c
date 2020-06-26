#include <stdio.h>

#define MAX_STRING_LENGTH 512


int main(void)
{
	//Function Prototype
	void MyStrcat(char[], char[]);

	//Variable Declarations
	char chArray_One_nrl[MAX_STRING_LENGTH], chArray_Two_nrl[MAX_STRING_LENGTH]; // A Character Array Is A String

	// Code
	// **** STRING INPUT ***
	printf("\n\n Enter First String : \n\n");
	gets_s(chArray_One_nrl, MAX_STRING_LENGTH);

	printf("\n\n Enter Second String : \n\n");
	gets_s(chArray_Two_nrl, MAX_STRING_LENGTH);

	// *** STRING CONCAT ****
	printf("\n\n ******* BEFORE CONCATENATION ***** \n\n "	);
	printf("the Original First String Entered By You (i. e. : 'chArray_One[]') Is : \n\n	");
	printf("%s\n", chArray_One_nrl);

	printf("\n\n The Original Second String Entered By You (i. e. : 'chArray_Two[]') Is : \n\n");
	printf("%s\n", chArray_Two_nrl);

	MyStrcat(chArray_One_nrl, chArray_Two_nrl);

	printf("\n\n ******* AFTER CONCATENATION ******\n\n");
	printf("\n\n 'chArray_One[]' Is : \n\n");
	printf("%s\n", chArray_One_nrl);

	printf("\n\n 'chArray_Two[]' Is : \n\n	");
	printf("%s\n", chArray_Two_nrl);

	return(0);

}

void MyStrcat(char str_destination[], char str_source[])
{
	// Function Prototypes
	int MyStrlen(char[]);

	//Variable Declarations
	int iStringLength_Source_nrl = 0, iStringLength_Destination_nrl = 0;
	int i_nrl, j_nrl;

	//CODE
	iStringLength_Source_nrl = MyStrlen(str_source);
	iStringLength_Destination_nrl = MyStrlen(str_destination);

	// Array Indices Begin From 0, Hence, Last Valid Of Array Will Always Be (Length - 1)
	// So, Concatenation Must Begin From Index Number Equal To Length Of The Array 'str_destination'
	// We Need To Put The Character Which Is At First Index Of 'str_source' To The (Last Index + 1) of 'str_destination'


	for (i_nrl = iStringLength_Destination_nrl, j_nrl = 0; j_nrl < iStringLength_Source_nrl; i_nrl++, j_nrl++)
	{
		str_destination[i_nrl] = str_source[j_nrl];

	}

	str_destination[i_nrl] = '\0';
}

int MyStrlen(char str[])
{
	// Varaible Declarartions
	int j_nrl;
	int string_length_nrl = 0;

	//Code
	// *** Determining Exact Length Of The String, By Detecting The First Occurence Of Null-Terminating Character (\0)
	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;
		else
			string_length_nrl++;
	}

	return(string_length_nrl);
}
