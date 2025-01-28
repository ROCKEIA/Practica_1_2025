#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node {
	public:
    		T data; // Elemento almacenado
    		Node<T>* next; // Puntero al siguiente nodo

    		Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    		friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        		out << node.data;
        		return out;
    		}
};

#endif // NODE_H

