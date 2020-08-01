#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrrev(char*, char*);
	int MyStrlen(char*);

	//Variable Declarations
	char* chArray_Original_nrl = NULL, * chArray_Reversed_nrl = NULL; // A Character Array Is A String
	int original_string_length_nrl;

	//code

	// *** String Input ***
	printf("\n\n");
	chArray_Original_nrl = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));

	if (chArray_Original_nrl == NULL)
	{
		printf("Memory Allocation For Original String Failed !!! Exiting Now...\n\n");
		exit(0);
	}

	printf("Enter A String : \n\n");
	gets_s(chArray_Original_nrl, MAX_STRING_LENGTH);

	//*** SDTRING REVERSE  ***
	original_string_length_nrl = MyStrlen(chArray_Original_nrl);
	chArray_Reversed_nrl = (char*)malloc(original_string_length_nrl * sizeof(char));
	if (chArray_Reversed_nrl == NULL)
	{
		printf("Memory Allocation For Reversed String Failed !!! Exiting Now ... \n\n");
		exit(0);

	}

	MyStrrev(chArray_Reversed_nrl, chArray_Original_nrl);

	// *** STRING OUTPUT ***
	printf("\n\n The Original String Entered By You (i.e. : 'chArray_Original[]') Is : \n\n");
	printf("%s\n", chArray_Original_nrl);

	printf("\n\n The Reversed String (i.e  : 'chArray_Reversed[]') Is : \n\n");
	printf("%s\n", chArray_Reversed_nrl);


	if (chArray_Reversed_nrl)
	{
		free(chArray_Reversed_nrl);
		chArray_Reversed_nrl = NULL;

		printf("\n\n");
		printf("Memory Allocated To Reversed String Has Been Successfully Freed !!!\n\n");
	}

	if (chArray_Original_nrl)
	{
		free(chArray_Original_nrl);
		chArray_Original_nrl = NULL;
		printf("\n\n Memory Allocated To Original String Has Been Successfully Freed !!!\n\n");
	}
	return(0);

}

void MyStrrev(char* str_destination, char* str_source)
{
	//Function Declarations
	int MyStrlen(char*);

	// Variable Declarations
	int iStringLength_nrl = 0;
	int i_nrl, j_nrl, len_nrl;

	//Code

	iStringLength_nrl = MyStrlen(str_source);

	//Array Indices Begin From 0; Hence Last Index Will always be (Length - 1	)

	len_nrl = iStringLength_nrl - 1;

	//We need to put the character which is ata last index of 'str_source' To The Fitst Index Of 'str_destination' and so on....
	
	for (i_nrl = 0, j_nrl=len_nrl; i_nrl < iStringLength_nrl, j_nrl >=0;i_nrl++, j_nrl--)
	{
		*(str_destination + 1) = *(str_source + j_nrl);
	}

	*(str_destination + i_nrl) = '\0';
}

int MyStrlen(char* str)
{
	//Variable Decalrations
	int j_nrl;
	int string_length_nrl = 0;

	//code
	// *** Determing Exact Length of the string, By deteceting the first occurence of NUll-Terminanting character (\0) ***
	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl)
	{
		if (str[j_nrl] == '\0')
			break;
		else
			string_length_nrl++;
	}
	return(string_length_nrl);
}
