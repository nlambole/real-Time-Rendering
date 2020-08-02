#include <stdio.h>

//Defining Struct 
struct MyData
{
	int* ptr_i_nrl;
	int i_nrl;

	float* ptr_f_nrl;
	float f_nrl;

	double* ptr_d_nrl;
	double d_nrl;
};

int main(void)
{
	//Variable Declarations
	struct MyData* pData = NULL;

	//Code
	printf("\n\n");
	pData = (struct MyData*)malloc(sizeof(struct MyData));
	if (pData == NULL)
	{
		printf("Failed to allocate memory to 'struct Mydata' !!!!!! Exiting Now...\n\n");
		exit(0);
	}
	else
		printf("Successfully Allocated Memory To 'struct MyData' !!!!!!\n\n");

	pData->i_nrl = 9;
	pData->ptr_i_nrl = &(pData->i_nrl);

	pData->f_nrl = 11.45f;
	pData->ptr_f_nrl = &(pData->f_nrl);
	
	pData->d_nrl = 30.121995;
	pData->ptr_d_nrl = &(pData->d_nrl);

	printf("\n\n");
	printf("i = %d\n", *(pData->ptr_i_nrl));
	printf("Adress Of 'i' = %p\n", pData->ptr_i_nrl);
	printf("\n\n");
	printf("f = %f\n", *(pData->ptr_f_nrl));
	printf("Adress Of 'f' = %p\n", pData->ptr_f_nrl);
	printf("\n\n");
	printf("d = %lf\n", *(pData->ptr_d_nrl));
	printf("Adress Of 'd' = %p\n", pData->ptr_d_nrl);

	if (pData)
	{
		free(pData);
		pData = NULL;
		printf("Memory Allocated To 'struct MyData' Has Been Successfully Freed !!\n\n");
	}

	return(0);

}

