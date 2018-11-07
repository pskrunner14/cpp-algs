#pragma once

/**
 * Data Structures - queue
 * queue.hpp
 * Purpose: Queue interface and implementation
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>

namespace ds {

template <class T>
class Queue {
  private:
    // pointer to our data queue
    int *queue;

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
    void operator=(const Queue &);

    // helper method to print the content of queue
    void print() const;

    // method that check if queue is empty
    bool empty() const;

    // returns the size of the queue
    int size() const;
};

template <class T>
Queue<T>::Queue() {
    queue = new T[capacity];
}

template <class T>
Queue<T>::Queue(const int &capacity) : capacity(capacity) {
    queue = new T[capacity];
}

template <class T>
Queue<T>::Queue(const Queue &q) {
    queue = new T[capacity];
    for (int i = 0; i < q.size(); i++) {
        enqueue(q[i]);
    }
}

template <class T>
Queue<T>::~Queue() {
    delete[] queue;
}

template <class T>
void Queue<T>::extend() {
    T *aux = new T[2 * capacity];
    for (int i = 0; i < length; i++) {
        aux[i] = queue[i];
    }
    delete[] queue;
    queue = aux;
    capacity *= 2;
}

template <class T>
void Queue<T>::enqueue(const T &val) {
    if (length == capacity) {
        extend();
    }
    queue[length++] = val;
}

template <class T>
T Queue<T>::dequeue() {
    if (empty()) {
        throw std::runtime_error("queue index out of bound");
    }
    T elem = peek();
    queue++;
    length--;
    return elem;
}

template <class T>
T Queue<T>::peek() const {
    if (empty()) {
        throw std::runtime_error("queue index out of bound");
    }
    return queue[0];
}

template <class T>
T Queue<T>::operator+(int index) const {
    if (index >= length || index < 0) {
        throw std::runtime_error("queue index out of bound");
    }
    return queue[index];
}

template <class T>
T Queue<T>::operator[](int index) const {
    if (index >= length || index < 0) {
        throw std::runtime_error("queue index out of bound");
    }
    return queue[index];
}

template <class T>
void Queue<T>::operator=(const Queue &q) {
    queue = new T[capacity];
    for (int i = 0; i < q.size(); i++) {
        enqueue(q[i]);
    }
}

template <class T>
bool Queue<T>::empty() const {
    if (length == 0) {
        return true;
    }
    return false;
}

template <class T>
void Queue<T>::print() const {
    for (int i = 0; i < length; i++) {
        std::cout << queue[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
int Queue<T>::size() const {
    return length;
}
} // namespace ds
