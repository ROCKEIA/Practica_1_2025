#ifndef DRAWING_H
#define DRAWING_H

#include "Shape.h"
#include "ListLinked.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

class Drawing {
private:
    ListLinked<Shape*>* shapes;

public:
    // Constructor
    Drawing();
    // Destructor
    ~Drawing(); 

    // Añadir una figura al frente del dibujo
    void add_front(Shape* shape);
    

    // Añadir una figura al fondo del dibujo
    void add_back(Shape* shape);

    // Imprimir toda la información de las figuras del dibujo
    void print_all() const; 

    // Calcular el área total de todos los círculos presentes en el dibujo
    double get_area_all_circles() const; 

    // Mover todos los cuadrados aplicando los incrementos de X e Y proporcionados
    void move_squares(double incX, double incY);

};
#endif // DRAWING_H

