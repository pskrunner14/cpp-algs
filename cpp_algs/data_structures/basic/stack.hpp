/**
 * MIT License
 *
 * Copyright (c) 2018 Prabhsimran Singh
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

/**
 * Data Structures - stack
 * stack.hpp
 * Purpose: Stack interface and impl.
 * 
 * @author Prabhsimran Singh
 * @version 2.0 03/12/18
*/
#include <iostream>

#include "container.hpp"

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class Stack : public Container {
  private:
    // current size of the stack i.e. only valid no. of elements
    int m_size = 0;

    // the total capacity of the stack including garbage space
    int m_capacity = 0;

  protected:
    // pointer to our data stack
    T *data;

    // extends the data stack size by a factor of 2
    void extend() override;

  public:
    // default constructor
    Stack();

    // constructor with user defined capacity
    explicit Stack(const int &);

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
    Stack &operator=(const Stack &);

    // helper method to print the content of stack
    void print() const override;

    // method that check if stack is empty
    bool empty() const override;

    // returns the size of the stack
    inline int size() const override;

    // returns the capacity of the stack
    inline int capacity() const override;
};

// -------------------------------------------- Implementation --------------------------------------------------//

template <typename T>
Stack<T>::Stack() {
    data = new T[m_capacity];
}

template <typename T>
Stack<T>::Stack(const int &capacity) : m_capacity(capacity) {
    data = new T[capacity];
}

template <typename T>
Stack<T>::Stack(const Stack &s) {
    if (data)
        delete[] data;
    data = new T[s.capacity()];
    m_capacity = s.capacity();
    std::copy(s.data, s.data + s.size(), data);
    m_size = s.size();
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template <typename T>
void Stack<T>::extend() {
    T *aux = new T[2 * m_capacity];
    std::move(data, data + m_size, aux);
    delete[] data;
    data = aux;
    m_capacity *= 2;
}

template <typename T>
void Stack<T>::push(const T &val) {
    if (m_size == m_capacity) {
        extend();
    }
    data[m_size++] = val;
}

template <typename T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::runtime_error("stack index out of bound");
    }
    m_size--;
    return data[m_size];
}

template <typename T>
T Stack<T>::top() const {
    if (empty()) {
        throw std::runtime_error("stack index out of bound");
    }
    return data[m_size - 1];
}

template <typename T>
T Stack<T>::operator+(int index) const {
    if (index >= m_size || index < 0) {
        throw std::runtime_error("stack index out of bound");
    }
    return data[index];
}

template <typename T>
T Stack<T>::operator[](int index) const {
    if (index >= m_size || index < 0) {
        throw std::runtime_error("stack index out of bound");
    }
    return data[index];
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack &s) {
    if (this != &s) {
        if (data)
            delete[] data;
        data = new T[s.capacity()];
        m_capacity = s.capacity();
        std::copy(s.data, s.data + s.size(), data);
        m_size = s.size();
    }
    return *this;
}

template <typename T>
bool Stack<T>::empty() const {
    if (m_size == 0) {
        return true;
    }
    return false;
}

template <typename T>
void Stack<T>::print() const {
    for (int i = 0; i < m_size; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}

template <typename T>
inline int Stack<T>::size() const {
    return m_size;
}

template <typename T>
inline int Stack<T>::capacity() const {
    return m_capacity;
}
} // namespace ds