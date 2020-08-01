#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Functions Prototype
	void MyStrcpy(char*, char*);
	int MyStrlen(char*);

	//Variabale declarations
	char* chArray_Original_nrl = NULL, *chArray_copy_nrl = NULL; //A cCharacter Aray Is A String
	int original_string_length_nrl;

	//Code

	// *** String Input ***
	printf("\n\n ");
	chArray_Original_nrl = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (chArray_Original_nrl == NULL)
	{
		printf("Memory Allocation For Original String Failed !!! Exiting Now...\n\n");
		exit(0);

	}

	printf("Enter A String : \n\n");
	gets_s(chArray_Original_nrl, MAX_STRING_LENGTH);

	original_string_length_nrl = MyStrlen(chArray_Original_nrl);
	chArray_copy_nrl = (char*)malloc(original_string_length_nrl * sizeof(char));

	if (chArray_copy_nrl == NULL)
	{
		printf("Memory Allocation For Coppied String Failed !!! Exiting  Now..\n\n");
		exit(0);
	}
	
	// *** String Copy ****
	MyStrcpy(chArray_copy_nrl, chArray_Original_nrl);

	// *** String Output ***
	printf("\n\n The Original String Entered By You  (i. e. : 'chArray_Original' Is \n\n");
	printf("%s\n", chArray_Original_nrl);
	printf("\n\n The Copied String (i.e. : 'chArray_copy') Is :  \n\n");
	printf("%s\n", chArray_copy_nrl);

	if (chArray_copy_nrl)
	{
		free(chArray_copy_nrl);
		chArray_copy_nrl = NULL;
		printf("\n\n Memory Allocated For Copied  String Has Been Successfully Freed !!!\n\n");
	}

	if (chArray_Original_nrl)
	{
		free(chArray_Original_nrl);
		chArray_Original_nrl = NULL;
		printf("\n\n MEMORY ALLOCATED FOR ORIGNAL STRINGS HAS BEEN SUCCESSFULLY FREED !!!\n\n");

	}

	return(0);
}

void MyStrcpy(char* str_destination, char* str_source)
{
	//function prototyope
	int MyStrlen(char*);


	//Variable declarations
	int iStringLength_nrl = 0;
	int j_nrl;

	//code
	iStringLength_nrl = MyStrlen(str_source);
	for (j_nrl = 0; j_nrl < iStringLength_nrl; j_nrl++)
	{
		*(str_destination + j_nrl) = *(str_source + j_nrl);

		*(str_destination + j_nrl) = '\0';
	}

}

int MyStrlen(char* str)
{
	//Variable Declarations
	int j_nrl;
	int string_length_nrl = 0;


	//Code
	// *** Determing Exact Length Of The String, By Detecting The First Occurence Of NULL-TERMINATING ChARACTER (\0) **

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;
		else
			string_length_nrl++;
	}
	return(string_length_nrl);
}

