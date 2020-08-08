#include <stdio.h>

int main(void)
{
	//Variable Declarations..
	int length_nrl, breadth_nrl, area_nrl;

	struct MyPoint
	{
		int x_nrl;
		int y_nrl;
	};

	struct Rectangle
	{
		struct MyPoint point_01;
		struct MyPoint point_02;
	};

	struct Rectangle rect_nrl;

	// Code
	printf("\n\n Enter Leftmost X-Coordinate Of Rectangle :");
	scanf("%d", &rect_nrl.point_01.x_nrl);

	printf("\n\n Enter Bottommost Y-Coordinate Of Rectangle :");
	scanf("%d", &rect_nrl.point_01.y_nrl);

	printf("\n\n Enter Rigthmost X-Coordinate Of Rectangle :");
	scanf("%d", &rect_nrl.point_02.x_nrl);

	printf("\n\n Enter Topmost Y-Coordinate Of Rectangle :");
	scanf("%d", &rect_nrl.point_02.y_nrl);

	length_nrl = rect_nrl.point_02.y_nrl - rect_nrl.point_01.y_nrl;
	if (length_nrl < 0)
		length_nrl = length_nrl * -1;

	breadth_nrl = rect_nrl.point_02.x_nrl - rect_nrl.point_02.y_nrl;
	if (breadth_nrl < 0)
		breadth_nrl = breadth_nrl * -1;

	area_nrl = length_nrl * breadth_nrl;

	printf("\n\n Length Of Rectangle = %d\n\n", length_nrl);
	printf("Breadth Of Rectangle = %d\n\n", area_nrl);
	printf("Area Of Rectangle = %d\n\n", area_nrl);

	return(0);
}