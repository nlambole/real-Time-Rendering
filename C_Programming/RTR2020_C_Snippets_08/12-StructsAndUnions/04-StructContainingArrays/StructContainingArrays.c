#include <stdio.h>	

#define INT_ARRAY_SIZE 10
#define FLOAT_ARRAY_SIZE 5
#define CHAR_ARRAY_SIZE 26

#define NUM_STRINGS 10
#define MAX_CHARACTERS_PER_STRING 20

#define ALPHABET_BEGINNING 65 //'A'

struct MyDataOne
{
	int iArray_nrl[INT_ARRAY_SIZE];
	float fArray_nrl[FLOAT_ARRAY_SIZE];

};

struct MyDataTwo
{
	char cArray_nrl[CHAR_ARRAY_SIZE];
	char strArray_nrl[NUM_STRINGS][MAX_CHARACTERS_PER_STRING];

};

int main(void)
{
	//Varaible Declarations
	struct MyDataOne data_one_nrl;
	struct MyDataTwo data_two_nrl;
	int i_nrl;

	//Code
	// *** Piece-Meal Assignment (HArd-Coded) ****
	data_one_nrl.fArray_nrl[0] = 0.1f;
	data_one_nrl.fArray_nrl[1] = 1.2f;
	data_one_nrl.fArray_nrl[2] = 2.3f;
	data_one_nrl.fArray_nrl[3] = 3.4f;
	data_one_nrl.fArray_nrl[4] = 4.5f;

	// *** Loop Assignment (User Input) ***
	printf("\n\n Enter %d Integers : \n\n", INT_ARRAY_SIZE);
	for (i_nrl = 0; i_nrl < INT_ARRAY_SIZE; i_nrl++)
		scanf("%d", &data_one_nrl.iArray_nrl[i_nrl]);

	// ** Loop Assignment (Hard-Coded) ***
	for (i_nrl = 0; i_nrl < CHAR_ARRAY_SIZE; i_nrl++)
		data_two_nrl.cArray_nrl[i_nrl] = (char)(i_nrl + ALPHABET_BEGINNING);

	// **** Piece_Meal Assignment (Hard-Coded) ***
	strcpy(data_two_nrl.strArray_nrl[0], "Welcome !!!");
	strcpy(data_two_nrl.strArray_nrl[1], "This");
	strcpy(data_two_nrl.strArray_nrl[2], "Is");
	strcpy(data_two_nrl.strArray_nrl[3], "ASTROMEDICOMP's");
	strcpy(data_two_nrl.strArray_nrl[4], "Real");
	strcpy(data_two_nrl.strArray_nrl[5], "Time");
	strcpy(data_two_nrl.strArray_nrl[6], "Rendering");
	strcpy(data_two_nrl.strArray_nrl[7], "Batch");
	strcpy(data_two_nrl.strArray_nrl[8], "Of");
	strcpy(data_two_nrl.strArray_nrl[9], "2020-2021");

	// *** Displaying Data Members Of 'struct DataOne' AND Their Values ****
	printf("\n\n Members Of 'struct DataOne' Alongwith Their Assigned Values Are : \n\n");

	printf("\n\nInteger Array (dat_one.iArra[]) : \n\n");
	for (i_nrl = 0; i_nrl < INT_ARRAY_SIZE; i_nrl++)
		printf("data_one.iArray[%d] = %d\n", i_nrl, data_one_nrl.iArray_nrl[i_nrl]);

	printf("\n\n Floating - Point Array (data_one.fArray[[ : \n\n");
	for (i_nrl = 0; i_nrl < FLOAT_ARRAY_SIZE; i_nrl++)
		printf("data_one.fArray[%d] = %f \n", i_nrl, data_one_nrl.fArray_nrl[i_nrl]);

	// *** Displaying Data Members Of 'struct DataTwo' And Their Values ***
	printf("\n\n Members Of 'struct DataTwo' Alongwith Their Assigned Values  Are : \n\n");
	printf("\n\n Character Array (data_two.cArray[] : \n\n");
	for (i_nrl = 0; i_nrl < CHAR_ARRAY_SIZE; i_nrl++)
		printf("data_two.cArray[%d] = %c\n", i_nrl, data_two_nrl.cArray_nrl[i_nrl]);
	
	printf("\n\n String Array (data_two.strArray[] :  \n\n");
	for (i_nrl = 0; i_nrl < NUM_STRINGS; i_nrl++)
		printf("%s", data_two_nrl.strArray_nrl[i_nrl]);

	printf("\n\n");

	return(0);
	
}
