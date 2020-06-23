#include <stdio.h> // 'stdio.h' contains delclaration of 'printf()'

// *** User Defined Function : Methods of Callling Function 2 ***
// *** Claling Only Two Function Directly In main(), Rest of the Function Trace Their Call Indirectly to main() ***

int  main(int argc, char* argv[], char* envp[])
{
	//Function Prototyoes
	void display_information(void);
	void Function_Country(void);

	//Code
	display_information(); //Function Call
	Function_Country(); //Function Call

	return(0);

}

// *** User-Defined Function Definitions...***
void display_information(void) //Function Declaration 
{
	//Function Prototypes
	void Function_My(void);
	void Function_Name(void);
	void Function_Is(void);
	void Function_FirstName(void);
	void Function_MiddleName(void);
	void Function_Surname(void);
	void Function_ofAMC(void);

	//code

	// *** Functionns Calls ***
	Function_My();
	Function_Name();
	Function_Is();
	Function_FirstName();
	Function_MiddleName();
	Function_Surname();
	Function_ofAMC();
}

void Function_My(void) //Function Definition
{
	//Code
	printf("\n\n My");
}

void Function_Name(void)
{
	//code
	printf("\n\n Name");
}

void Function_Is(void)
{
	//Code
	printf("\n\n Is");
}

void Function_FirstName(void)
{
	//Code
	printf("\n\n Nandlal");
}

void Function_MiddleName(void)
{
	printf("\n\n Raghunath");
}

void Function_Surname(void)
{
	printf("\n\n Lambole");

}

void Function_ofAMC(void)
{
	printf("\n\n of ASTROMEDICOMP");
}

void Function_Country(void)
{
	printf("\n\n I Live In India. \n\n");
}




