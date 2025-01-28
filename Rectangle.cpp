#include "Rectangle.h"
#include <cmath>

// Constructor por defecto
Rectangle::Rectangle() : Shape("red") {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

// Constructor con parámetros
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for rectangle");
    }
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle &r) : Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

// Método para obtener un vértice
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Index out of range");
    }
    return vs[ind];
}

// Método para modificar los vértices
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for rectangle");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

// Sobrecarga del operador []
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

// Sobrecarga del operador de asignación
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        delete[] vs;
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; ++i) {
            vs[i] = r.vs[i];
        }
        color = r.color;
    }
    return *this;
}

// Implementación del método abstracto print() de Shape
void Rectangle::print() const {
    std::cout << "[Rectangle:";
    std::cout << " color: " << get_color();
    for (int i = 0; i < N_VERTICES; ++i) {
	std::cout <<"; v"<< i << " = " << vs[i];
    }
    std::cout << "]";
}

// Implementación del método area
double Rectangle::area() const {
    double length = Point2D::distance(vs[0], vs[1]);
    double width = Point2D::distance(vs[1], vs[2]);
    return length * width;
}

// Implementación del método perimeter
double Rectangle::perimeter() const {
    double length = Point2D::distance(vs[0], vs[1]);
    double width = Point2D::distance(vs[1], vs[2]);
    return 2 * (length + width);
}

// Implementación del método translate
void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    r.print();
    return out;
}

// Método para comprobar si los vértices forman un rectángulo válido
bool Rectangle::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    return (d01 == d23) && (d12 == d30);
}

