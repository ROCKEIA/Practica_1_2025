#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Rectangle.h"

// Clase Square derivada de Rectangle
class Square : public Rectangle {
public:
    // Constructor por defecto
    Square();

    // Constructor con parámetros
    Square(std::string color, Point2D* vertices);

    // Método para modificar los vértices
    void set_vertices(Point2D* vertices) override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Square &square);

    // Implementación del método print() heredado de Rectangle
    void print() const override;

private:
    // Método para comprobar si los vértices forman un cuadrado válido
    static bool check(Point2D* vertices);
};

#endif // SQUARE_H

