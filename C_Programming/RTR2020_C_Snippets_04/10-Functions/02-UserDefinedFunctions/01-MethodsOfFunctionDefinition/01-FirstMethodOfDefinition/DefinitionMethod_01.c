#include <stdio.h> //'stdio.h' contaons declaration of 'printf()'

//Entry-Pount Funstion => main() Vlaid Return Type (int) and 3 Parameters (int) argc , char *argv[}, char * envp[]
int main(int argc, char* argv[], char* envp[])
{
	//Function prototype / declaration / signature
	void MyAddition_nrl(void);

	//code
	MyAddition_nrl(); //Function Call
	return(0);
} 

// *** User Defined Function : Method Of Definantion 1 ****
//*** No Return Value , No Parameters

void MyAddition_nrl(void) //Function Defination 
{
	//Variable Declaration : Locar Variable to Myadditon()
	int a_nrl, b_nrl, sum_nrl;

	//code
	printf("\n\n");
	printf("Enter Integer Value For 'A' : ");
	scanf("%d", &a_nrl);
	printf("\n\n");
	printf("Enter Integer Value For 'B' : ");
	scanf("%d", &b_nrl);
	sum_nrl = a_nrl + b_nrl;
	printf("\n\n");
	printf("Sum Of %d And %d = %d\n\n", a_nrl, b_nrl, sum_nrl);
}