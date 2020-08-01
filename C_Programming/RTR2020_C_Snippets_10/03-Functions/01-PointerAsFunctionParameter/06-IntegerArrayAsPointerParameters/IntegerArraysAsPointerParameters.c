#include <stdio.h>	
#include <stdlib.h>

int main(void)
{
	//Function Declarations
	void MultiplyArrayElementsByNumber(int*, int, int);

	//Variable Declaration
	int* iArray_nrl = NULL;
	int num_elements_nrl;
	int i_nrl, num_nrl;


		//Code
		printf("\n\n Enter How Many Elements You Want In The Integer Array : ");
		scanf("%d", &num_elements_nrl);

		iArray_nrl = (int*)malloc(num_elements_nrl * sizeof(int));
		if (iArray_nrl == NULL)
		{
			printf("Memory Allocation To 'iArray' Has Failed !!! Exiting Now...\n\n");
			exit(0);
		}

		printf("\n\n Enter %d Elements For The Integer Array : \n\n", num_elements_nrl);
		for (i_nrl = 0; i_nrl < num_elements_nrl; i_nrl++)
			scanf("%d", &iArray_nrl[i_nrl]);

		// ***** ONE *****
		printf("\n\n Aray Before Passing To Function MultiplyArrayElementsByNumber() : \n\n");
		for (i_nrl = 0; i_nrl < num_elements_nrl; i_nrl++)
			printf("iarray[%d]  = %d\n",i_nrl, iArray_nrl[i_nrl]);

		printf("\n\n Enter The Number By Which You Want To MultiplyArrayElementBy Number() : \n\n");
		scanf("%d", &num_nrl);

		MultiplyArrayElementsByNumber(iArray_nrl, num_elements_nrl, num_nrl);

		printf("\n\n");
		printf("Array Returned By Function MultiplyArrayElementsByNumber() : \n\n");

		for (i_nrl = 0; i_nrl < num_elements_nrl; i_nrl++)
			printf("iArray[%d] = %d\n",i_nrl, iArray_nrl[i_nrl]);


		if (iArray_nrl)
		{
			free(iArray_nrl);
			iArray_nrl = NULL;
			printf("\n\n Memory allocated to 'iArray' has been successfully freed !!!\n\n");
		}
		return(0);
}

void MultiplyArrayElementsByNumber(int* arr, int iNumElements, int n)
{
	//Variable Declarations
	int i_nrl;

	//code
	for (i_nrl = 0; i_nrl < iNumElements; i_nrl++)
	{
		arr[i_nrl] = arr[i_nrl] * n;
	}
}
