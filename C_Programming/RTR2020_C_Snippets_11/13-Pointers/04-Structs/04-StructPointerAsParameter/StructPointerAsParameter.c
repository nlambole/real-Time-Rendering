#include <stdio.h>

//Defining Struct 
struct MyData
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
};

int main(void)
{
	//Functions Prototype
	void ChangeValues(struct MyData*);

	//Variable Declarations
	struct MyData* pData = NULL;

	//code
	printf("\n\n ");

	pData = (struct MyData*)malloc(sizeof(struct MyData));
	if (pData == NULL)
	{
		printf("failed To Allocate Memory To 'struct MyData' !!! Exiting Now....\n\n");
		exit(0);
	}
	else
		printf("Successfully Allocated Memory To 'struct MyData' !!! \n\n");

	//Assigning Data Value To The Data Members Of 'struct MyData' 
	pData->i_nrl = 9;
	pData->f_nrl = 11.45f;
	pData->d_nrl = 1.291995;

	//Displaying Vlaues Of The Data Members Of 'struct MyData'
	printf("\n\n Data Members Of 'struct MyDat' ARE : \n\n");
	printf("i = %d\n", pData->i_nrl);
	printf("f = %f\n", pData->f_nrl);
	printf("d = %lf\n", pData->d_nrl);

	ChangeValues(pData);

	//Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n Data Members Of 'struct MyData' Are : \n\n");
	printf("i = %d\n", pData->i_nrl);
	printf("f = %f\n", pData->f_nrl);
	printf("d = %lf\n", pData->d_nrl);

	if (pData)
	{
		free(pData);
		pData = NULL;
		printf("Memoty Allpocated To 'struct MyData' Has Been Successfully Freed !!!!\n\n");
	}
	return(0);
}

void ChangeValues(struct  MyData* pParam_Data)
{
	//Code

	pParam_Data->i_nrl = 9;
	pParam_Data->f_nrl = 8.2f;
	pParam_Data->i_nrl = 6.1998;

}
