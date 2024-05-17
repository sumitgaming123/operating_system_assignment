#include "circle.h"
#define PI 3.14159265358979323846

double circle_area(double radius) {
    return PI * radius * radius;
}

double circle_circumference(double radius) {
    return 2 * PI * radius;
}
