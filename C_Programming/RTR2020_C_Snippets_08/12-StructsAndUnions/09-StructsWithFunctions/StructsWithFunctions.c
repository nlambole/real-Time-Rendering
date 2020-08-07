#include <stdio.h>

//Defining Struct 
struct MyData
{
	int i_nrl;
	float f_nrl;
	double d_nrl;
	char c_nrl;
};

int main(void)
{
	//Function Prototype 
	struct MyData AddStructMembers_nrl(struct MyData, struct MyData, struct MyData);

	//Variable Declarations
	struct MyData data1_nrl, data2_nrl, data3_nrl, answer_data_nrl;

	//code
	// **** data1 ***
	printf("\n\n\ *********** DATA 1 *********\n\n");
	printf("NEter Integer Value For 'i' of Struct MyData data1' : ");
	scanf("%d", &data1_nrl.i_nrl);

	printf("\n\n Enter Floating-Point Value For 'f' Of Struct MyData data1' : ");
	scanf("%f", &data1_nrl.f_nrl);

	printf("\n\n Enter 'Double' Vlaue For 'd' of 'struct MyData data1' : ");
	scanf("%lf", &data1_nrl.d_nrl);

	printf("\n\n Enter Character Vlaue For 'c' of 'struct MyData data1' : ");
	data1_nrl.c_nrl = getch();
	printf("%c", data1_nrl.c_nrl);

	// **** data2 ****
	printf("\n\n ************* DATA 2 **************\n\n");
	printf("Enter  Integer Value For 'i' Of 'sturct MyData data2' :");
	scanf("%d", &data2_nrl.i_nrl);

	printf("\n\n Enter 'Double' Value For 'd' Of 'struct MyData data2' : ");
	scanf("%lf", &data2_nrl.d_nrl);

	printf("\n\n Enter Floating-Point Vlaue For 'f' Of 'struct MyData data2' : ");
	scanf("%f", &data2_nrl.f_nrl);

	printf("\n\n Enter Character Value For 'c' Of 'struct Mydata data2' :");
	data2_nrl.c_nrl = getch();
	printf("%c", data2_nrl.c_nrl);

	// **** data3 ****
	printf("\n\n ************* DATA 3 **************\n\n");
	printf("Enter  Integer Value For 'i' Of 'sturct MyData data3' :");
	scanf("%d", &data3_nrl.i_nrl);

	printf("\n\n Enter 'Double' Value For 'd' Of 'struct MyData data3' : ");
	scanf("%lf", &data3_nrl.d_nrl);

	printf("\n\n Enter Floating-Point Vlaue For 'f' Of 'struct MyData data3' : ");
	scanf("%f", &data3_nrl.f_nrl);

	printf("\n\n Enter Character Value For 'c' Of 'struct Mydata data3' :");
	data3_nrl.c_nrl = getch();
	printf("%c", data3_nrl.c_nrl);

	// *** Calling Functions AddStructMembers() Which Accept Three Varaible Of Type 'struct MyData' As Parameters And Adds Up the Respective Members And Returns The Anwer In Another struct Of Same Type ***
	answer_data_nrl = AddStructMembers_nrl(data1_nrl, data2_nrl, data3_nrl);

	printf("\n\n\n\n *********** ANSWER *************\n\n");
	printf("answer_data.i = %d\n", answer_data_nrl.i_nrl);
	printf("answer_data.f = %f\n", answer_data_nrl.f_nrl);
	printf("answer_data.d = %lf\n", answer_data_nrl.d_nrl);

	answer_data_nrl.c_nrl = data1_nrl.c_nrl;
	printf("answer_data.c (from data1) = %c\n\n", answer_data_nrl.c_nrl);
	answer_data_nrl.c_nrl = data2_nrl.c_nrl;
	printf("answer_data.c (from data2) = %c\n\n", answer_data_nrl.c_nrl);
	answer_data_nrl.c_nrl = data3_nrl.c_nrl;
	printf("answer_data.c (from data3) = %c\n\n", answer_data_nrl.c_nrl);

	return(0);
}

struct MyData AddStructMembers_nrl(struct MyData md_one, struct MyData md_two, struct MyData md_three)
{
	//Varaible Declarations
	struct MyData answer_nrl;

	//Code
	answer_nrl.i_nrl = md_one.i_nrl + md_two.i_nrl + md_three.i_nrl;
	answer_nrl.f_nrl = md_one.f_nrl + md_two.f_nrl + md_three.f_nrl;
	answer_nrl.d_nrl = md_one.d_nrl + md_two.d_nrl + md_three.d_nrl;

	return(answer_nrl);
}

