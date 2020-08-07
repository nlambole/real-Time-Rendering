#include <stdio.h>
#include <ctype.h>	
#include <string.h>

#define MAX_STRING_LENGTH 1024

struct CharacterCount
{
	char ch_nrl;
	int ch_count_nrl;

}character_and_count[] = { { 'A', 0 }, { 'B', 0 }, { 'C', 0 }, { 'C', 0 }, { 'D', 0 }, { 'E', 0 }, { 'F', 0 }, { 'G', 0 }, { 'H', 0 }, { 'I', 0 }, { 'J', 0 }, { 'K', 0 }, { 'L', 0 }, { 'M', 0 }, { 'N', 0 }, { 'O', 0 }, { 'P', 0 }, { 'Q', 0 }, { 'R', 0 }, { 'S', 0 }, { 'T', 0 }, { 'U',0 }, { 'V', 0 }, { 'W', 0 }, { 'X', 0 }, {'Y', 0}, {'Z', 0} };

#define SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS sizeof(character_and_count)	
#define SIZE_OF_ONE_STRUCT_FROM_THE_ARRAY_OF_STRUCTS sizeof(character_and_count[0])
#define NUM_ELEMENTS_IN_ARRAY (SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS / SIZE_OF_ONE_STRUCT_FROM_THE_ARRAY_OF_STRUCTS)

//Entry Point Function
int main(void)
{
	//Varaible Declarations
	char str_nrl[MAX_STRING_LENGTH];
	int i_nrl, j_nrl, actual_length_nrl = 0;

	//Code
	printf("\n\n Enter A String : \n\n");
	gets_s(str_nrl, MAX_STRING_LENGTH);

	actual_length_nrl = strlen(str_nrl);

	printf("\n\n The String You Have Entered Is : \n\n");
	printf("%s \n\n", str_nrl);

	for (i_nrl = 0; i_nrl < actual_length_nrl; i_nrl++)
	{
		for (j_nrl = 0; j_nrl < NUM_ELEMENTS_IN_ARRAY; j_nrl++) // Run Every character of the input string through the entire alphabet (A to Z)
		{
			str_nrl[i_nrl] = toupper(str_nrl[i_nrl]); // If input character is in lower case , turn it to upper case for comparsion
			
			if (str_nrl[i_nrl] == character_and_count[j_nrl].ch_nrl) //If The character is present...
				character_and_count[j_nrl].ch_count_nrl++; //Increment its count by 1..
		}
	}

	printf("\n\n The Number Of Occurence Of All Character From The Alphabet Are As Follows: \n\n");
	for (i_nrl = 0; i_nrl < NUM_ELEMENTS_IN_ARRAY; i_nrl++)
	{
		printf("Character %c = %d\n", character_and_count[i_nrl].ch_nrl, character_and_count[i_nrl].ch_count_nrl);
	}

	printf("\n\n");

	return(0);
}
