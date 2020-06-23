#include <stdio.h>

// *** Global Scope ***
int global_count = 0;

int main(void)
{
	// Function Prototypes 
	void change_count(void);
	void change_count_one(void); // Function Defines in File_01.c
	void change_count_two(void); // Function Defines in File_02.c

	// Code
	printf("\n");

	change_count();
	change_count_one(); // Function Defines in File_01.c
	change_count_two(); // Function Defines in File_02.c

	return(0);
}

void change_count(void)
{
	//Code
	global_count = global_count + 1;
	printf("Global Count = %d \n\n", global_count);
}