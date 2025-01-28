#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Point2D.h"
#include "Shape.h"

// Clase Rectangle derivada de Shape
class Rectangle : public Shape {
protected:
    Point2D* vs; // Puntero a un array de 4 vértices

public:
    static const int N_VERTICES = 4;

    // Constructor por defecto
    Rectangle();

    // Constructor con parámetros
    Rectangle(std::string color, Point2D* vertices);

    // Constructor de copia
    Rectangle(const Rectangle &r);

    // Destructor
    ~Rectangle();

    // Métodos consultores y modificadores
    Point2D get_vertex(int ind) const;
    virtual void set_vertices(Point2D* vertices);
    Point2D operator[](int ind) const;

    // Sobrecarga del operador de asignación
    Rectangle& operator=(const Rectangle &r);

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

    // Implementación del método abstracto print() de Shape
    void print() const override;

    // Implementación de los métodos area, perimeter y translate
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;

private:
    // Método para comprobar si los vértices forman un rectángulo válido
    static bool check(Point2D* vertices);
};

#endif // RECTANGLE_H

