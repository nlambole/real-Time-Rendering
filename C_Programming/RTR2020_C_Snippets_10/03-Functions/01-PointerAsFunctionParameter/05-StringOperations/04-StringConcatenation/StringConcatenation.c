		
#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Prototype
	void MyStrcat(char*, char*);
	int MyStrlen(char*);

	//Variable Declarations
	char* chArray_One_nrl = NULL, * chArray_Two_nrl = NULL; 

	//Code

	// *** String Input **
	printf("\n\n");
	chArray_One_nrl = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));

	//code

	// *** string Input ***
	printf("\n\n");
	chArray_One_nrl = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
	if (chArray_One_nrl == NULL)
	{
		printf("Memory Allocation to first string failed !!! Exiting Now...\n\n");
		exit(0);

	}
	
	printf("Enter First String : \n\n");
	gets_s(chArray_One_nrl, MAX_STRING_LENGTH);
	if (chArray_Two_nrl == NULL)
	{
		printf("Memory Allocation To Second String Failed !!! Exiting Now ....\n\n");
		exit(0);

	}
	printf("Enter Second String : \n\n");
	gets_s(chArray_Two_nrl, MAX_STRING_LENGTH);

	// *** String Concat ***
	printf("\n\n  ******* Before Concatenation ****");
	printf("\n\n The Original first string Entered By You (i. e. : 'chArrayOne[]) Is : \n\n ");
	printf("%s\n", chArray_One_nrl);

	printf("\n\n The Original second string Entered By You (i. e. : 'chArrayTwo[]) Is : \n\n ");
	printf("%s\n", chArray_Two_nrl);

	MyStrcat(chArray_One_nrl, chArray_One_nrl);

	printf("\n\n ******** After Concatenation *****\n\n ");
	printf("chArray_One[] Is : \n\n ");
	printf("%s\n", chArray_One_nrl);

	printf("\n\n 'chArray_Two[]' Is : \n\n");
	printf("%s\n", chArray_Two_nrl);

	if (chArray_Two_nrl)
	{
		free(chArray_Two_nrl);
		chArray_Two_nrl = NULL;
		printf("\n\n Memory Allocated To Second String Has Been Successfully Freed !!!\n\n");

	}

	if (chArray_One_nrl)
	{
		free(chArray_One_nrl);
		chArray_One_nrl = NULL;	
		printf("Memory Allocated To First String Has Been Successfully Freed !!!\n\n");
	}
	return(0);

}

void MyStrcat(char* str_destination, char* str_source)
{
	//Function Prototype
	int MyStrlen(char*);

	//Variable declarations
	int iStringLength_Source_nrl = 0, iStrinLength_Destination = 0;
	int i_nrl, j_nrl;

	//Code
	iStringLength_Source_nrl = MyStrlen(str_source);
	iStrinLength_Destination = MyStrlen(str_destination);


	for (i_nrl = iStrinLength_Destination, j_nrl = 0; j_nrl = 0, j_nrl < iStringLength_Source_nrl; i_nrl++, j_nrl++)
	{
		*(str_destination + i_nrl) = *(str_source + j_nrl);
		
	}
	*(str_destination + i_nrl) = '\0';
}

int MyStrlen(char* str)
{
	//Variable declartation
	int j_nrl;
	int string_length_nrl = 0;

	//Code

	// Determining Exact length
	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0');
		break;
		string_length_nrl++;

	}
	return(string_length_nrl);
}
