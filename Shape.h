#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>

class Shape {
	protected:
    		std::string color; // Color de la figura

	public:
    		// Constructor por defecto, crea una figura de color rojo
    		Shape(); 

    		// Constructor que crea una figura del color especificado
    		Shape(std::string color);
    	
    		// Devuelve el color de relleno de la figura
    		std::string get_color() const;

    		// Modifica el color del relleno de la figura
    		void set_color(std::string c); 

    		// Métodos virtuales puros
    		virtual double area() const = 0;
    		virtual double perimeter() const = 0;
    		virtual void translate(double incX, double incY) = 0;
    		virtual void print() const = 0;
};

#endif // SHAPE_H

