// *** Global Scope ***
// global_count is a global variable declared in source code file ExternGlobalVariablesInMultiples.c 
// To access it in this file, it must first be re-declared as an external variable in the global scope of this file along with the 'Extern' keyword and its proper data type.
// Then, it can be used as any ordinary global variable throughout this file as well 

#include <stdio.h>

void change_count_two(void)
{
	// Code
	extern int global_count;

	global_count = global_count + 1;

	printf("change_count_two() : Value Of global_count in File_02 = %d \n\n", global_count);
}