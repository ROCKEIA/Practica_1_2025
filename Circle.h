#ifndef CIRCLE_H
#define CIRCLE_H

#include <ostream>
#include "Point2D.h"
#include "Shape.h"

// Clase Circle derivada de Shape
class Circle : public Shape {
private:
    Point2D center; // Centro del círculo
    double radius;  // Radio del círculo

public:
    // Constructor por defecto
    Circle();

    // Constructor con parámetros
    Circle(std::string color, Point2D center, double radius);

    // Métodos consultores y modificadores
    Point2D get_center() const;
    void set_center(Point2D p);
    double get_radius() const;
    void set_radius(double r);

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Circle &c);

    // Implementación del método abstracto print() de Shape
    void print() const override;

    // Implementación de los métodos area, perimeter y translate
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
};

#endif // CIRCLE_H

