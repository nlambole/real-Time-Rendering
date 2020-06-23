#include <stdio.h> 

// *** Global Scope ***

// If not initialized by us, global variables are initialized to thier zero values (with respect to their data types i.e. 0 for int , 0.0 float and double, etc.) by default.
// But still, for good programming discipline, we shall explicitly initialize our global variable with 0.

int global_count = 0;

int main(void)
{
	//Function Prototypes 
	void change_count_one(void);
	void change_count_two(void);
	void change_count_three(void);

	//code
	printf("\n");

	printf("main() : Value of global_count = %d \n", global_count);

	change_count_one();
	change_count_two();
	change_count_three();

	printf("\n");
	return(0);
}

// *** GLOBAL SCOPE ***

void change_count_one(void)
{
	//Code
	global_count = 100;
	printf("Change_count_one() : Vlaue of Global Count = %d\n\n", global_count);

}

// *** Global Scope ***

void change_count_two(void)
{
	//Code
	global_count = global_count + 1;
	printf("Change_count_two() : Vlaue of Global Count = %d\n\n", global_count);

}

// *** Global Scope ***

void change_count_three(void)
{
	//Code
	global_count = global_count + 10;
	printf("change_count_three() : Values of global_count = %d\n", global_count);
}

// *** GLobal Scope ***
