#include <stdio.h>	
#include <ctype.h>	

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

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
	void MyGetString(char[], int);

	//Variable Declarations
	struct Employee* (pEmployeeRecord) = NULL;
	int num_employees_nrl, i_nrl;

	//code
	printf("\n\n Enter Of Employee Whose Details You Want To Record : ");
	scanf("%d", &num_employees_nrl);

	printf("\n\n ");
	pEmployeeRecord = (struct Employee*)malloc(sizeof(struct Employee) * num_employees_nrl);
	if (pEmployeeRecord == NULL)
	{
		printf("Failed to Allocate Memory For %d Employees !!! Exiting Now...\n\n", num_employees_nrl);
		exit(0);
	}
	else
		printf("Successfully Allocated Memory For %d Employees !!!\n\n", num_employees_nrl);

	// **** User Input Initialization Of Array Of 'struct Employee ***
	for (i_nrl = 0; i_nrl < num_employees_nrl; i_nrl++)
	{
		printf("\n\n\n\n  ************ Data Entry For Eployee Number %d ********\n", (i_nrl + 1));

		printf("\n\n");
		printf("Enter Employee Name: ");
		MyGetString(pEmployeeRecord[i_nrl].name_nrl, NAME_LENGTH);

		printf("\n\n\n Enter Employee's Age (in years) L");
		scanf("%d", &pEmployeeRecord[i_nrl].age_nrl);

		printf("\n\n Enter Employee's Sex (M/m For male, F/f For Female :");
		pEmployeeRecord[i_nrl].sex_nrl = getch();

		printf("%c", pEmployeeRecord[i_nrl].sex_nrl);
		pEmployeeRecord[i_nrl].sex_nrl = toupper(pEmployeeRecord[i_nrl].marital_status_nrl);

		printf("\n\n\n");
		printf("Enter Employee's Salary (in Indian Rupees) : ");
		scanf("%f", &pEmployeeRecord[i_nrl].salary_nrl);
		printf("\n\n");
		printf("Is The Employee Married? (Y/y For Yes, N/n For No) : ");
		pEmployeeRecord[i_nrl].marital_status_nrl = getch();
		printf("%c", pEmployeeRecord[i_nrl].marital_status_nrl);
		pEmployeeRecord[i_nrl].marital_status_nrl = toupper(pEmployeeRecord[i_nrl].marital_status_nrl);
	}

	// *** Display ****
	printf("\n\n\n\n\n ******* Displaying Employee Record *********\n\n");
	for (i_nrl = 0; i_nrl < num_employees_nrl; i_nrl++)
	{
		printf("(*********** Emplooyee Number %d *********\n\n", (i_nrl + 1));
		printf("Name :     %s\n", pEmployeeRecord[i_nrl].name_nrl);
		printf("Age :     %d years\n", pEmployeeRecord[i_nrl].age_nrl);

		if (pEmployeeRecord[i_nrl].sex_nrl == 'M')
			printf("Sex : Male\n");
		else if (pEmployeeRecord[i_nrl].sex_nrl == 'F')
			printf("Sex : Female\n");
		else
			printf("Sex : Invalid Data Entered\n");

		printf("Salary : Rs. %f\n", pEmployeeRecord[i_nrl].salary_nrl);

		if (pEmployeeRecord[i_nrl].marital_status_nrl == 'Y')
		{
			printf("Marital Status : Married\n");
		}
		else if (pEmployeeRecord[i_nrl].marital_status_nrl == 'N')
		{
			printf("Marital Status : Unmarried\n");
		}
		else
		{
			printf("Marital Status : Invalid Data Entered..\n\n\n");
		}

	}
		if (pEmployeeRecord)
		{
			free(pEmployeeRecord);
			pEmployeeRecord = NULL;
			printf("Memory Allocated To %d Employees Has Been Successfully Freed !!!\n\n", num_employees_nrl);
		}
		return(0);
}

void MyGetString(char str[], int str_size)
{
	//Variable Declarations
	int i_nrl;
	char ch_nrl;

	//code
	i_nrl = 0;
	do
	{
		ch_nrl = getch();
		str[i_nrl] = ch_nrl;
		printf("%c", str[i_nrl]);
		i_nrl++;

	} while ((ch_nrl != '\r') && (i_nrl < str_size));

	if (i_nrl == str_size)
		str[i_nrl - 1] = '\0';
	else
		str[i_nrl] = '\0';
}
