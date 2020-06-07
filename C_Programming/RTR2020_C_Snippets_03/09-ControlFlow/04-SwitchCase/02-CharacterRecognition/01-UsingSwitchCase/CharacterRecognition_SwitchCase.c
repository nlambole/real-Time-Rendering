#include<stdio.h>  //for printf()
#include<conio.h>	//for getch()

//ASCII Value For 'A' to 'Z' => 65 to 90
#define CHAR_ALPHABET_UPPER_CASE_BEGINNIG 65
#define CHAR_ALPHABET_UPPER_CASE_ENDING 90

//ASCII Values For 'a' to 'z' => 97 to 122
#define CHAR_ALPHABET_LOWER_CASE_BEGINNING 97
#define CHAR_ALPHABET_LOWER_CASE_ENDING 122

//ASCII Values For '0' to '9' => 48 to 57
#define CHAR_DIGIT_BEGINNING 48
#define CHAR_DIGIT_ENDING 57

int main(void)
{
	//Variable declarations
	char ch_nrl;
	int ch_value_nrl;

	//Code
	printf("\n\n");

	printf("Enter Character : ");
	ch_nrl = getch();

	printf("\n\n");

	switch (ch_nrl)
	{
		//Fall Through Condition....
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

		printf("Character \'%c\' Entered By You, Is A VOWEL CHARACTER From From The English Alphabet !!!\n\n", ch_nrl);
		break;

	default:
		ch_value_nrl = (int)ch_nrl;

		//If  The Character Has ASCII Value Between 65 AND 90 OR BETWEEN 97 AND 122, It Is Still A Letter Of The Alphabet , But It Is A 'CONSTANT', and NOT a 'VOWEL'....

		if ((ch_value_nrl >= CHAR_ALPHABET_UPPER_CASE_BEGINNIG && ch_value_nrl <= CHAR_ALPHABET_UPPER_CASE_ENDING) || (ch_value_nrl >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && ch_value_nrl <= CHAR_ALPHABET_LOWER_CASE_ENDING))
		{
			printf("Character \'%c\' Entered By You, Is A CONSONANT CHARACTER From The English Alphabet !!!\n\n", ch_nrl);
		}

		else if (ch_value_nrl >= CHAR_DIGIT_BEGINNING && ch_value_nrl <= CHAR_DIGIT_ENDING)
		{
			printf("Character \'%c\' Entered By You, Is A DIGIT CHARACTER !!!\n\n", ch_nrl);
		}
		else
		{
			printf("Character \'%c\' Entered By You, Is A SPECIAL CHARACTER !!!\n\n", ch_nrl);
		}
		break;
	}

	printf("Switch Case Block Complete !!!\n");

	return (0);
}