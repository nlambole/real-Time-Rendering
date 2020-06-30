#include <stdio.h>

int main(void)
{
	//Variable Declarations
	int iArray_nrl[] = { 12, 24, 36, 48, 60, 72, 84, 96, 108, 120 };
	float fArray_nrl[] = { 9.8f, 8.7f, 7.6f, 6.5f, 5.4f };
	double dArray_nrl[] = { 1.222222, 2.33333, 3.444444 };
	char cArray_nrl[] = { 'A','S','T','R','O', 'M', 'E','D', 'I', 'C','O','M','P','\0' };


	//COde
	printf("\n\n Integer Array Elements And The Addresses They Occupy Are As Follows : \n\n");
	printf("iArray[0] = %d\t At Address : %p\n", *(iArray_nrl + 0), (iArray_nrl + 0));
	printf("iArray[1] = %d\t At Address : %p\n", *(iArray_nrl + 1), (iArray_nrl + 1));
	printf("iArray[2] =%d\t At Address : %p\n", *(iArray_nrl + 2), (iArray_nrl + 2));
	printf("iArray[3] =%d\t At Address :%p\n", *(iArray_nrl + 3), (iArray_nrl + 3));
	printf("iArray[4] =%d\t At Address : %p\n", *(iArray_nrl + 4), (iArray_nrl + 4));
	printf("iArray[5] =%d\t At Address : %p\n", *(iArray_nrl + 5), (iArray_nrl + 5));
	printf("iArray[6] =%d\t At Address :%p\n", *(iArray_nrl + 6), (iArray_nrl + 6));
	printf("iArray[7] =%d\t At Address :%p\n", *(iArray_nrl + 7), (iArray_nrl + 7));
	printf("iArray[8] =%d\t At Address :%p\n", *(iArray_nrl + 8), (iArray_nrl + 8));
	printf("iArray[9] =%d\t At Address :%p\n", *(iArray_nrl + 9), (iArray_nrl + 9));

	printf("\n\n Float Array Elements And The Addresses They Occupy Are As Folloes :\n\n");
	printf("fArray[0] =%f\t At Address :%p\n", *(fArray_nrl + 0), (fArray_nrl + 0));
	printf("fArray[1] =%f\t At Address :%p\n", *(fArray_nrl + 1), (fArray_nrl + 1));
	printf("fArray[2] =%f\t At Address :%p\n", *(fArray_nrl + 2), (fArray_nrl + 2));
	printf("fArray[3] =%f\t At Address :%p\n", *(fArray_nrl + 3), (fArray_nrl + 3));
	printf("fArray[4] =%f\t At Address :%p\n", *(fArray_nrl + 4), (fArray_nrl + 4));
	
	printf("\n\n Double Array Elements And The Addresses They Occupy And As Follows : \n\n");
	printf("dArray[0] =%lf\t At Address :%p\n", *(dArray_nrl + 0), (dArray_nrl + 0));
	printf("dArray[1] =%lf\t At Address :%p\n", *(dArray_nrl + 1), (dArray_nrl + 1));
	printf("dArray[2] =%lf\t At Address :%p\n", *(dArray_nrl + 2), (dArray_nrl + 2));

	printf("\n\n Character Array Elements And The Addresses They Occupy Are As Follows : \n\n");
	printf("cArray[0] =%c\t At Address :%p\n", *(cArray_nrl + 0), (cArray_nrl + 0));
	printf("cArray[1] =%c\t At Address :%p\n", *(cArray_nrl + 1), (cArray_nrl + 1));
	printf("cArray[2] =%c\t At Address :%p\n", *(cArray_nrl + 2), (cArray_nrl + 2));
	printf("cArray[3] =%c\t At Address :%p\n", *(cArray_nrl + 3), (cArray_nrl + 3));
	printf("cArray[4] =%c\t At Address :%p\n", *(cArray_nrl + 4), (cArray_nrl + 4));
	printf("cArray[5] =%c\t At Address :%p\n", *(cArray_nrl + 5), (cArray_nrl + 5));
	printf("cArray[6] =%c\t At Address :%p\n", *(cArray_nrl + 6), (cArray_nrl + 6));
	printf("cArray[7] =%c\t At Address :%p\n", *(cArray_nrl + 7), (cArray_nrl + 7));
	printf("cArray[8] =%c\t At Address :%p\n", *(cArray_nrl + 8), (cArray_nrl + 8));
	printf("cArray[9] =%c\t At Address :%p\n", *(cArray_nrl + 9), (cArray_nrl + 9));
	printf("cArray[10]=%c\t At Address :%p\n", *(cArray_nrl + 10), (cArray_nrl + 10));
	printf("cArray[11]=%c\t At Address :%p\n", *(cArray_nrl + 11), (cArray_nrl + 11));
	printf("cArray[12]=%c\t At Address :%p\n", *(cArray_nrl + 12), (cArray_nrl + 12));
	printf("cArray[13]=%c\t At Address :%p\n", *(cArray_nrl + 13), (cArray_nrl + 13));



	return(0);
}