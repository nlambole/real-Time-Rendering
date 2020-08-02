#include <stdio.h>

int main(void)
{
	//variable declarations
	int a_nrl;
	int b_nrl;
	int c_nrl;
	int result;

	//code
	printf("\n\n");
	printf("Enter First Integer : ");
	scanf("%d", &a_nrl);

	printf("\n\n");
	printf("Enter Second Integer : ");
	scanf("%d", &b_nrl);

	printf("\n\n");
	printf("Enter Third Integer : ");
	scanf("%d", &c_nrl);

	printf("\n\n");
	printf("If Answer = 0, It Is 'FALSE'.\n\n");
	printf("If Answer = 1, It Is 'TRUE'.\n\n");
	result = (a_nrl <= b_nrl) && (b_nrl != c_nrl);

	printf("LOGICAL AND (&&) : Answer is TRUE (1) If And Only If BOTH Condition Are True. The Answer is FALSE (0), If Any One Or Both Conditions Are False. \n\n");
	printf("A = %d Is Less Than Or Equal To B = %d AND B = %d Is NOT Equal To C = %d \t Answer = %d\n\n", a_nrl, b_nrl, b_nrl, c_nrl, result);
	result = (b_nrl >= a_nrl) || (a_nrl == c_nrl);
	printf("LOGICAL OR (||) : Answer is FALSE (0) If And Only If BOTH Conditions Are False. The Answer is TRUE (1), If Any One Or Both Conditions Are True.\n \n");
	printf("Either B = %d Is Greater Than Or Equal To A = %d OR A = %d Is Equal To C = %d \t Answer = %d\n\n", b_nrl, a_nrl, a_nrl, c_nrl, result);
	
	result = !a_nrl;
	printf("A = %d And Using Logical NOT (!) Operator on A Gives Result = %d\n\n",a_nrl, result);
	
	result = !b_nrl;
	printf("B = %d And Using Logical NOT (!) Operator on B Gives Result = %d\n\n", b_nrl, result);
	
	result = !c_nrl;
	printf("C = %d And Using Logical NOT (!) Operator on C Gives Result = %d\n\n",c_nrl, result);
	
	result = (!(a_nrl <= b_nrl) && !(b_nrl != c_nrl));
	printf("Using Logical NOT (!) On (a_nrl <= b_nrl) And Also On (b_nrl != c_nrl) And then ANDing Them Afterwards Gives Result = %d\n", result);
	printf("\n\n");

	result = !((b_nrl >= a_nrl) || (a_nrl == c_nrl));
	printf("Using Logical NOT (!) On Entire Logical Expression (b_nrl >= a_nrl) || (a_nrl == c_nrl) Gives Result = %d\n", result);

	printf("\n\n");
	return(0);
}