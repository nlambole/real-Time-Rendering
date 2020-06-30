#include <stdio.h>

int main(void)
{
	//Variable Declarations
	int iArray_nrl[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 }; // Integer Array 
	int* ptr_iArray_nrl = NULL; //Integer Pointer

	//code
	// ##### Using Array Name Ad A Array i.e. : Vlaue Of xth Elements Of iArray : iArray[x] And Address Of xth Element Of iArray : &iArray[x] ####
	printf("\n\n **** Using Array Name As A ARRAY i.e. : Value Of xth Element Of iArray : iArray[x] And Address Of xth  Element Of iArray : &iArray[x] ***\n\n");
	printf("Integer Array Elements And Their Addresses : \n\n");
	printf("iArray[0] =%d\t\t At Address &iArray[0] :%p\n", iArray_nrl[0], &iArray_nrl[0]);
	printf("iArray[1] =%d\t\t At Address &iArray[1] :%p\n", iArray_nrl[1], &iArray_nrl[1]);
	printf("iArray[2] =%d\t\t At Address &iArray[2] :%p\n", iArray_nrl[2], &iArray_nrl[2]);
	printf("iArray[3] =%d\t\t At Address &iArray[3] :%p\n", iArray_nrl[3], &iArray_nrl[3]);
	printf("iArray[4] =%d\t\t At Address &iArray[4] :%p\n", iArray_nrl[4], &iArray_nrl[4]);
	printf("iArray[5] =%d\t\t At Address &iArray[5] :%p\n", iArray_nrl[5], &iArray_nrl[5]);
	printf("iArray[6] =%d\t\t At Address &iArray[6] :%p\n", iArray_nrl[6], &iArray_nrl[6]);
	printf("iArray[7] =%d\t\t At Address &iArray[7] :%p\n", iArray_nrl[7], &iArray_nrl[7]);
	printf("iArray[8] =%d\t\t At Address &iArray[8] :%p\n", iArray_nrl[8], &iArray_nrl[8]);
	printf("iArray[9] =%d\t\t At Address &iArray[9] :%p\n", iArray_nrl[9], &iArray_nrl[9]);

	//Assigning Base Address Of Integer Array 'iArray' To Integer Pointer 'ptr_iArray'
	//Name Of Any Array Is Its Own Base Address
	ptr_iArray_nrl = iArray_nrl; //Same as .....ptr_iArray = &iArray[0]	

	// #### Using Pointer As Pointer i.e. : Value Of xth Element Of iArray : *(ptr_iArray + x) And Address Ofxth Element Of iArray : (ptr_iArray + 5) ####

	printf("\n\n *** Using Pointer As Pointer i.e. : Value Of xth Element Of iAray : *(ptr_iArray + x) And Address Of xth Element Of iArray : (ptr_iArray + x) ****\n\n");
	printf("Integer Array Elements And Their Addresses : \n\n");
	printf("*(ptr_iArray + 0) =%d\t\t At Address (ptr_iArray + 0) :%p\n", *(ptr_iArray_nrl + 0), (ptr_iArray_nrl + 0));
	printf("*(ptr_iArray + 1) =%d\t\t At Address (ptr_iArray + 1) :%p\n", *(ptr_iArray_nrl + 1), (ptr_iArray_nrl + 1));
	printf("*(ptr_iArray + 2) =%d\t\t At Address (ptr_iArray + 2) :%p\n", *(ptr_iArray_nrl + 2), (ptr_iArray_nrl + 2));
	printf("*(ptr_iArray + 3) =%d\t\t At Address (ptr_iArray + 3) :%p\n", *(ptr_iArray_nrl + 3), (ptr_iArray_nrl + 3));
	printf("*(ptr_iArray + 4) =%d\t\t At Address (ptr_iArray + 4) :%p\n", *(ptr_iArray_nrl + 4), (ptr_iArray_nrl + 4));
	printf("*(ptr_iArray + 5) =%d\t\t At Address (ptr_iArray + 5) :%p\n", *(ptr_iArray_nrl + 5), (ptr_iArray_nrl + 5));
	printf("*(ptr_iArray + 6) =%d\t\t At Address (ptr_iArray + 6) :%p\n", *(ptr_iArray_nrl + 6), (ptr_iArray_nrl + 6));
	printf("*(ptr_iArray + 7) =%d\t\t At Address (ptr_iArray + 7) :%p\n", *(ptr_iArray_nrl + 7), (ptr_iArray_nrl + 7));
	printf("*(ptr_iArray + 8) =%d\t\t At Address (ptr_iArray + 8) :%p\n", *(ptr_iArray_nrl + 8), (ptr_iArray_nrl + 8));
	printf("*(ptr_iArray + 9) =%d\t\t At Address (ptr_iArray + 9) :%p\n", *(ptr_iArray_nrl + 9), (ptr_iArray_nrl + 9));

	return(0);
}