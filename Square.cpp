#include "Square.h"

// Constructor por defecto
Square::Square() : Rectangle("red", new Point2D[4]{Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)}) {}

// Constructor con parámetros
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
}

// Método para modificar los vértices
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
    Rectangle::set_vertices(vertices);
}

// Implementación del método print() heredado de Rectangle
void Square::print() const {
    std::cout << "[Square: color = " << get_color();
    for (int i = 0; i < N_VERTICES; ++i) {
        std::cout << "; v" << i << " = " << vs[i];
    }
    std::cout << "]";
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Square &square) {
    square.print();
    return out;
}

// Método para comprobar si los vértices forman un cuadrado válido
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    return (d01 == d12) && (d12 == d23) && (d23 == d30);
}

