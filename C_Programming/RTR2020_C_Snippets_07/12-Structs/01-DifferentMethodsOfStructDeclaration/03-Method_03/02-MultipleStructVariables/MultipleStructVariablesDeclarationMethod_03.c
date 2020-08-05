#include <stdio.h>	

int main(void)
{
	//Defining Struct...
	struct MyPoint
	{
		int x_nrl;
		int y_nrl;

	}point_A, point_B, point_C, point_D, point_E; //Declaring 5 struct variables of type 'struct MyData' globally..

	//Code
	//Assigning Data Values To The Data Members of 'struct MyPoint' Variable 'point_A'
	point_A.x_nrl = 3;
	point_A.y_nrl = 0;

	//Assigning Data Values To The Data Members of 'struct MyPoint' Variable 'point_B'
	point_B.x_nrl = 1;
	point_B.y_nrl = 2;

	//Assigning Data Values To The Data Members of 'struct MyPoint' Variable 'point_C'
	point_C.x_nrl = 9;
	point_C.y_nrl = 6;

	//Assigning Data Values To The Data Members of 'struct MyPoint' Variable 'point_D'
	point_D.x_nrl = 8;
	point_D.y_nrl = 2;

	//Assigning Data Values To The Data Members of 'struct MyPoint' Variable 'point_E'
	point_E.x_nrl = 11;
	point_E.y_nrl = 8;

	//Displaying Values Of The Data Members Of 'struct MyPoint' (all variables)
	printf("\n\n Co-ordintes (x, y) of point 'A' Are : (%d, %d)\n\n", point_A.x_nrl, point_A.y_nrl);
	printf("\n\n Co-ordintes (x, y) of point 'B' Are : (%d, %d)\n\n", point_B.x_nrl, point_B.y_nrl);
	printf("\n\n Co-ordintes (x, y) of point 'C' Are : (%d, %d)\n\n", point_C.x_nrl, point_C.y_nrl);
	printf("\n\n Co-ordintes (x, y) of point 'D' Are : (%d, %d)\n\n", point_D.x_nrl, point_D.y_nrl);
	printf("\n\n Co-ordintes (x, y) of point 'E' Are : (%d, %d)\n\n", point_E.x_nrl, point_E.y_nrl);

	return(0);

}
