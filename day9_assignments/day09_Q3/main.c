#include <stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"

int main() {
	double radius = 5.0;
	double side = 4.0;
	double length = 6.0;
	double width = 3.0;

	printf("Circle Area: %f\n", circle_area(radius));
	printf("Circle Circumference: %f\n", circle_circumference(radius));
	printf("Square Area: %f\n", square_area(side));
	printf("Square Perimeter: %f\n", square_perimeter(side));
	printf("Rectangle Area: %f\n", rectangle_area(length, width));
	printf("Rectangle Perimeter: %f\n", rectangle_perimeter(length, width));

	return 0;
}
