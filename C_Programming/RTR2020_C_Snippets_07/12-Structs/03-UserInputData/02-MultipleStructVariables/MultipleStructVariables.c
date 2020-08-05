#include <stdio.h>

struct MyPoint
{
	int x_nrl;
	int y_nrl;
};

int main(void)
{
	//Variable Declarations
	struct MyPoint point_A, point_B, point_C, point_D, point_E; //Declarating a struct variable

	//Code
	//User Input For The Data Members Of 'struct MyPoint' vataibel 'point_A' 
	printf("\n\n Enter X-Coordinate For Point 'A' : ");
	scanf("%d", &point_A.x_nrl);
	printf("enter Y-Coordinate for Point 'A' :");
	scanf("%d", &point_A.y_nrl);

	//User Input For The Data Members Of 'struct MyPoint' vataibel 'point_B' 
	printf("\n\n Enter X-Coordinate For Point 'B' : ");
	scanf("%d", &point_B.x_nrl);
	printf("enter Y-Coordinate for Point 'B' : ");
	scanf("%d", &point_B.y_nrl);

	//User Input For The Data Members Of 'struct MyPoint' vataibel 'point_C' 
	printf("\n\n Enter X-Coordinate For Point 'C' : ");
	scanf("%d", &point_C.x_nrl);
	printf("enter Y-Coordinate for Point 'C' :");
	scanf("%d", &point_C.y_nrl);

	//User Input For The Data Members Of 'struct MyPoint' vataibel 'point_D' 
	printf("\n\n Enter X-Coordinate For Point 'D' : ");
	scanf("%d", &point_D.x_nrl);
	printf("enter Y-Coordinate for Point 'D' :");
	scanf("%d", &point_D.y_nrl);

	//User Input For The Data Members Of 'struct MyPoint' vataibel 'point_E' 
	printf("\n\n Enter X-Coordinate For Point 'E' : ");
	scanf("%d", &point_E.x_nrl);
	printf("enter Y-Coordinate for Point 'E' :");
	scanf("%d", &point_E.y_nrl);

	//Displaying Vlaue Of The  Data Members OF 'struct MyPoint' (All Varaibels )
	printf("\n\n ");
	printf("Co-Ordinate (x, y) Of Point 'A' are : (%d, %d) \n\n", point_A.x_nrl, point_A.y_nrl);
	printf("Co-Ordinate (x, y) Of Point 'B' are : (%d, %d) \n\n", point_B.x_nrl, point_B.y_nrl);
	printf("Co-Ordinate (x, y) Of Point 'C' are : (%d, %d) \n\n", point_C.x_nrl, point_C.y_nrl);
	printf("Co-Ordinate (x, y) Of Point 'D' are : (%d, %d) \n\n", point_D.x_nrl, point_D.y_nrl);
	printf("Co-Ordinate (x, y) Of Point 'E' are : (%d, %d) \n\n", point_E.x_nrl, point_E.y_nrl);

	return(0);

}