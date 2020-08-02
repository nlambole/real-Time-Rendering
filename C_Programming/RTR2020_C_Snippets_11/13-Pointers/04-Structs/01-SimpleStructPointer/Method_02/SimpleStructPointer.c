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
	//Variable Declarations
	int i_size_nrl;
	int f_size_nrl;
	int d_size_nrl;
	int struct_MyData_size_nrl;
	int pointer_to_struct_MyData_size_nrl;

	struct MyData* pData = NULL;

	//code
	printf("\n\n ");

	pData = (struct MyData*)malloc(sizeof(struct MyData));
	if (pData == NULL)
	{
		printf("Failed To Allocate Memory To 'struct MyData' !!! Exiting Now....\n\n");
		exit(0);
	}

	else
		printf("Successfully Allocated Memory To 'struct MyData' !!!\n\n");

	//Assigning Data Values To The Data Members Of 'struct Mydata'
	pData->i_nrl = 30;
	pData->f_nrl = 11.45f;
	pData->d_nrl = 1.2995;

	//Displaying Values Of The Data Members Of 'struct MyData'
	printf("\n\n Data Mmebers Of 'struct MyData' Are : \n\n");
	printf("i =%d\n", pData->i_nrl);
	printf("f = %f\n", pData->f_nrl);
	printf("d = %lf\n", pData->d_nrl);

	//Calculating Sizes (In Bytes) Of The Data Member Of 'struct MyData'
	i_size_nrl = sizeof(pData->i_nrl);
	f_size_nrl = sizeof(pData->f_nrl);
	d_size_nrl = sizeof(pData->d_nrl);

	//Displaying Sizes of the data members of 'struct mydata'
	printf("\n\n SIZEs of Data Members Of 'struct MYdata' Are : \n\n");
	printf("Size pf 'i' = %d bytes\n", i_size_nrl);
	printf("Size of 'f' = %d bytes\n", f_size_nrl);
	printf("Size Of 'd' = %d bytes\n", d_size_nrl);

	//Calculating size of the entire 'struct MyData'
	struct_MyData_size_nrl = sizeof(struct MyData*);
	pointer_to_struct_MyData_size_nrl = sizeof(struct MyData);

	//Displaying Sizes Of The Entire 'struct MyData '

	printf("\n\n Size of 'struct MyData' : %d bytes \n\n", struct_MyData_size_nrl);
	printf("Size of pointer to 'struct MyData' : %d bytes \n\n	", pointer_to_struct_MyData_size_nrl);
	
	if(pData)
	{
		free(pData);
		pData = NULL;
		printf("Memory Allocated To 'struct MyData' Has Been Successfully Freed !!!\n\n");
	}
	return(0);
}