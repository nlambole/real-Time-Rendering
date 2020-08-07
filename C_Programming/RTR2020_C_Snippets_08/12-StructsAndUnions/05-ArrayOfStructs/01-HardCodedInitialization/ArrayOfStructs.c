#include <stdio.h>

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{
	char name_nrl[NAME_LENGTH];
	int age_nrl;
	float salary_nrl;
	char sex_nrl;
	char marital_status_nrl[MARITAL_STATUS];

};

int main(void)
{
	//Varaible Declarations
	struct Employee EmployeeRecord_nrl[5]; // An Array of 5 structs -Each beigh type 'struct Employee'

	char employee_rajesh[] = " Rajesh";
	char employee_sameer[] = "Sameer";
	char employee_kalyani[] = "Kalyani";
	char employe_sonali[] = "Soanli";
	char employee_shantanu[] = "Shantanu";

	int i_nrl;

	//Code
	// ***** Hard_Coded Initialization Of Array Of 'struct Empolyee' ****

	// ***** Employee 1 ******
	strcpy(EmployeeRecord_nrl[0].name_nrl, employee_rajesh);
	EmployeeRecord_nrl[0].age_nrl = 30;
	EmployeeRecord_nrl[0].sex_nrl = 'M';
	EmployeeRecord_nrl[0].salary_nrl = 50000.0f;
	strcpy(EmployeeRecord_nrl[0].marital_status_nrl, "UnMarried");

	// ***** Employee 2 *****
	strcpy(EmployeeRecord_nrl[1].name_nrl, employee_sameer);
	EmployeeRecord_nrl[1].age_nrl = 32;
	EmployeeRecord_nrl[1].sex_nrl = 'M';
	EmployeeRecord_nrl[1].salary_nrl = 60000.0f;
	strcpy(EmployeeRecord_nrl[1].marital_status_nrl, "Married");

	// ***** Employee 3 ******
	strcpy(EmployeeRecord_nrl[2].name_nrl, employee_kalyani);
	EmployeeRecord_nrl[2].age_nrl = 29;
	EmployeeRecord_nrl[2].sex_nrl = 'F';
	EmployeeRecord_nrl[2].salary_nrl = 62000.0f;
	strcpy(EmployeeRecord_nrl[2].marital_status_nrl, "UnMarried");

	// ***** Employee 4 *****
	strcpy(EmployeeRecord_nrl[3].name_nrl, employe_sonali);
	EmployeeRecord_nrl[3].age_nrl = 33;
	EmployeeRecord_nrl[3].sex_nrl = 'F';
	EmployeeRecord_nrl[3].salary_nrl = 50000.0f;
	strcpy(EmployeeRecord_nrl[3].marital_status_nrl, "Married");

	// ****** Employee 5 *****
	strcpy(EmployeeRecord_nrl[4].name_nrl, employee_shantanu);
	EmployeeRecord_nrl[4].age_nrl = 35;
	EmployeeRecord_nrl[4].sex_nrl = 'M';
	EmployeeRecord_nrl[4].salary_nrl = 55000.0f;
	strcpy(EmployeeRecord_nrl[4].marital_status_nrl, "Married");

	// *** Display *****
	printf("\n\n ********** Displaying Employee Records **** \n\n");
	for (i_nrl = 0; i_nrl < 5; i_nrl++)
	{
		printf("Name          : %s\n", EmployeeRecord_nrl[i_nrl].name_nrl);
		printf("Age           :%d years\n", EmployeeRecord_nrl[i_nrl].age_nrl);

		if (EmployeeRecord_nrl[i_nrl].sex_nrl == 'M' || EmployeeRecord_nrl[i_nrl].sex_nrl == 'm')
			printf("Sex             : Male\n");
		else
			printf("Sex             : Female\n");

		printf("Salary            : Rs. %f\n", EmployeeRecord_nrl[i_nrl].salary_nrl);
		printf("Marital Status : %s\n", EmployeeRecord_nrl[i_nrl].marital_status_nrl);


		printf("\n\n");
	}

	return(0);
}