#include  <stdio.h>
#include <stdlib.h> //Contains prototypes of malloc() and free()	

int main(void)
{
	//Variable Declarations
	int* ptr_iArray_nrl = NULL; //It Is Good Discipline To Initialize Any Pointer With Null Address To Prevent ANy Garbage Vlaue Geetting Into It, That Way, It Makes It Easy To Check For Success OR Failure Of Memore Allocations Later On After malloc()...

	unsigned int intArrayLength = 0;
	int i_nrl;

	// code
	printf("\n\n\ Enter The Number Of Elements You Want In Your Integer Array : ");
	scanf("%d", &intArrayLength);
	
	// **** Allocating Ad Much Memory Requred To The Integer Array *****
	// **** Memory Required For Integer Array = Size In Byted Of One Integer * Number OF Integers TO Be Stored In Array ****
	// **** To Allocate Said Ammount Of Memory, Functions malloc() Will Be Used  *****
	// **** malloc() Will Allocate Said Amount  Of Memmory, Which Must Be Captured In A Pointer Variable ***
	// **** malloc() Will Allocate Said Amount Of Memory And Will Return The Initial / Starting / Base Address Of The Allocated Memory, Ehich Must Be Captured In A Pointer Variable ****
	// **** Using This Base Address, The Integer Array Can Be Accessed And Used...****

	ptr_iArray_nrl = (int*)malloc(sizeof(int) * intArrayLength);
	if (ptr_iArray_nrl == NULL) // IF ptr_iArray Is Still Null, Even After Call To malloc(), It Means malloc() Has failde to Allocate Memory And No Address Has Returned By malloc() in ptr_iArray...
	{
		printf("\n\n Memory Allocation For Integer Array Has failed !!! Exitting Now...\n\n");
		exit(0);

	}
	else // If ptr_iArray Is Not Null, It Means It Must Contian A Valid Address Which Is Returned by malloc(), Hence, malloc() Has Succceeded In Memory Allocations..
	{
		printf("\n\n Memory Allocation For Integer Array Had Succeeded !!! \n\n");
		printf("Memory Addres From %p To %p Have Been Allocated To Integer Array !!!\n\n", ptr_iArray_nrl, (ptr_iArray_nrl + (intArrayLength -1)));
	}

	printf("\n\n Enter For The Integer Array : \n\n", intArrayLength);
	for (i_nrl = 0; i_nrl < intArrayLength; i_nrl++)
		scanf("%d", (ptr_iArray_nrl + 1));
		printf("\n\n THe Integer Array Entered By By You, Consisting Of %d Elements : \n\n", intArrayLength);

		for (i_nrl = 0; i_nrl < intArrayLength; i_nrl++)
		{
			printf("ptr_iArray[%d] = %d \t\t At Address &ptr_iArray[%d] : %p\n", i_nrl, ptr_iArray_nrl[i_nrl], i_nrl, &ptr_iArray_nrl[i_nrl]);
		}
		printf("\n\n");

		for (i_nrl = 0; i_nrl < intArrayLength; i_nrl++)
		{
			printf("*(ptr_iArray + %d) = %d \t\t At Address (ptr_iArray + %d) :\n\n", i_nrl, *(ptr_iArray_nrl + i_nrl), i_nrl, (ptr_iArray_nrl + i_nrl));

		}

		// **** Checking If Memory Is Still Allocated By Checking Validity Of Base Address 'ptr_iArray' ***
		// **** If Address Is Valid, That is if 'ptr_iArray' Exists, That Is, If It Is Not Null, Memory Is Still Allocated *****
		// **** In That Case, The Allocatde Using malloc() And Freed Using free() ****
		// **** Once Memory Is Freed free(), The Base Address Must Be Cleaned, That Is, It Must Be Re-Initialized To 'Null' To Keep Away Garbage Value. This Is Not Compulsory, But It Is Good Coding Disciline ****

		if (ptr_iArray_nrl)
		{
			free(ptr_iArray_nrl);
			ptr_iArray_nrl = NULL;

			printf("\n\n Memory Allocated For Integer Array Has Been Successfully Freed !!!\n\n");
		}

		return(0);

}