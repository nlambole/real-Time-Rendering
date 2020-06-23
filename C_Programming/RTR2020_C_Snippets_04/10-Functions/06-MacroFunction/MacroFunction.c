#include <stdio.h>


#define MAX_NUMBER(a, b) ((a > b) ? a : b)

int main(int argc, char* argv[], char* envp[])
{
	// Varibale Declarations
	int iNum_01_nrl;
	int iNum_02_nrl;
	int iResult;

	float fNum_01_nrl;
	float fNum_02_nrl;
	float fResult;

	// Code
	// ***** Comparing Integer Values *****
	printf("\n\n Enter An Iteger Number :  \n\n");
	scanf("%d", &iNum_01_nrl);

	printf("\n\n Enter Another Integer Number : \n\n ");
	scanf("%d", &iNum_02_nrl);

	iResult = MAX_NUMBER(iNum_01_nrl, iNum_02_nrl);
	printf("\n\n Result Of Macro Function MAX_NUMBER() = %d\n", iResult);

	printf("\n\n");

	// ***** Comparing Floating-Point Values ****
	printf("\n\n Enter A FLoating Point Number : \n\n");
	scanf("%f", &fNum_01_nrl);

	printf("\n\n Enter Another Floating Point Number : \n\n");
	scanf("%f", &fNum_02_nrl);

	fResult = MAX_NUMBER(fNum_01_nrl, fNum_02_nrl);
	printf("\n\n Result Of Macro Function MAX_NUMBER () = %f \n\n\n	", fResult);

	return(0);

}