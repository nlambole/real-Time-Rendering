#include <stdio.h>

struct MyNumber
{
	int num_nrl;
	int num_table_nrl[10];
};

struct NumTables
{
	struct MyNumber a_nrl;
	struct MyNumber b_nrl;
	struct MyNumber c_nrl;
};

int main(void)
{
	//Vatriable Declarations
	struct NumTables tables_nrl;
	int i_nrl;

	///Code
	tables_nrl.a_nrl.num_nrl = 2;
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		tables_nrl.a_nrl.num_table_nrl[i_nrl] = tables_nrl.a_nrl.num_nrl * (i_nrl + 1);
	printf("\n\n Tables Of %d : \n\n", tables_nrl.a_nrl.num_nrl);
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("%d * %d = %d\n", tables_nrl.a_nrl.num_nrl, (i_nrl + 1), tables_nrl.a_nrl.num_table_nrl[i_nrl]);

	tables_nrl.b_nrl.num_nrl = 3;
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		tables_nrl.b_nrl.num_table_nrl[i_nrl] = tables_nrl.b_nrl.num_nrl * (i_nrl + 1);
	printf("\n\n Tables Of %d : \n\n", tables_nrl.b_nrl.num_nrl);
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("%d * %d = %d\n", tables_nrl.b_nrl.num_nrl, (i_nrl + 1), tables_nrl.b_nrl.num_table_nrl[i_nrl]);

	tables_nrl.c_nrl.num_nrl = 4;
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		tables_nrl.c_nrl.num_table_nrl[i_nrl] = tables_nrl.c_nrl.num_nrl * (i_nrl + 1);
	printf("\n\n Tables Of %d : \n\n", tables_nrl.c_nrl.num_nrl);
	for (i_nrl = 0; i_nrl < 10; i_nrl++)
		printf("%d * %d = %d\n", tables_nrl.c_nrl.num_nrl, (i_nrl + 1), tables_nrl.c_nrl.num_table_nrl[i_nrl]);

	return(0);
}