#include <stdio.h>

// ***  GLOBAL SCOPE ***

int main(void)
{
	// *** Local Scope Of main() Begins ***

	// Variable Declaration 
	// 'a' is Local Variable . It is local to main() obly.

	int a_nrl = 5;

	// Function Prototypes
	void change_count(void);

	// code 
	printf("\n A = %d\n\n", a_nrl);

	// local_count is initialized to 0.
	// local_count = local_count + 1 = 0 + 1 = 1
	change_count();

	// Since, 'local_count' is an ordinary local variable of change_count(), it will NOT retain its value from previous call to change_count().
	// So, local_count is AGAIN intialized to 0
	// local_count = local_count +1 = 0 + 1= 1
	change_count();

	// Since, 'local_count' is an ordinary local variable of change_count(), it will NOT retain its value from previous call to change_count().
		// So, local_count is AGAIN intialized to 0
		// local_count = local_count +1 = 0 + 1= 1
	change_count();

	return(0);

	// *** Local Cope Of main() ends ***

}

// Global Scope ***

void change_count(void)
{
	// *** Local Scope Of change_count() Begins ***

	 //Variable Declaration 
	 // 'local_count' is a Local Variable. It is local to change_count() only.

	int local_count = 0;

	//Code
	local_count = local_count + 1;

	printf("Local Count =%d\n\n", local_count);

}

// **** Global Scope ***