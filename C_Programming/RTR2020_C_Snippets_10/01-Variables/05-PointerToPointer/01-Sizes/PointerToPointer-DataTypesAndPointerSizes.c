#include <stdio.h>	

struct Employee
{
	char name_nrl[100];
	int age_nrl;
	float salary_nrl;
	char sex_nrl;
	char marital_status_nrl;

};

int main(void)
{
	//Code
	printf("\n\n Size Of Data Types And Pointers To Those Respective Data Types Are : \n\n");
	printf("Size Of (int)      :%d \t\t\t Size of Pointer To int (int*)       :%d\t\t\t Size of pointer to pointer to int (int**)			:%d\n\n ", sizeof(int), sizeof(int*), sizeof(int**));
	printf("Size Of (float)    :%d \t\t\t Size Of Pointer To float (float*)   :%d\t\t\t Size of pointer to pointer to float (int**)         :%d\n\n", sizeof(float), sizeof(float*), sizeof(float**));
	printf("Size Of (double)   :%d \t\t\t Size Of Pointer To double (double*) :%d\t\t\t Size Of Pointer to pointer to double (double**)     :%d\n\n", sizeof(double), sizeof(double*), sizeof(double**));
	printf("Size Of (char)     :%d \t\t\t Size Of Pointer To char (char*)     :%d\t\t\t Size Of Pointer to pointer to double (char**)       :%d\n\n", sizeof(char), sizeof(char*), sizeof(char**));
	printf("Size Of (struct Employee) :%d\t\t\t Size Of Pointer To struct Employee (struct Employee*) : %d \t\t\t Size Of Pointer to Pointer (struct Employee**) :%d\n\n", sizeof(struct Employee), sizeof(struct Employee*), sizeof(struct Employee**));
	return(0);

}