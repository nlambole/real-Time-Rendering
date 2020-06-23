#include <stdio.h>

int main(void)
{
	//Variable Declarations
	int iArrayOne_nrl[10];
	int iArrayTwo_nrl[10];

	// code

	// ***** iArrayOne[] ****

	iArrayOne_nrl[0] = 3;
	iArrayOne_nrl[1] = 6;
	iArrayOne_nrl[2] = 9;
	iArrayOne_nrl[3] = 12;
	iArrayOne_nrl[4] = 15;
	iArrayOne_nrl[5] = 18;
	iArrayOne_nrl[6] = 21;
	iArrayOne_nrl[7] = 24;
	iArrayOne_nrl[8] = 27;
	iArrayOne_nrl[9] = 30;

	printf("\n\n Piece-meal (Hard-Coded) Assignment And Display Of Elements TO Array 'iArrayOne[] : \n\n");
	printf("1st ELement Of Array 'iArrayOne[]' Or Element At 0th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne_nrl[0]);
	printf("2nd Element Of Array 'iArrayOne[]' Or Element At 1st Index Of Array 'iArrayOne[]' = %d\n", iArrayOne_nrl[1]);
	printf("3rd Element Od Array 'iArrayOnr[]' Or Element At 2nd Index Of Array 'iArrayOne[]' = %d\n", iArrayOne_nrl[2]);
	printf("4th Element Of Array 'iArrayOne[]' Or Element At 3rd Index Of Array 'iArrayOne[]' = %d\n", iArrayOne_nrl[3]);
	printf("5th Element Of Array 'iArrayOne[]' Or Element At 4th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne_nrl[4]);
	printf("6th Element Of Array 'iArrayOnr[]' Or Element At 5th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne_nrl[5]);
	printf("7th Element Of Array 'iArrayOne[]' Or Element At 6th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne_nrl[6]);
	printf("8th Element Of Array 'iArrayOne[]' Or Element At 7th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne_nrl[7]);
	printf("9th Element Of Array 'iArrayOne[]' Or Element Ar 8th Index Of Array 'iArrayOne[]' = %d\n", iArrayOne_nrl[8]);
	printf("10th Element Of Array 'iArrayOne[]' Or Element At 9th Index Of Array 'iArrauOne[]' =%d\n\n", iArrayOne_nrl[9]);

	// ***** iArrayTwo[] ****

	printf("\n\n Enter 1st Element Of Array 'iArrayTwo[]' : ");
	scanf("%d", &iArrayTwo_nrl[0]);
	printf("Enter 2nd Element Of Array 'iArrayTwo[]' :	");
	scanf("%d", &iArrayTwo_nrl[1]);
	printf("Enter 3rd Element Of Array 'iArrayTwo[] : ");
	scanf("%d", &iArrayTwo_nrl[2]);
	printf("Enter 4th Element Of Array 'iArrayTwo[] :");
	scanf("%d", &iArrayTwo_nrl[3]);
	printf("Enter 5th Element Of Array 'iArrayTwo[]' : ");
	scanf("%d", &iArrayTwo_nrl[4]);
	printf("Enter 6th Element Of Arrray 'iArrayTwo[]' : ");
	scanf("%d", &iArrayTwo_nrl[5]);
	printf("Enter 7th Element Of Array 'iArrayTwo[]' : ");
	scanf("%d", &iArrayTwo_nrl[6]);
	printf("Enter 8th Element Of Array 'iArrayTwo[]' : ");
	scanf("%d", &iArrayTwo_nrl[7]);
	printf("Enter 9th Element Of Array 'iArrayTwo[]' : ");
	scanf("%d", &iArrayTwo_nrl[8]);
	printf("Enter 10th Element of Array  'iArrayTwo[]' : ");
	scanf("%d", &iArrayTwo_nrl[9]);

	printf("\n\n Piece-meal (Hard-Coded) Assignment And Display Of Elements TO Array 'iArrayTwo[] : \n\n");
	printf("1st ELement Of Array 'iArrayTwo[]' Or Element At 0th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo_nrl[0]);
	printf("2nd Element Of Array 'iArrayTwo[]' Or Element At 1st Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo_nrl[1]);
	printf("3rd Element Od Array 'iArrayTwo[]' Or Element At 2nd Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo_nrl[2]);
	printf("4th Element Of Array 'iArrayTwo[]' Or Element At 3rd Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo_nrl[3]);
	printf("5th Element Of Array 'iArrayTwo[]' Or Element At 4th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo_nrl[4]);
	printf("6th Element Of Array 'iArrayTwo[]' Or Element At 5th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo_nrl[5]);
	printf("7th Element Of Array 'iArrayTwo[]' Or Element At 6th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo_nrl[6]);
	printf("8th Element Of Array 'iArrayTwo[]' Or Element At 7th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo_nrl[7]);
	printf("9th Element Of Array 'iArrayTwo[]' Or Element Ar 8th Index Of Array 'iArrayTwo[]' = %d\n", iArrayTwo_nrl[8]);
	printf("10th Element Of Array 'iArrayTwo[]' Or Element At 9th Index Of Array 'iArrayTwo[]' =%d\n\n", iArrayTwo_nrl[9]);

	return(0);


}