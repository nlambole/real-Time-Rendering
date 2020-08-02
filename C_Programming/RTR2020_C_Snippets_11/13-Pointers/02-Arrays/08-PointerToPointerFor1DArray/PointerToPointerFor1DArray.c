#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	void MyAlloc(int** ptr, unsigned int numberOfElments);

	//Variable Declarations
	int* piArray_nrl = NULL;
	unsigned int num_elements_nrl;
	int i_nrl;

	//Code
	printf("\n\n How Many Elements You Want In Integer Array ? \n\n");
	scanf("%u", &num_elements_nrl);

	printf("\n\n");
	MyAlloc(&piArray_nrl, num_elements_nrl);

	printf("Enter %u Elements To Fill Up Your Integer Array :\n\n", num_elements_nrl);
	for (i_nrl = 0; i_nrl < num_elements_nrl; i_nrl++)
		scanf("%d", &piArray_nrl[i_nrl]);

	printf("\n\n The %u Elements By You In The Integer Array : \n\n", num_elements_nrl);
	for (i_nrl = 0; i_nrl < num_elements_nrl; i_nrl++)
		printf("%u\n", piArray_nrl[i_nrl]);
	

	printf("\n\n");
	if (piArray_nrl)
	{
		free(piArray_nrl);
		piArray_nrl = NULL;
		printf("Memory Allocated Has Now Been Successfully Freed !!!\n\n");
	}
	return(0);
}

void MyAlloc(int** ptr, unsigned int numberOfElements)
{
	//Code 
	*ptr = (int*)malloc(numberOfElements * sizeof(int));
	if (*ptr == NULL)
	{
		printf("Could Not Allocate Memory !!! Exiting Now...\n\n");
		exit(0);

	}
}
