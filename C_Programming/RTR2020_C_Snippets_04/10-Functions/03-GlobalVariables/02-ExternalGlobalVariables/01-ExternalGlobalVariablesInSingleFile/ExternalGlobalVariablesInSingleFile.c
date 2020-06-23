#include <stdio.h>

// ** Global Scope 

int main(void)
{
	void change_count(void);

		//Variable declarations
		extern int global_count;

	// Code
	printf("\n");
	printf("Value Of global_count before change_count() = %d\n", global_count);

	change_count();
	printf("Value Of global_count after change_count() = %d \n\n", global_count);
	return(0);
}

// *** Global Scope ***
// Global_count is a global variable.
// Since, it is declared before change_count(), it can be accssed and used as any ordinary global variable in change_count()
// Since, it is declared after main(), it must be first re-declared in main() as external global variable by means of the 'extern' keyboard and the tyes of the variable 
// once this is done, it can be used as an ordinary global varible in main as well

int global_count = 0;

void change_count(void)
{
	//Code
	global_count = 5;
	printf("Value Of global_count in change_count() = %d \n\n", global_count);
}