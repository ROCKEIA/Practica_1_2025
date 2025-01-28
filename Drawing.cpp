#include "Drawing.h"

// Constructor
Drawing::Drawing() {
    shapes = new ListLinked<Shape*>();
}

// Destructor
Drawing::~Drawing() {
    delete shapes;
}

// Añadir una figura al frente del dibujo
void Drawing::add_front(Shape* shape) {
    shapes->insert(0, shape);
}

// Añadir una figura al fondo del dibujo
void Drawing::add_back(Shape* shape) {
    shapes->insert(shapes->size(), shape);
}

// Imprimir toda la información de las figuras del dibujo
void Drawing::print_all() const {
    for (int i = 0; i < shapes->size(); ++i) {
        shapes->get(i)->print();
        std::cout << std::endl;
    }
}

// Calcular el área total de todos los círculos presentes en el dibujo
double Drawing::get_area_all_circles() const {
    double total_area = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Circle* circle = dynamic_cast<Circle*>(shapes->get(i));
        if (circle != nullptr) {
            total_area += circle->area();
        }
    }
    return total_area;
}

// Mover todos los cuadrados aplicando los incrementos de X e Y proporcionados
void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Square* square = dynamic_cast<Square*>(shapes->get(i));
        if (square != nullptr) {
            square->translate(incX, incY);
        }
    }
}

