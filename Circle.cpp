#include "Circle.h"
#include <cmath>
#include <iostream>

// Constructor por defecto
Circle::Circle() : Shape("red"), center(Point2D()), radius(1) {}

// Constructor con parámetros
Circle::Circle(std::string color, Point2D center, double radius) 
    : Shape(color), center(center), radius(radius) {}

// Métodos consultores y modificadores
Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

// Implementación del método abstracto print() de Shape
void Circle::print() const {
    std::cout << "[Circle: color: " << color << ", center: " << center << ", radius: " << radius << "]";
}

// Implementación del método area
double Circle::area() const {
    return M_PI * radius * radius;
}

// Implementación del método perimeter
double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

// Implementación del método translate
void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    c.print(); // Reutilizamos el método print()
    return out;
}

