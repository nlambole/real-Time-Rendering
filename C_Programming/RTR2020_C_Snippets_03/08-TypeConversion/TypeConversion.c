#include <stdio.h>

int main(void)
{
	//variable declarations
	int i_nrl, j_nrl;
	char ch_01, ch_02;

	int a_nrl;
	int result_int;
	float f_nrl, result_float;

	int i_explicit;
	float f_explicit;

	//code 
	printf("\n\n");

	//Interconversion And Implicit Type-Casing Between 'char' and 'int' Types...
	i_nrl = 70;
	ch_01 = i_nrl;
	printf("I = %d\n", i_nrl);
	printf("Character 1 (after ch_01 = i_nrl) = %c\n\n", ch_01);

	ch_02 = 'Q';
	j_nrl = ch_02;
	printf("Character 2 = %c\n", ch_02);
	printf("J (after j = ch_02)=%d\n\n", j_nrl);

	//Implicit conversion of 'int' to 'float'...
	a_nrl = 5;
	f_nrl = 7.8f;
	result_float = a_nrl + f_nrl;
	printf("Integer a=%d and Floating-Point number %f Added gives Floating-Point Sum = %f\n\n", a_nrl, f_nrl, result_float);
	
	result_int = a_nrl + f_nrl;
	printf("Integer a = %d and Floating-Point number %f gives integer Sum = %d\n\n", a_nrl, f_nrl, result_int);

	//Explicit type-Casting using operator...
	f_explicit = 30.121995f;
	i_explicit = (int)f_explicit;
	printf("Floating point number which will be type casted explicitly = %f\n", f_explicit);
	printf("Resultant integer after explicit type casting of %f = %d\n\n", f_explicit, i_explicit);

	return(0);
}