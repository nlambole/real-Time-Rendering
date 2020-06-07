#include <stdio.h> //for printf()
#include <conio.h> //for getch()

//ASCII Values For 'A' to 'Z' => 65 ro 90
#define CHAR_ALPHABET_UPPER_CASE_BEGINNING 65
#define CHAR_ALPHABET_UPPER_CASE_ENDING 90

// ASCII Values FOr 'a' to 'z' => 97 to 122
#define CHAR_ALPHABET_LOWER_CASE_BEGINNING 97
#define CHAR_ALPHABET_LOWER_CASE_ENDING 122

//ASCII Values For '0' to '9' => 48 to 57
#define CHAR_DIGIT_BEGINNING 48
#define CHAR_DIGIT_ENDING 57

int main(void)
{
	//Variables Declarations
	char ch_nrl;
	int ch_value_nrl;

	//code
	printf("\n\n");

	printf("Enter Character : ");
	ch_nrl = getch();

	printf("\n\n");

	if ((ch_nrl == 'A' || ch_nrl == 'a') || (ch_nrl == 'E' || ch_nrl == 'e') || (ch_nrl == 'I' || ch_nrl == 'i') || (ch_nrl == 'O' || ch_nrl == 'o') || (ch_nrl == 'U' || ch_nrl == 'u'))
	{
		printf("Character \'%c\' Entered By You, Is VOWEL CHARACTER From The English Alphabet !!!\n\n", ch_nrl);

	}
	else
	{

		ch_value_nrl = (int) ch_nrl;

		//If The Character Has ASCII Value Between 65 AND 90 OR Between 97 AND 122 It Is Still A Letter Of The Alphabet Of The Alphabet, Bit It Is 'CONSONANT', and NOT a 'VOMEL'...
		if ((ch_value_nrl >= CHAR_ALPHABET_UPPER_CASE_BEGINNING && ch_value_nrl <= CHAR_ALPHABET_UPPER_CASE_ENDING) || (ch_value_nrl >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && ch_value_nrl <= CHAR_ALPHABET_LOWER_CASE_ENDING))
		{
			printf("Character \'%c\' Entered By You, Is A CONSONANT CHARACTER From THE English Alphabet !!!\n\n", ch_nrl);
		}
		else if (ch_value_nrl >= CHAR_DIGIT_BEGINNING && ch_value_nrl <= CHAR_DIGIT_ENDING)
		{
			printf("Character \'%c\' Entered By You, Is A DIGIT CHARACTER !!!\n\n", ch_nrl);
		}
		else
		{
			printf("Character \'%c\' Entered By You, Is A SPECIAL CHARACTER !!!\n\n", ch_nrl);
		}
	}
	return(0);
}
