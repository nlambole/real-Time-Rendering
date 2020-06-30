#include <stdio.h>	
enum
{
	NEGATIVE = -1,
	ZERO,
	POSITIVE
};

int main(void)
{
	//Functions Delclarations
	int Difference(int, int, int*);

	//Variable Declarations
	int a_nrl;
	int b_nrl;
	int answer_nrl, ret_nrl;

	//Code
	printf("\n\n Enter Value Of 'A' : ");
	scanf("%d", &a_nrl);

	printf("\n\n ENter Value Of 'B' : ");
	scanf("%d", &b_nrl);

	ret_nrl = Difference(a_nrl, b_nrl, &answer_nrl);
	printf("\n\n Difference Of %d And %d =%d\n\n", a_nrl, b_nrl, answer_nrl);

	if (ret_nrl == POSITIVE)
		printf("The Difference Of %d And %d Is Positive !!!\n\n", a_nrl, b_nrl);

	else if (ret_nrl == NEGATIVE)
		printf("The Difference Of %d And %d Is Positive !!!\n\n", a_nrl, b_nrl);

	else
		printf("The Difference Of %d And %d Is Zero !!!\n\n", a_nrl, b_nrl);

	return(0);

}

//We want our Function Difference() To Perform 2 JOBs...
//One, Is to substract the input numbers ('y' From 'x') and The Second, Is To Tell Whether The Difference Of 'X' And 'y' Is Positive or Negative or Zero...
// But Any Function Has Only One Valid Return Vlaue, The How Can We Manage To Return Two Values To The  Calling Function?
//This Is Where Parameterized Return Vlaue COmes Into The Picture...
//We can return The Actual Difference Of 'x' And 'y', That Is, The Actual Answer Value, VIA Out_Parameter / Parameterized Return Vlaue 
// And We Can Return The Status Of The Answer  (Positive / Negative / Zero) Via The Actual Return Vlaue Of The Functions...

int Difference(int x, int y, int* diff)
{
	//Code
	*diff = x - y;

	if (*diff > 0)
		return(POSITIVE);

	else if (*diff < 0)
		return(NEGATIVE);

	else
		return(ZERO);
}