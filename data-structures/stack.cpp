/**
 * Data Structures - stack
 * stack.cpp
 * Purpose: Implementation of Stack
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>
#include <stdexcept>

#include "stack.hpp"
using namespace ds;

template <class T>
Stack<T>::Stack() {
    this->stack = new T[this->capacity];
}

template <class T>
Stack<T>::Stack(const int &capacity) {
    this->capacity = capacity;
    this->stack = new T[this->capacity];
}

template <class T>
Stack<T>::Stack(const Stack &s) {
    this->stack = new T[this->capacity];
    for (int i = 0; i < s.size(); i++) {
        this->push(s[i]);
    }
}

template <class T>
Stack<T>::~Stack() {
    delete[] this->stack;
}

template <class T>
void Stack<T>::extend() {
    T *aux = new T[2 * this->capacity];
    for (int i = 0; i < this->length; i++) {
        aux[i] = this->stack[i];
    }
    delete[] this->stack;
    this->stack = aux;
    this->capacity *= 2;
}

template <class T>
void Stack<T>::push(const T &val) {
    if (this->length == this->capacity) {
        this->extend();
    }
    this->stack[this->length++] = val;
}

template <class T>
T &Stack<T>::pop() {
    if (this->empty()) {
        throw std::runtime_error("stack index out of bound");
    }
    this->length--;
    return this->stack[this->length];
}

template <class T>
T &Stack<T>::top() const {
    if (this->empty()) {
        throw std::runtime_error("stack index out of bound");
    }
    return this->stack[this->length - 1];
}

template <class T>
T &Stack<T>::operator+(int index) const {
    if (index >= this->length || index < 0) {
        throw std::runtime_error("stack index out of bound");
    }
    return this->data[index];
}

template <class T>
T &Stack<T>::operator[](int index) const {
    if (index >= this->length || index < 0) {
        throw std::runtime_error("stack index out of bound");
    }
    return this->data[index];
}

template <class T>
void Stack<T>::operator=(const Stack &s) {
    this->data = new int[this->capacity];
    for (int i = 0; i < s.size(); i++) {
        this->push(s[i]);
    }
}

template <class T>
bool Stack<T>::empty() const {
    if (this->length == 0) {
        return true;
    }
    return false;
}

template <class T>
void Stack<T>::print() const {
    for (int i = 0; i < this->length; i++) {
        std::cout << this->stack[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
int Stack<T>::size() const {
    return this->length;
}