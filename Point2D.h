#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>
#include <ostream>

// Clase Point2D que representa un punto bidimensional
class Point2D {
public:
    double x; // Coordenada x
    double y; // Coordenada y

    // Constructor por defecto y con parámetros
    Point2D(double x = 0, double y = 0); 

    // Calcula la distancia euclidiana entre dos puntos
    static double distance(const Point2D &a, const Point2D &b);
    
    // Sobrecarga del operador ==
    friend bool operator==(const Point2D &a, const Point2D &b);

    // Sobrecarga del operador !=
    friend bool operator!=(const Point2D &a, const Point2D &b);
 
    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};
#endif // POINT2D_H

