#pragma once

/**
 * Data Structures - stack
 * stack.hpp
 * Purpose: Stack Interface
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>

namespace ds {

template <typename T>
class Stack {
  private:
    // pointer to our data stack
    int *stack;

    // current length of the stack i.e. only valid no. of elements
    int length = 0;

    // the total capacity of the stack including garbage space
    int capacity = 10;

    // extends the data stack size by a factor of 2
    void extend();

  public:
    // default constructor
    Stack();

    // constructor with user defined capacity
    Stack(const int &);

    // copy constructor to make deep copy of stack
    Stack(const Stack &);

    // destructor for freeing the stack memory once out of scope
    ~Stack();

    // pushes an element onto stack
    void push(const T &);

    // removes and returns an element from top of stack
    T pop();

    // returns the top element of stack
    T top() const;

    // overloading the + operator behaviour
    T operator+(int) const;

    // overloading the array access operator behaviour
    T operator[](int) const;

    // assignment operator to make deep copy
    void operator=(const Stack &);

    // helper method to print the content of stack
    void print() const;

    // method that check if stack is empty
    bool empty() const;

    // returns the size of the stack
    int size() const;
};

template <class T>
Stack<T>::Stack() {
    stack = new T[capacity];
}

template <class T>
Stack<T>::Stack(const int &capacity) : capacity(capacity) {
    stack = new T[capacity];
}

template <class T>
Stack<T>::Stack(const Stack &s) {
    stack = new T[capacity];
    for (int i = 0; i < s.size(); i++) {
        push(s[i]);
    }
}

template <class T>
Stack<T>::~Stack() {
    delete[] stack;
}

template <class T>
void Stack<T>::extend() {
    T *aux = new T[2 * capacity];
    for (int i = 0; i < length; i++) {
        aux[i] = stack[i];
    }
    delete[] stack;
    stack = aux;
    capacity *= 2;
}

template <class T>
void Stack<T>::push(const T &val) {
    if (length == capacity) {
        extend();
    }
    stack[length++] = val;
}

template <class T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::runtime_error("stack index out of bound");
    }
    length--;
    return stack[length];
}

template <class T>
T Stack<T>::top() const {
    if (empty()) {
        throw std::runtime_error("stack index out of bound");
    }
    return stack[length - 1];
}

template <class T>
T Stack<T>::operator+(int index) const {
    if (index >= length || index < 0) {
        throw std::runtime_error("stack index out of bound");
    }
    return stack[index];
}

template <class T>
T Stack<T>::operator[](int index) const {
    if (index >= length || index < 0) {
        throw std::runtime_error("stack index out of bound");
    }
    return stack[index];
}

template <class T>
void Stack<T>::operator=(const Stack &s) {
    stack = new T[capacity];
    for (int i = 0; i < s.size(); i++) {
        push(s[i]);
    }
}

template <class T>
bool Stack<T>::empty() const {
    if (length == 0) {
        return true;
    }
    return false;
}

template <class T>
void Stack<T>::print() const {
    for (int i = 0; i < length; i++) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
int Stack<T>::size() const {
    return length;
}
} // namespace ds