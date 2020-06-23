#include <stdio.h>

// ***Global Scope ***

int main(void)
{
	// *** Local Scope Of main() begins ***

	// Variable Declarations 
	// 'a' is a Local Variables. It is local to main() only.
	int a_nrl = 5;

	// function prototypes 
	void change_count(void);

	// code 
	printf("\n A = %d \n\n", a_nrl);

	// local_count is initialized to 0.
	// local_count = local_count + 1 = 0 + 1 = 1

	change_count();

	// Since, 'local_count' is local static varaible of change_count(), it WILL retain its value from previous call to change_count().
	// soo local_count is 1
	// local_count = local_count + 1 = 1 + 1 = 2
	change_count();

	// Since, 'local_count' is local static varaible of change_count(), it WILL retain its value from previous call to change_count().
	// soo local_count is 1
	// local_count = local_count + 1 = 2 + 1 = 3

	return(0);

	// *** Local Scope Of main() ends ***
}

// *** Global Scope ***

void change_count(void)
{
	// Local Scope Of change_count() begins 

	// Varaible Declaration 
	// 'local_count' is a Local Static Variable. It is local to change_count() only

	// It Will retain its value between call to change_count()

	static int local_count = 0;

	// Code 
	local_count = local_count + 1;
	printf("Local Count = %d\n", local_count);

	// *** Loal Scope Of change_count() ends ***
}

// *** Global Scope ***
