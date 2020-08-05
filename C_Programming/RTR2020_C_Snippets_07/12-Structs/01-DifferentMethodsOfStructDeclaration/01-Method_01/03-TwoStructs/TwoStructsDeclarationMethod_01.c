#include <stdio.h>	

//Defining Struct 
struct MyPoint
{
	int x_nrl;
	int y_nrl;
}point	; //Declaring a single variable of type 'struct MyPoint' globally...

//Defining Struct
struct MyPointProperties
{
	int quadrant_nrl;
	char axis_location_nrl[10];
} point_properties_nrl; //Declaration a single variable of type 'struct' MyPointProperties' globally...

int main(void)
{
	//Code
	//Use input For The Data Members of 'struct MyPoint' Variable 'point_A' 
	printf("\n\n Enter X-Coordinate For A Point :");
	scanf("%d", &point.x_nrl);

	printf("Enter Y-Coordinate For A Point :");
	scanf("%d", &point.y_nrl);

	printf("\n\n Point Co-Oridinate (x, y) Are : (%d, %d) !!! ", point.x_nrl, point.y_nrl);

	if (point.x_nrl == 0 && point.y_nrl)
		printf("The Point Is The Origin (%d, %d) !!!\n", point.x_nrl, point.y_nrl);
	else
	{
		if (point.x_nrl == 0)
		{
			if (point.y_nrl < 0)
				strcpy(point_properties_nrl.axis_location_nrl, "Negative Y");

			if (point.y_nrl > 0)
				strcpy(point_properties_nrl.axis_location_nrl, "Positive Y");

			point_properties_nrl.quadrant_nrl = 0;
			printf("The Point Lies On The %s Axis !!!\n\n", point_properties_nrl.axis_location_nrl);
		}
		else if (point.x_nrl == 0)
		{
			if (point.x_nrl < 0)
				strcpy(point_properties_nrl.axis_location_nrl, "Negative X");

			if (point.x_nrl > 0)
				strcpy(point_properties_nrl.axis_location_nrl, "Positive X");

			point_properties_nrl.quadrant_nrl = 0;
			printf("The Point Lies On The %s Axis !!!\n\n", point_properties_nrl.axis_location_nrl);

		}
		else
		{
			point_properties_nrl.axis_location_nrl[0] = '\0';

			if (point.x_nrl > 0 && point.y_nrl > 0)
				point_properties_nrl.quadrant_nrl = 1;
			else if (point.x_nrl < 0 && point.y_nrl > 0)
				point_properties_nrl.quadrant_nrl = 2;

			else if (point.x_nrl < 0 && point.y_nrl < 0)
				point_properties_nrl.quadrant_nrl = 3;
			else
				point_properties_nrl.quadrant_nrl = 4;

			printf("The Point Lies In Quadrant Number %d !!!\n\n", point_properties_nrl.quadrant_nrl);
		}
	}
	
	return(0);
}

