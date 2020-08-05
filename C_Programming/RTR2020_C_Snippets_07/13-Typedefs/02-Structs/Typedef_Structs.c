#include <stdio.h>

#define MAX_NAME_LENGTH 100

struct Employee
{
	char name_nrl[MAX_NAME_LENGTH];
	unsigned int age_nrl;
	char gender_nrl;
	double salary_nrl;

};

struct MyData
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
	char c_nrl;
};

int main(void)
{
	// TypeDefs
	typedef struct Employee MY_EMPLOYEE_TYPE;
	typedef struct MyData MY_DATA_TYPE;

	//Variable Declarations
	struct Employee emp_nrl = { "Funny", 24, 'M', 10000.00 };
	MY_EMPLOYEE_TYPE emp_typedef_nrl = { "Bunny", 23, 'F', 20400.00 };

	struct MyData md_nrl = { 30, 11.45f, 26.122017, 'X' };
	MY_DATA_TYPE md_typedef_nrl;

	//Code
	md_typedef_nrl.i_nrl = 9;
	md_typedef_nrl.f_nrl = 1.5f;
	md_typedef_nrl.d_nrl = 9.041997;
	md_typedef_nrl.c_nrl = 'P';

	printf("\n\n  struct Employee : \n\n");
	printf("emp.name   =%s\n", emp_nrl.name_nrl);
	printf("emp.age    = %d\n", emp_nrl.age_nrl);
	printf("emp.gneder = %c\n", emp_nrl.gender_nrl);
	printf("emp.salary =%lf\n", emp_nrl.salary_nrl);

	printf("\n\n MY EMPLOYE TYPE : \n\n");
	printf("emp_typedef.name  =%s\n", emp_typedef_nrl.name_nrl);
	printf("emp_typedef.age   = %d\n", emp_typedef_nrl.age_nrl);
	printf("emp_typedef.gender = %c\n", emp_typedef_nrl.gender_nrl);
	printf("emp_typedef.salary =%lf\n", emp_typedef_nrl.salary_nrl);

	printf("\n\n struct MyData : \n\n");
	printf("md.i = %d\n", md_nrl.i_nrl);
	printf("md.f = %f\n", md_nrl.f_nrl);
	printf("md.d = %lf\n", md_nrl.d_nrl);
	printf("md.c = %c\n", md_nrl.c_nrl);

	printf("\n\n MY_DATA_TYPE : \n\n");
	printf("md_typedef.i = %d\n", md_typedef_nrl.i_nrl);
	printf("md_typedef.f = %f\n", md_typedef_nrl.f_nrl);
	printf("md_typedef.d = %lf\n", md_typedef_nrl.d_nrl);
	printf("md_typedef.c = %c\n", md_typedef_nrl.c_nrl);

	printf("\n\n ");

	return(0);
}

