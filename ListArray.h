#include <iostream>
#include <stdexcept>
#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
	private:
    		T* arr; // Puntero al inicio del array que almacenará los elementos
    		int max; // Tamaño actual del array
    		int n;   // Número de elementos en la lista
    		static const int MINSIZE = 2; // Tamaño mínimo del array

    		// Método privado para redimensionar el array
    		void resize(int new_size) {
        		T* new_arr = new T[new_size]; // Crear un nuevo array
        		for (int i = 0; i < n; i++) {
            			new_arr[i] = arr[i]; // Copiar los elementos al nuevo array
        		}
        		delete[] arr; // Liberar el antiguo array
        		arr = new_arr; // Actualizar el puntero
        		max = new_size; // Actualizar el tamaño máximo
    		}

	public:
    		// Constructor sin argumentos
    		ListArray() : max(MINSIZE), n(0) {
        		arr = new T[max]; // Reservar memoria para el array
    		}

    		// Destructor
    		~ListArray() {
        		delete[] arr; // Liberar la memoria del array
    		}

    		// Sobrecarga del operador []
    		T operator[](int pos) {
        		if (pos < 0 || pos >= n) {
            			throw std::out_of_range("Posición inválida!"); // Lanzar excepción si la posición es inválida
        		}
        		return arr[pos]; // Devolver el elemento en la posición especificada
    		}

    		// Sobrecarga del operador <<
    		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        		out << "List => [";
        		for (int i = 0; i < list.n; i++) {
            			out << (i > 0 ? ", " : "") << list.arr[i]; // Imprimir los elementos
        		}
        		out << "]";
        		return out;
    		}

    		// Implementación de los métodos de la interfaz List<T>
    		void insert(int pos, T e) override {
        		if (pos < 0 || pos > n) {
            			throw std::out_of_range("Posición inválida!"); // Lanzar excepción si la posición es inválida
        		}
        		if (n == max) {
            			resize(max * 2); // Duplicar el tamaño si está lleno
        		}
        		for (int i = n; i > pos; i--) {
            			arr[i] = arr[i - 1]; // Desplazar elementos a la derecha
        		}
        		arr[pos] = e; // Insertar el nuevo elemento
        		n++; // Incrementar el contador de elementos
    		}

    		void append(T e) override {
        		insert(n, e); // Llamar a insert para agregar al final
    		}

    		void prepend(T e) override {
        		insert(0, e); // Llamar a insert para agregar al principio
    		}

    		T remove(int pos) override {
        		if (pos < 0 || pos >= n) {
            			throw std::out_of_range("Posición inválida!"); // Lanzar excepción si la posición es inválida
        		}
        		T removedElement = arr[pos]; // Guardar el elemento a eliminar
        			for (int i = pos; i < n - 1; i++) {
            				arr[i] = arr[i + 1]; // Desplazar elementos a la izquierda
        			}
        		n--; // Decrementar el contador de elementos
        		if (n < max / 4 && max > MINSIZE) {
            			resize(max / 2); // Reducir tamaño si está "demasiado vacío"
        		}
        		return removedElement; // Devolver el elemento eliminado
    		}

    		T get(int pos) override {
        		if (pos < 0 || pos >= n) {
            			throw std::out_of_range("Posición inválida!"); // Lanzar excepción si la posición es inválida
        		}
        		return arr[pos]; // Devolver el elemento en la posición especificada
    		}

    		int search(T e) override {
        		for (int i = 0; i < n; i++) {
            			if (arr[i] == e) {
                			return i; // Devolver la posición si se encuentra el elemento
            			}
        		}
        		return -1; // Devolver -1 si no se encuentra
    		}

    		bool empty() override {
			return n == 0;
    		}

		int size() override {
			return n;
		}

};

