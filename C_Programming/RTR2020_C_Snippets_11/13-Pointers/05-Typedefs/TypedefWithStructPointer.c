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
	//Varible Declarations
	int i_size_nrl;
	int f_size_nrl;
	int d_size_nrl;
	int struct_MyData_Size_nrl;	
	int pointer_to_struct_MyData_size_nrl;

	typedef struct MyData* MyDataPtr;

	MyDataPtr pData;

	//Code
	printf("\n\n");

	pData = (MyDataPtr)malloc(sizeof(struct MyData));
	if (pData == NULL)
	{
		printf("Failed To Allocate Memory To 'struct MyData' !!! Exiting Now....\n\n");
		exit(0);

	}
	else
		printf("Successfully allocated memory to 'struct MyData' !!!\n\n");


	//Assigning DataValues To The Data Members Of 'struct MyData'
	pData->i_nrl = 30;
	pData->f_nrl = 11.45f;
	pData->d_nrl = 1.2995;

	//Displaying Values Of The Data Members Of 'strucr MyData' 
	printf("\n\n Data Members Of 'struct MyData' ARE : \n\n");
	printf("i = %d\n", pData->i_nrl);
	printf("f = %f\n", pData->f_nrl);
	printf("d = %lf\n", pData->d_nrl);

	//Calculating sizes of The Data Members Of 'struct MyData'
	i_size_nrl = sizeof(pData->i_nrl);
	f_size_nrl = sizeof(pData->f_nrl);
	d_size_nrl = sizeof(pData->d_nrl);

	//Displaying Sizes Of The Members Of 'struct Mydata'
	printf("\n\n Size Of Data Members Of 'struct MyData; ARE : \n\n");
	printf("Size of 'i' = %d bytes\n", i_size_nrl);
	printf("Size of 'f' = %d bytes\n", f_size_nrl);
	printf("Size of 'd' = %d bytes\n", d_size_nrl);

	//Calculating Size Of The entire 'struct MyData'
	struct_MyData_Size_nrl = sizeof(struct MyData);
	pointer_to_struct_MyData_size_nrl = sizeof(MyDataPtr);


	//Displaying Sizes Of The Entire 'struct MyData'
	printf("\n\n Size Of 'stuct MyData' : %d bytes\n\n", struct_MyData_Size_nrl);
	printf("Size Of pointer to 'stuct MyData' : %d bytes \n\n", pointer_to_struct_MyData_size_nrl);
	
	if (pData)
	{
		free(pData);
		pData = NULL;
		printf("Memory Allocated To 'struct MyData' Has Been Successfully Freed !!!\n\n");
	}

	return(0);
}