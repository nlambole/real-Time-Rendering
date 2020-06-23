#include <stdio.h>
int main(void)
{
	// Variable Declarations

	int iArray_nrl[] = { 9, 30, 6, 12, 98, 95, 20, 23, 2, 45 };
	int int_size_nrl;
	int iArray_size_nrl;
	int iArray_num_elements_nrl;

	float fArray_nrl[] = { 1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f,7.8f,8.9f };
	int float_size_nrl;
	int fArray_size_nrl;
	int fArray_num_elements_nrl;

	char cArray_nrl[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P' };
	int char_size_nrl;
	int cArray_size_nrl;
	int cArray_num_elements_nrl;

	int i_nrl;

	//code

	// ***** iArray[] *****

	printf("\n\n Inline Initialization ANd Loop (for) Display Of Elements of Array 'iArray[]' : \n\n");
	int_size_nrl = sizeof(int);
	iArray_size_nrl = sizeof(iArray_nrl);
	iArray_num_elements_nrl = iArray_size_nrl / int_size_nrl;

	for (i_nrl = 0; i_nrl < iArray_num_elements_nrl; i_nrl++)
	{
		printf("iArray[%d] (Element %d) = %d\n", i_nrl, (i_nrl + 1), iArray_nrl[i_nrl]);
	}

	printf("\n\n Size Of Data type 'int' = %d bytes\n", int_size_nrl);
	printf("Number Of Elements In 'int' Array 'iArray[]' = %d bytes\n", iArray_num_elements_nrl);
	printf("Size Of Array 'iArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", iArray_num_elements_nrl, int_size_nrl, iArray_size_nrl);

	// *** fArray[] ***

	printf("\n\n In-Line Initialization And Loop (while) Display Of Elements of Array 'fArray[]' : \n\n");

	float_size_nrl = sizeof(float);
	fArray_size_nrl = sizeof(fArray_nrl);
	fArray_num_elements_nrl = fArray_size_nrl / float_size_nrl;

	i_nrl = 0;

	while (i_nrl < fArray_num_elements_nrl)
	{
		printf("fArray[%d] (Elements %d) = %f\n", i_nrl, (i_nrl + 1), fArray_nrl[i_nrl]);
		i_nrl++;
	}

	printf("\n\n Size Of Data Types 'float' = %d bytes \n", float_size_nrl);
	printf("Number Of Elements In 'float' Array 'fArray[]' = %d Elements \n	", fArray_num_elements_nrl, float_size_nrl, fArray_size_nrl);
	

	// ***** cArray[] *****

	printf("\n\n In-Line Initialization And Loop (do while) Display Of Elements Of Array 'cArray[]' : \n\n	");

	char_size_nrl = sizeof(char);
	cArray_size_nrl = sizeof(cArray_nrl);
	cArray_num_elements_nrl = cArray_size_nrl / char_size_nrl;

	i_nrl = 0;
	do
	{
		printf("cArray[%d] (Elements %d) = %c\n\n", i_nrl, (i_nrl + 1), cArray_nrl[i_nrl]);
		i_nrl++;
	} while (i_nrl < cArray_num_elements_nrl);
	
	printf("\n\n Size Of Data types 'char' = %d bytes\n", char_size_nrl);
	printf("Number Of Elements In 'char' Array 'cArray[]' = %d Elements \n	", cArray_num_elements_nrl);
	printf("Size Of Array 'cArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", cArray_num_elements_nrl, char_size_nrl, cArray_size_nrl);

	return(0);

}



