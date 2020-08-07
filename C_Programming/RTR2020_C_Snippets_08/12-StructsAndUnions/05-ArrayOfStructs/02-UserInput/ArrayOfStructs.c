#include <stdio.h>	
#include < ctype.h>

#define NUM_EMPLOYEES 5 // Simply Change this constant value to have as many number of Employee Records as you please...

#define NAME_LENGTH 100
#define MARTTAL_STATUS 10

struct Employee
{
	char name_nrl[NAME_LENGTH];
	int age_nrl;
	char sex_nrl;
	float salary_nrl; 
	char marital_status_nrl;
};

int main(void)
{
	//Functions Prototype 
	void MyGetStrings(char[], int);

	//Variable Declarations
	struct Employee EmployeeRecord_nrl[NUM_EMPLOYEES]; //An Array of <NUM_EMPLOYEES> structs - Each being type 'struct Employee'

	int i_nrl;

	//Code
	// ****** User Input Initializations Of array of 'struct Employee' *****
	for (i_nrl = 0; i_nrl < NUM_EMPLOYEES; i_nrl++)
	{
		printf("\n\n\n\n\n");
		printf("********** Data Entry For Employee Number %d ********\n", (i_nrl + 1));

		printf("\n\n Enter Employee Name : ");
		MyGetStrings(EmployeeRecord_nrl[i_nrl].name_nrl, NAME_LENGTH);

		printf("\n\n\n Enter Employee's Age (in Year) : ");
		scanf("%d", &EmployeeRecord_nrl[i_nrl].age_nrl);

		printf("\n\n Enter Employee's Sex (M/m For Male, F/f For Female ) : ");
		EmployeeRecord_nrl[i_nrl].sex_nrl = getch();
		printf("%c", EmployeeRecord_nrl[i_nrl].sex_nrl);
		EmployeeRecord_nrl[i_nrl].sex_nrl = toupper(EmployeeRecord_nrl[i_nrl].age_nrl);


		printf("\n\n Enter Employee's Salary (in Indian Rupees) : ");
		scanf("%f", &EmployeeRecord_nrl[i_nrl].salary_nrl);

		printf("\n\n Is The Employee Married ? (Y/y For Yes, N/n For No) : ");
		EmployeeRecord_nrl[i_nrl].marital_status_nrl = getch();
		printf("%c", EmployeeRecord_nrl[i_nrl].marital_status_nrl);
		EmployeeRecord_nrl[i_nrl].marital_status_nrl = toupper(EmployeeRecord_nrl[i_nrl].marital_status_nrl);
	}

	// **** Display ****
	printf("\n\n\n\n Displaying Employee Records ********\n\n");
	for (i_nrl = 0; i_nrl < NUM_EMPLOYEES; i_nrl++)
	{
		printf("******** Employee Number %d *********\n\n", (i_nrl + 1));
		printf("Name            : %s\n", EmployeeRecord_nrl[i_nrl].name_nrl);
		printf("Age             :%d years \n", EmployeeRecord_nrl[i_nrl].age_nrl);

		if (EmployeeRecord_nrl[i_nrl].sex_nrl == 'M')
			printf("Sex            : Male\n");
		else if (EmployeeRecord_nrl[i_nrl].sex_nrl == 'F')
			printf("Sex            : Female\n");
		else
			printf("Sex            : Invalid Data Entered \n");

		printf("Salary              : Rs. %f\n", EmployeeRecord_nrl[i_nrl].salary_nrl);
			
		if (EmployeeRecord_nrl[i_nrl].marital_status_nrl == 'Y')
			printf("Marital Status : Married\n");
		else if (EmployeeRecord_nrl[i_nrl].marital_status_nrl == 'N')
			printf("Marital Status : Unmarried\n");
		else
			printf("Marital Status : Invalid Data Entered\n");

		printf("\n\n\n");
	}
	return(0);
}


// **** Simple Rudimentary Implementations of gets_s() ***
// **** Implememted Due To Different Behaviour of gets_s() / fgets() / fscanf() ON Different Platforms ***
//Backspace / Character Deletion AND Arrow Key Cursor Movement Not Implemented ***

void MyGetStrings(char str[], int str_size)
{
	//Varaibler Declarations
	int i_nrl;
	char ch = '\0';

	// Code
	i_nrl = 0;
	do
	{
		ch = getch();
		str[i_nrl] = ch;
		printf("%c", str[i_nrl]);
		i_nrl++;

	} while ((ch != '\r') && (i_nrl < str_size));

	if (i_nrl == str_size)
		str[i_nrl - 1] = '\0';
	else
		str[i_nrl] = '\0';
}