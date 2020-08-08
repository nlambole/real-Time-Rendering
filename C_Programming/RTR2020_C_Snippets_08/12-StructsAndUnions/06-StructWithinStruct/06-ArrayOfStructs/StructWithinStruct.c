#include <stdio.h>	

struct  MyNumber
{
	int num_nrl;
	int num_table_nrl[10];
};

struct NumTables
{
	struct MyNumber n_nrl;
};

int main(void)
{
	//variable Declarations
	struct NumTables tables_nrl[10]; //an array of 10 'struct NumTables'
	int i_nrl, j_nrl;

	//Code
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
	{
		tables_nrl[i_nrl].n_nrl.num_nrl = (i_nrl + 1);
	}

	for (i_nrl = 0; i_nrl < 10; i_nrl++)
	{
		printf("\n\n Table Of %d : \n\n", tables_nrl[i_nrl].n_nrl.num_nrl);
		
		for (j_nrl = 0; j_nrl < 10; j_nrl++)
		{
			tables_nrl[i_nrl].n_nrl.num_table_nrl[j_nrl] = tables_nrl[i_nrl].n_nrl.num_nrl * (j_nrl + 1);
			printf("%d * %d = %d\n", tables_nrl[i_nrl].n_nrl.num_nrl, (j_nrl + 1), tables_nrl[i_nrl].n_nrl.num_table_nrl[j_nrl]);
		}
	}
	return(0);
}