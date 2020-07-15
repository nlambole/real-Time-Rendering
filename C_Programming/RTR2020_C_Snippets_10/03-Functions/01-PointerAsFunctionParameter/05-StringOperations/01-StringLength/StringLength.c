#include <stdio.h>	
#include <stdlib.h>	

#define MAX_STRING_LENGTH	512

int main(void)
{
	//Functions Prototype
	int MyStrlen_nrl(char*);
	
	//Varaible Declaration
	char* chArray_nrl = NULL; // Character Array Can BE Represented By A Chae pointer to Mark The BAse Address(char *	)

	int iStringLength_nrl = 0;

	//Code
	printf("\n\n ");
	chArray_nrl = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (chArray_nrl == NULL)
	{
		printf("Memory Allocation To Character Array Failed !!! Exiting Now...\n\n");
		exit(0);
	}

	// *** STRING INPUT  ***
	printf("Enter A String : \n\n");
	gets_s(chArray_nrl, MAX_STRING_LENGTH);

	// *** STRING OUTPUT ***
	printf("\n\n String Entered By You Is : \n\n	");
	printf("%s\n", chArray_nrl);
	
	// *** STRING LENGTH ****
	printf("\n\n");
	iStringLength_nrl = MyStrlen(chArray_nrl);
	printf("Length Of String Is = %d Characters !!!\n\n", iStringLength_nrl);

	if (chArray_nrl)
	{
		free(chArray_nrl);
		chArray_nrl = NULL;

	}

	return(0);

}

int MyStrlen(char* str)
{
	//Variable Decalrations
	int j_nrl;
	int string_length_nrl = 0;

	//Code
	// *** Deternmining Exact Length Of The String, By Detecting The First  Occurence Of Null-Terminating Character(\0) ***

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (*(str + j_nrl) == '\0')
			break;
		else
			string_length_nrl++;
	}

	return(string_length_nrl);
}
