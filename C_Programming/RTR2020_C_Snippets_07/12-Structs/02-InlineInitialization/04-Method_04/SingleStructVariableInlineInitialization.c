#include <stdio.h>	

//Defining Struct
struct MyData
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
	char c_nrl;
};

int main(void)
{
	//Varable Declarations

	//34 will be assigned to 'i' of 'data_one' 
	//3.9 will be assigned to 'f' of 'data_one'
	// 1.23765 will be assigned to 'd' of 'data_one'
	// 'A' will be assigned to 'c' of 'data_one'
	struct MyData data_one = { 35, 3.9f, 1.23765, 'A' }; 

	// 'P' will be assigned to 'i' of 'data_two'... but 'P' is a character (char) and 'i' is an integer ... so 'P' is converted into it decimal integer ASCII value(80) and 80 is assigned to 'i' of data_two
	// 6.2 will be assigned to 'f' of 'data_two'
	// 12.199523 will be assigned to 'd' of 'data_two'
	// 68 will be assigned to 'c' of 'data_two'... but 68 is an integer (int) and 'c' is a 'char' ... so 68 is considered as a decimal ASCII value and its corressponding character('D') is assigned to 'c' of data_two
	struct MyData data_two = { 'P', 6.2f, 12.199523, 68 }; 

	// 36 will be assigned to 'i' of 'data_three'
	// 'G' is 'char', but 'f' of 'data_three' is 'float...hence, 'G' is converted to its decimal integer ASCII value(71) and this in turn is converted to 'float' (71.000000) and then it will be assigned to 'f' of 'data_three'
	// 0.0000000 will be assigned to 'd' of 'data_threee'
	// No character will be assigned to 'c' of 'data_three'
	struct MyData data_three = { 36, 'G' };
		
	// 79 will be assigned to 'i' of 'data_four'
	// 0.000000 will be assigned to 'f' of 'data_four'
	// 0.000000 will be assigned to 'd' of 'data_four'
	// No character will be assigned to 'c' of 'data_four'
	struct MyData data_four = { 79 }; //Inline Initializationn

	//code
	//Displaying Vlaues Of The Data Members Of "struct MyData'
	printf("\n\n Data Memberrs Of 'struct MyData data_one' ARE : \n\n");
	printf("i = %d\n", data_one.i_nrl);
	printf("f = %f\n", data_one.f_nrl);
	printf("d = %lf\n", data_one.d_nrl);
	printf("c = %c\n", data_one.c_nrl);

	printf("\n\n Dataa Members Of 'struct MyData data_one' ARE : \n\n");
	printf("i = %d\n", data_two.i_nrl);
	printf("f = %f\n", data_two.f_nrl);
	printf("d = %lf\n", data_two.d_nrl);
	printf("c = %c\n", data_two.c_nrl);

	printf("\n\n DaTa Members Of 'struct MyData data_one' ARE : \n\n");
	printf("i = %d\n", data_three.i_nrl);
	printf("f = %f\n", data_three.f_nrl);
	printf("d = %lf\n", data_three.d_nrl);
	printf("c = %c\n", data_three.c_nrl);

	printf("\n\n Data Memberss Of 'struct MyData data_one' ARE : \n\n");
	printf("i = %d\n", data_four.i_nrl);
	printf("f = %f\n", data_four.f_nrl);
	printf("d = %lf\n", data_four.d_nrl);
	printf("c = %c\n", data_four.c_nrl);

	return(0);

}