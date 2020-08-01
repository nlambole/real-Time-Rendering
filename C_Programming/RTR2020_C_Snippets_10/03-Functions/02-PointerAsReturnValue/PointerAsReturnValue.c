#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	//Function Declarations
	char* ReplaceVowelsWithHashSymbol(char*);

	//Variable Declarations
	char string_nrl[MAX_STRING_LENGTH];
	char* replaced_string_nrl = NULL;

	//Code
	printf("\n\n Enter String : ");
	gets_s(string_nrl, MAX_STRING_LENGTH);

	replaced_string_nrl = ReplaceVowelsWithHashSymbol(string_nrl);
	if (replaced_string_nrl == NULL)
	{
		printf(" ReplaceVowelsWithHashSymbol() Functions Has Failed !!! Exiting Now....");
		exit(0);

	}

	printf("\n\n Replaced String Is : \n\n");
	printf("%s\n\n", replaced_string_nrl);

	if (replaced_string_nrl)
	{
		free(replaced_string_nrl);
		replaced_string_nrl = NULL;
	}
	return(0);

}

char* ReplaceVowelsWithHashSymbol(char* s)
{
	//Function Prototype
	void MyStrcpy(char*, char*);
	int MyStrlen(char*);

	//Variable Declarations
	char* new_string_nrl = NULL;
	int i_nrl;

	//Code
	new_string_nrl = (char*)malloc(MyStrlen(s) * sizeof(char));
	if (new_string_nrl == NULL)
	{
		printf("Could Not Allcoate Memory For New String !!! \n\n ");
		return(NULL);
	}

	MyStrcpy(new_string_nrl, s);
	for (i_nrl = 0; i_nrl < MyStrlen(new_string_nrl); i_nrl++);
	{
		switch (new_string_nrl[i_nrl])
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			
			new_string_nrl[i_nrl] = '#';
			break;
		default:
			break;
		}
	}

	return(new_string_nrl);
}

void MyStrcpy(char* str_destination, char* str_source)
{
	//Function Declarations
	int MyStrlen(char*);

	//Variable Declartions
	int iStringLength_nrl = 0;
	int j_nrl;

	//Code
	iStringLength_nrl = MyStrlen(str_source);
	for (j_nrl = 0; j_nrl < iStringLength_nrl; j_nrl++)
		*(str_destination + j_nrl) = *(str_source + j_nrl);

	*(str_destination + j_nrl) = '\0';
}

int MyStrlen(char* str)
{
	//Variable Declartions
	int j_nrl;
	int string_length_nrl = 0;

	//code
	// *** Determining Exact Length of String....

	for (j_nrl = 0; j_nrl < MAX_STRING_LENGTH; j_nrl++)
	{
		if (str[j_nrl] == '\0')
			break;
		string_length_nrl++;
	}
	return(string_length_nrl);
}
