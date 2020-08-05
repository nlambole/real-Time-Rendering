#include <stdio.h>	

//Global typedef
typedef int MY_INT; //"type " int has been re"def"ined as MY_INT... Now, MY_INT can be treated jist like "int"

int main(void)
{
	//Functions Prototype
	MY_INT Add(MY_INT, MY_INT);

	///Typedefs
	typedef int MY_INT; //Type int has been re'def'ined as MY_INT...Now, MY_INT can be treated jist like "int"
	typedef float PVG_FLOAT; // "type' float has been re'def'ined as PVG_FLOAT...

	typedef char CHARACTER;

	typedef double MY_DOUBLE;

	//******* Just Like In Win32SDK !!!! ***
	typedef unsigned int UINT;
	typedef UINT HANDLE;
	typedef HANDLE HWND;
	typedef HANDLE HINSTANCE;

	//Variable Declarations
	MY_INT a_nrl = 10, i_nrl;
	MY_INT iArray_nrl[] = { 9, 18,27,36,45,54,63,72,81,90 };

	PVG_FLOAT f_pvg_nrl = 30.9f;
	const PVG_FLOAT f_pvg_nrl_pi = 3.14f;

	CHARACTER ch_nrl = '*';
	CHARACTER chArray_nrl_01[] = "Hello";
	CHARACTER chArray_nrl_02[][10] = { "RTR", "Batch", "2020-2021" };

	MY_DOUBLE d_nrl = 8.041997;

	// *** Just Random Numbers - They Have Nothing To Do WIth Any Windows's Handle Or Instance Handle !!! THis is just for unsderstanding ***
	UINT uint_nrl = 3456;
	HANDLE handle_nrl = 987;
	HWND hwnd_nrl = 9876;
	HINSTANCE hInstance = 14466;

	//Code
	printf("\n\n Type MY_INT variable a = %d\n", a_nrl);

	printf("\n\n");
	for (i_nrl = 0; i_nrl < (sizeof(iArray_nrl) / sizeof(int)); i_nrl++)
	{
		printf("Type MY_INT array variable iArray[%d] = %d\n	", i_nrl, iArray_nrl[i_nrl]);

	}
	printf("\n\n \n\n");
	printf("Type PVG_FLOAT variable f = %f\n", f_pvg_nrl_pi);
	printf("Type PPVG_FLOAT constant f_pvg_nrl_pi = %f\n", f_pvg_nrl_pi);

	printf("\n\n Type My_Double Variable d = %lf\n", d_nrl);
	printf("\n\n Type Character Variable ch = %c\n", ch_nrl);

	printf("\n\n Type Character array variable chArray_01 = %s\n", chArray_nrl_01);

	printf("\n\n");
	for (i_nrl = 0; i_nrl < (sizeof(chArray_nrl_02) / sizeof(chArray_nrl_02[0])); i_nrl++);
	{
		printf("%s\t", chArray_nrl_02[i_nrl]);
	}
	printf("\n\n \n\n ");
	printf("Type UINT Variable uint = %u\n\n", uint_nrl);
	printf("Type HANDLE varible handle = %u\n\n", handle_nrl);
	printf("Type HWND variable hInstance = %u\n\n", hwnd_nrl);
	printf("Type HINSTANCE variable hInstance = %u\n\n", hInstance);
	printf("\n\n");

	MY_INT x_nrl = 90;
	MY_INT y_nrl = 30;
	MY_INT ret_nrl;

	ret_nrl = Add(x_nrl, y_nrl);
	printf("ret = %d\n\n", ret_nrl);

	return(0);
}

MY_INT Add(MY_INT a_nrl, MY_INT b_nrl)
{
	//Code
	MY_INT c_nrl;

	c_nrl = a_nrl + b_nrl;
	return(c_nrl);
}