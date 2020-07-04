#include <stdio.h>	
#include <stdlib.h>

#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define CHAR_SIZE sizeof(char)

int main(void)
{
	//Varibale Declarations
	int* ptr_iArray_nrl = NULL;
	unsigned int intArrayLength = 0;

	float* ptr_fArray_nrl = NULL;
	unsigned int floatArrayLength = 0;

	double* ptr_dArray_nrl = NULL;
	unsigned int doubleArrayLength = 0;
	
	char* ptr_cArray_nrl = NULL;
	unsigned int charArrayLength = 0;

	int i_nrl;
	
	//code
	// ****** INTEGER ARRAY *******
	printf("\n\n Enter The Number Of Elements You Want In The Integer Array : ");
	scanf("%u", &intArrayLength);

	ptr_iArray_nrl = (int*)malloc(INT_SIZE * intArrayLength);
	if (ptr_iArray_nrl == NULL)
	{
		printf("\n\n Memory  Allocation For Integer Array Failde !!! Exitting Now...\n\n");
		exit(0);

	}
	else
	{
		printf("\n\n memory Allocation For Integer Array Succede !!!\n\n");

	}

	printf("\n\n Enter The %d Integer Elements TO FIll Up THe Integer Array : \n\n", intArrayLength);
	for (i_nrl = 0; i_nrl < intArrayLength; i_nrl++)
		scanf("%d", (ptr_iArray_nrl + i_nrl));

	//****** FLOAT ARRAY *******
	printf("\n\n Enter The Number Of Elements You Want In The 'float' Array : \n\n");
	scanf("%u", &floatArrayLength);

	ptr_fArray_nrl = (float*)malloc(FLOAT_SIZE * floatArrayLength);
	if (ptr_fArray_nrl == NULL)
	{
		printf("\n\n Memory Allocation For Floating-Point Array Failed !!! Exiting Now...\n\n");
		exit(0);

	}
	else
	{
		printf("\n\n Memory Allocation For Floating-Point Array Succeeded !!!\n\n");

	}

	printf("\n\n Enter The %d Floating-Point Elements To Fill Up The 'float' Array : \n\n", floatArrayLength);
	for (i_nrl = 0; i_nrl < floatArrayLength; i_nrl++)
		scanf("%f", (ptr_fArray_nrl + i_nrl));

	// ******* DOUBLE ARRAY ******
	printf("\n\n Enter The Number Of Elements You Want In the 'double' Array : ");
	scanf("%u", &doubleArrayLength);

	ptr_dArray_nrl = (double*)malloc(DOUBLE_SIZE * doubleArrayLength);
	if (ptr_dArray_nrl == NULL)
	{
		printf("\n\n Memory Allocation For 'Double' Array Failed !!! Existing Now...\n\n");
		exit(0);
	}
	else
	{
		printf("\n\n Memory Allocation For 'Double' Array Succeeded !!!\n\n");
	}

	printf("\n\n Enter The %d Double Elements To Fill Up The 'double' Array : \n\n", charArrayLength);
	scanf("%u", &charArrayLength);

	ptr_cArray_nrl = (char*)malloc(CHAR_SIZE * charArrayLength);
	if (ptr_cArray_nrl == NULL)
	{
		printf("\n\n Memory Allocationn For Character Array Failed !!! Exiting Now...\n\n");
		exit(0);
	}
	else
	{
		printf("\n\n Enter The %d Character Elements To Fill Up The Character Elements To Fill Up The Character Array : \n\n", charArrayLength);

		for (i_nrl = 0; i_nrl < charArrayLength; i_nrl++)
		{
			*(ptr_cArray_nrl + i_nrl) = getch();
			printf("%c\n", *(ptr_cArray_nrl + i_nrl));
		}

		// ************** DIsplay Of Arrays **************
		// **********Integer Array ***********

		printf("\n\n The Integer Entered By You And Consisting Of %d Elements Is As Follows : \n\n", intArrayLength);
		for (i_nrl = 0; i_nrl < intArrayLength; i_nrl++)
			printf("%d \t\t At Address : %p\n", *(ptr_iArray_nrl + 1), (ptr_iArray_nrl + i_nrl));

		// ********** FLOAT ARRAY ***********
		printf("\n\n The Double Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n ", doubleArrayLength);
		for (i_nrl = 0; i_nrl < floatArrayLength; i_nrl++)
			printf("%f\t\t At Address : %p\n", *(ptr_fArray_nrl + i_nrl), (ptr_fArray_nrl + i_nrl++));

		// ********** DOUBLE ARRAY ***********
		printf("\n\n The Double Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n", doubleArrayLength);
		for (i_nrl = 0; i_nrl < doubleArrayLength; i_nrl++)
			printf("%lf \t\t At Address : %p\n", *(ptr_dArray_nrl + i_nrl), (ptr_dArray_nrl + i_nrl));
		
		// ********** CHARACTER ARRAY ********
		printf("\n\n The Character Array Entered By You And Consisting Of %d Elements Is As Follows : \n\n", charArrayLength);
		for (i_nrl = 0; i_nrl < charArrayLength; i_nrl++)
			printf("%c \t\t At Address : %p\n", *(ptr_cArray_nrl + i_nrl), (ptr_cArray_nrl + i_nrl));

		// ********* FREEING MEMORY OCCUPIED BY ARRAYS (IN REVERS ORDER OF ALLOCATION ****
		if (ptr_cArray_nrl)
		{
			free(ptr_cArray_nrl);
			ptr_cArray_nrl = NULL;

			printf("\n\n Memory Occupied By Character Array Has Been Successfully Freed !!!\n\n");
		}

		if (ptr_dArray_nrl)
		{
			free(ptr_dArray_nrl);
			ptr_dArray_nrl = NULL;

			printf("\n\n Memory Occupied By Floating-Point Array Jas Been Successfully Freed !!!!\n\n");
		}

		if (ptr_fArray_nrl)
		{
			free(ptr_iArray_nrl);
			ptr_iArray_nrl = NULL;

			printf("\n\n Memory Occupied By Integer Array Has Been Successfully Freed !!! \n\n");
		}
		
		return(0);
	}


}