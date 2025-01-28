#include "Shape.h"

// Constructor por defecto, crea una figura de color rojo
Shape::Shape() : color("red") {}

// Constructor que crea una figura del color especificado
Shape::Shape(std::string color) {
    if (color != "red" && color != "green" && color != "blue") {
        throw std::invalid_argument("Color inválido");
    }
    this->color = color;
}

// Devuelve el color de relleno de la figura
std::string Shape::get_color() const {
    return color;
}

// Modifica el color del relleno de la figura
void Shape::set_color(std::string c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Color inválido");
    }
    color = c;
}

