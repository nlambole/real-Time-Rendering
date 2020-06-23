#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// *** User Defined Function : Methods Of Calling Finction 3 ***
// *** Calling Only One Function Directly In main(), rest Of The Functions Trace Thier Call Indirectly To main() ***

int main(int argc, char* argv[], char* envp[])
{
	//Function Prototypes 
	void Function_Country();

	// Code
	Function_Country();
	return(0);
}

void Function_Country(void) // Function Definition
{
	// Function Declarations
	void Function_ofAMC(void);

	//Code
	Function_ofAMC();
	printf("\n\n I Live In India. \n\n");

}

void Function_ofAMC(void) //Function Definition
{
	//Function Declarations
	void Function_Surname(void);

	//Code
	Function_Surname();

	printf("\n\n Of ASTROMEDICOMP");

}

void Function_Surname(void) //Function Definition
{
	//Function Declarations
	void Function_MiddleName(void);

	//Code
	Function_MiddleName();

	printf("\n\n Lambole");
}

void Function_MiddleName(void) //Function Declaration
{
	// Function Declarations
	void Function_FirstName(void);

		//Code 
		Function_FirstName();

	printf("\n\n Raghunath");
}

void Function_FirstName(void) //function definition
{
	// function declarations
	void Function_Is(void);
	// code
	Function_Is();
	printf("\n\n");
	printf("Nandlal");
}

void Function_Is(void) // Function Definition
{
	// Function Declaration
	void Function_My(void);

	//Code
	Function_My();

	printf("\n\n Name");
}

// *** User-Defined Function's Definition...***
void Function_My(void) //Function Definition
{
	//Code
	printf("\n\n My");
}