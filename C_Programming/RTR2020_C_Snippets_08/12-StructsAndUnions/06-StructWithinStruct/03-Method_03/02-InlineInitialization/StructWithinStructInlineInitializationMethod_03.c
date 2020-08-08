#include <stdio.h>

int main(void)
{
	//Varaible Declarations
	int length_nrl, breadth_nrl, area_nrl;

	struct Rectangle
	{
		struct MyPoint
		{
			int x_nrl;
			int y_nrl;
		}point_01, point_02;

	}rect = { {2, 3}, {5,6 } };

	//Code
	length_nrl = rect.point_02.y_nrl - rect.point_01.y_nrl;
	if (length_nrl < 0)
		length_nrl = length_nrl * -1;

	breadth_nrl = rect.point_02.x_nrl - rect.point_01.x_nrl;
	if (breadth_nrl < 0)
		breadth_nrl = breadth_nrl * -1;

	area_nrl = length_nrl * breadth_nrl;

	printf("\n\n Length Of Rectangle = %d\n\n", length_nrl);
	printf("Breadth Of Rectangle = %d\n\n", breadth_nrl);
	printf("Area of Rectangle = %d\n\n", area_nrl);

	return(0);
}
