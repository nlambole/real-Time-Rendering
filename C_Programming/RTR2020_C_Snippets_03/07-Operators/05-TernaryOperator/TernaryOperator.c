#include <stdio.h>	
int main(void)
{
	//variable declaration
	int a_nrl, b_nrl;
	int p_nrl, q_nrl;
	char ch_result_01, ch_result_02;
	int i_result_01, i_result_02;

	//code 

	printf("\n\n");

	a_nrl = 5;
	b_nrl = 7;
	ch_result_01 = (a_nrl > b_nrl) ? 'A' : 'B';
	i_result_01 = (a_nrl > b_nrl) ? a_nrl : b_nrl;
	printf("Ternary Operator Answer 1 ----%c and %d. \n\n", ch_result_01, i_result_01);

	p_nrl = 30;
	q_nrl = 60;
	ch_result_02 = (p_nrl != q_nrl) ? 'P' : 'Q';
	i_result_02 = (p_nrl != q_nrl) ? p_nrl : q_nrl;
	printf("Ternary Operator Answer 2 ----%c and %d.\n\n", ch_result_02, i_result_02);

	printf("\n\n");
	return(0);
	}


