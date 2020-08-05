#include <stdio.h>

int main(void)
{

	//Defining Struct....
	struct MyPoint
	{
		int x_nrl;
		int y_nrl;

	}point;

	//Defining Struct....
	struct MyPointProperties
	{
		int quadrant_nrl;
		char axis_location_nrl[10];
	}point_properties_nrl;


	//Code
	//Use input For The Data Members of 'struct Mypoint' varaible 'point_A'
	printf("\n\n Enter X-Coordinate For A Point : ");
	scanf("%d", &point.x_nrl);

	printf("Enter Y-Coordinate For A Point : ");
	scanf("%d", &point.y_nrl);

	printf("\n\n Point Co-ordinate (x, y) Are :(%d, %d) !!!\n\n", point.x_nrl, point.y_nrl);

	if (point.x_nrl == 0 && point.y_nrl)
		printf("The Point Is The Origin (%d, %d) !!!\n", point.x_nrl, point.y_nrl);
	else
	{
		if (point.x_nrl == 0) // If 'x' Is zero... Obvisouly 'Y; Is The Non-Zero vlaue 
		{
			if (point.y_nrl < 0)
				strcpy(point_properties_nrl.axis_location_nrl, "Negative Y");

			if (point.y_nrl > 0)
				strcpy(point_properties_nrl.axis_location_nrl, "Positive Y");

			point_properties_nrl.quadrant_nrl = 0;  // A Point Lying On Any Of The Co-Orinate Axis Is Not A Part Of ANY Quadrant...
			printf("The Point Lies On The %s Axis !!!\n\n", point_properties_nrl.axis_location_nrl);
		}
		else if (point.y_nrl == 0)
		{
			if (point.x_nrl < 0)
				strcpy(point_properties_nrl.axis_location_nrl, "Negative X");

			if (point.x_nrl > 0)
				strcpy(point_properties_nrl.axis_location_nrl, "Positive X");

			point_properties_nrl.quadrant_nrl = 0;  // A Point Lying On Any Of The Co-Orinate Axis Is Not A Part Of ANY Quadrant...
			printf("The Point Lies On The %s Axis !!!\n\n", point_properties_nrl.axis_location_nrl);

		}

		else // Both 'x' AND 'Y' Are Non-Zero
		{
			point_properties_nrl.axis_location_nrl[0] = '\0'; // A Point Lying In Any Of The 4th Quadrants Cannot Ve Lyingh On Any Of The Co-Ordinate Axes...

			if (point.x_nrl > 0 && point.y_nrl > 0)
				point_properties_nrl.quadrant_nrl = 1;

			else if (point.x_nrl < 0 && point.y_nrl > 0)
				point_properties_nrl.quadrant_nrl = 2;

			else if (point.x_nrl < 0 && point.y_nrl < 0)
				point_properties_nrl.quadrant_nrl = 3;

			else
				point_properties_nrl.quadrant_nrl = 4;

			printf("The Point Lies In Quadarant Number %d !!!\n\n", point_properties_nrl.quadrant_nrl);
		}
	}

	return(0);
}

