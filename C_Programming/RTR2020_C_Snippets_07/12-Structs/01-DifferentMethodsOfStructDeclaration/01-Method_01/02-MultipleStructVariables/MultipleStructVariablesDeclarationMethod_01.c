#include <stdio.h>	

//Defining Struct 

struct MyPoint
{	
	int x_nrl;
	int y_nrl;

}point_A, point_B, point_C, point_D, point_E; //Declarations 5 struct variables of type 'struct MyPoint' globlly...

int main(void)
{
	//Code
	//Assigninhg Data Values To The Data Members Of 'struct MyPoint' variable 'point_A'

	point_A.x_nrl = 3;
	point_A.y_nrl = 0;

	//Assigninhg Data Values To The Data Members Of 'struct MyPoint' variable 'point_B'
	point_B.x_nrl = 1;
	point_B.y_nrl = 2;

	//Assigninhg Data Values To The Data Members Of 'struct MyPoint' variable 'point_C'
	point_C.x_nrl = 9;
	point_C.y_nrl = 6;

	//Assigninhg Data Values To The Data Members Of 'struct MyPoint' variable 'point_D'
	point_D.x_nrl = 8;
	point_D.y_nrl = 2;

	//Assigninhg Data Values To The Data Members Of 'struct MyPoint' variable 'point_E'
	point_E.x_nrl = 11;
	point_A.y_nrl = 8;

	//DiaplayingVlaues OF The Data Members Of 'struct MyPoint' (all variables)
	printf("\n\n Co-ordinate (x, y) of Point 'A' Are : (%d, %d)\n\n", point_A.x_nrl, point_A.y_nrl);
	printf("\n\n Co-ordinate (x, y) of Point 'B' Are : (%d, %d)\n\n", point_B.x_nrl, point_B.y_nrl);
	printf("\n\n Co-ordinate (x, y) of Point 'C' Are : (%d, %d)\n\n", point_C.x_nrl, point_C.y_nrl);
	printf("\n\n Co-ordinate (x, y) of Point 'D' Are : (%d, %d)\n\n", point_D.x_nrl, point_D.y_nrl);
	printf("\n\n Co-ordinate (x, y) of Point 'E' Are : (%d, %d)\n\n", point_E.x_nrl, point_E.y_nrl);

	return(0);
}
