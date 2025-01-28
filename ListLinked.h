#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first; // Puntero al primer nodo de la secuencia enlazada
    int n; // Número de elementos en la lista

    Node<T>* getNode(int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
        return current;
    }

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;
            delete first;
            first = aux;
        }
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida!");
        }
        Node<T>* newNode = new Node<T>(e);
        if (pos == 0) {
            newNode->next = first;
            first = newNode;
        } else {
            Node<T>* prev = getNode(pos - 1);
            newNode->next = prev->next;
            prev->next = newNode;
        }
        ++n;
    }

    void append(T e) override {
        insert(n, e); // Reutiliza insert() para añadir al final
    }

    void prepend(T e) override {
        insert(0, e); // Reutiliza insert() para añadir al principio
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida!");
        }
        Node<T>* target;
        if (pos == 0) {
            target = first;
            first = first->next;
        } else {
            Node<T>* prev = getNode(pos - 1);
            target = prev->next;
            prev->next = target->next;
        }
        T data = target->data;
        delete target;
        --n;
        return data;
    }

    T get(int pos) override {
        Node<T>* node = getNode(pos);
        return node->data;
    }

    int search(T e) override {
        Node<T>* current = first;
        for (int i = 0; i < n; ++i) {
            if (current->data == e) {
                return i;
            }
            current = current->next;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T operator[](int pos) {
        return get(pos);
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T> &list) {
        out << "List => [";
	Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data << " ";
            current = current->next;
        }
	out << "]";
        return out;
    }
};

#endif // LISTLINKED_H

