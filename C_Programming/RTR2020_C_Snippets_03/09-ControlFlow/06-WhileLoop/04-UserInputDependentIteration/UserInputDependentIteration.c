#include <stdio.h>

int main(void)
{
	int i_num_nrl, num_nrl, i_nrl;

	//code 
	printf("\n\n");

	printf("Enter An Integer Value From Which Interation Must Begin : ");
	scanf("%d", &i_num_nrl);

	printf("How Many Digits Do You Want To Print From %d Onwards ? : ", i_num_nrl);
	scanf("%d", &num_nrl);

	printf("Printing Digits %d to %d : \n\n", i_num_nrl, (i_num_nrl + i_num_nrl));

	i_nrl = i_num_nrl;
	while (i_nrl <= (i_num_nrl + num_nrl))
	{
		printf("\t%d\n", i_nrl);
		i_nrl++;
	}

	printf("\n\n");

	return(0);
}