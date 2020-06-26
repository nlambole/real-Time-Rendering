#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
	// Varaibles Declarartions
	char chArray_One_nrl[MAX_STRING_LENGTH], chArray_Two_nrl[MAX_STRING_LENGTH]; // A Character ArrayIs A STRING

	// COde
	// *** STRING INPUT ***

	printf("\n\n Enter First String : \n\n ");
	gets_s(chArray_One_nrl, MAX_STRING_LENGTH);

	printf("\n\n Enter Second String : \n\n ");
	gets_s(chArray_Two_nrl, MAX_STRING_LENGTH);

	// *** STRING CONCAT ***
	printf("\n\n ********** BEFORE CONCATENATION *********\n");
	printf("\n\n The Original First String Entered By You (i.e. : 'chArray_One[]') Is : \n\n");
	printf("%s\n", chArray_One_nrl);

	printf("\n\n The Original Second String Entered By You (i. e. : 'chArray_Two[]') Is \n\n	");
	printf("%s\n", chArray_Two_nrl);

	strcat(chArray_One_nrl, chArray_Two_nrl);

	printf("\n\n ******** AFTER CONCATENATION*********\n\n");
	printf("\n\n chArray_One[] Is : \n\n");
	printf("%s\n", chArray_One_nrl);

	printf("\n\n chArray_Two[] Is : \n\n");
	printf("%s\n", chArray_Two_nrl);

	return(0);


}