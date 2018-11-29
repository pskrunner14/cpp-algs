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
 * Data Structures - queue
 * queue.hpp
 * Purpose: Queue interface and impl.
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class Queue {
  private:
    // pointer to our data queue
    T *queue;

    // current length of the queue i.e. only valid no. of elements
    int length = 0;

    // the total capacity of the queue including garbage space
    int capacity = 10;

    // extends the data queue size by a factor of 2
    void extend();

  public:
    // default constructor
    Queue();

    // constructor with user defined capacity
    Queue(const int &);

    // copy constructor to make deep copy of queue
    Queue(const Queue &);

    // destructor for freeing the queue memory once out of scope
    ~Queue();

    // appends an element to queue
    void enqueue(const T &);

    // removes and returns an element from front of queue
    T dequeue();

    // returns the front element of queue
    T peek() const;

    // overloading the + operator behaviour
    T operator+(int) const;

    // overloading the array access operator behaviour
    T operator[](int) const;

    // assignment operator to make deep copy
    Queue &operator=(const Queue &);

    // helper method to print the content of queue
    void print() const;

    // method that check if queue is empty
    bool empty() const;

    // returns the size of the queue
    int size() const;
};

// -------------------------------------------- Implementation --------------------------------------------------//

template <typename T>
Queue<T>::Queue() {
    queue = new T[capacity];
}

template <typename T>
Queue<T>::Queue(const int &capacity) : capacity(capacity) {
    queue = new T[capacity];
}

template <typename T>
Queue<T>::Queue(const Queue &q) {
    delete[] queue;
    queue = new T[capacity];
    for (int i = 0; i < q.size(); i++) {
        enqueue(q[i]);
    }
}

template <typename T>
Queue<T>::~Queue() {
    delete[] queue;
}

template <typename T>
void Queue<T>::extend() {
    T *aux = new T[2 * capacity];
    for (int i = 0; i < length; i++) {
        aux[i] = queue[i];
    }
    delete[] queue;
    queue = aux;
    capacity *= 2;
}

template <typename T>
void Queue<T>::enqueue(const T &val) {
    if (length == capacity) {
        extend();
    }
    queue[length++] = val;
}

template <typename T>
T Queue<T>::dequeue() {
    if (empty()) {
        throw std::runtime_error("queue index out of bound");
    }
    T elem = peek();
    queue++;
    length--;
    return elem;
}

template <typename T>
T Queue<T>::peek() const {
    if (empty()) {
        throw std::runtime_error("queue index out of bound");
    }
    return queue[0];
}

template <typename T>
T Queue<T>::operator+(int index) const {
    if (index >= length || index < 0) {
        throw std::runtime_error("queue index out of bound");
    }
    return queue[index];
}

template <typename T>
T Queue<T>::operator[](int index) const {
    if (index >= length || index < 0) {
        throw std::runtime_error("queue index out of bound");
    }
    return queue[index];
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue &q) {
    if (this != &q) {
        delete[] queue;
        queue = new T[capacity];
        for (int i = 0; i < q.size(); i++) {
            enqueue(q[i]);
        }
    }
    return *this;
}

template <typename T>
bool Queue<T>::empty() const {
    if (length == 0) {
        return true;
    }
    return false;
}

template <typename T>
void Queue<T>::print() const {
    for (int i = 0; i < length; i++) {
        std::cout << queue[i] << ' ';
    }
    std::cout << '\n';
}

template <typename T>
int Queue<T>::size() const {
    return length;
}
} // namespace ds
