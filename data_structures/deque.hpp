#pragma once

/**
 * Data Structures - deque
 * deque.hpp
 * Purpose: Deque Interface
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>

namespace ds {

template <class T>
class Deque {
  private:
    // pointer to our data deque
    int *deque;

    // current length of the deque i.e. only valid no. of elements
    int length = 0;

    // the total capacity of the deque including garbage space
    int capacity = 10;

    // extends the data deque size by a factor of 2
    void extend();

    // adjusts the front and back positions for optimal space utilization
    void calibrate();

  public:
    // front index of deque
    int front = 5;

    // back index of deque
    int back = 5;

    // default constructor
    Deque();

    // constructor with user defined capacity
    Deque(const int &);

    // copy constructor to make deep copy of deque
    Deque(const Deque &);

    // destructor for freeing the deque memory once out of scope
    ~Deque();

    // appends an element to front of deque
    void enqueue_front(const T &);

    // appends an element to back of deque
    void enqueue_back(const T &);

    // removes and returns an element from front of deque
    T dequeue_front();

    // removes and returns an element from back of deque
    T dequeue_back();

    // returns the front element of deque
    T peek_front() const;

    // returns the back element of deque
    T peek_back() const;

    // overloading the + operator behaviour
    T operator+(int) const;

    // overloading the array access operator behaviour
    T operator[](int) const;

    // assignment operator to make deep copy
    void operator=(const Deque &);

    // helper method to print the content of deque
    void print() const;

    // method that check if deque is empty
    bool empty() const;

    // returns the size of the deque
    int size() const;
};

template <class T>
Deque<T>::Deque() {
    deque = new T[capacity];
}

template <class T>
Deque<T>::Deque(const int &capacity) : capacity(capacity) {
    front = capacity / 2;
    back = front;
    deque = new T[capacity];
}

template <class T>
Deque<T>::Deque(const Deque &d) {
    deque = new T[capacity];
    for (int i = 0; i < d.size(); i++) {
        enqueue_back(d[d.front + i]);
    }
}

template <class T>
Deque<T>::~Deque() {
    delete[] deque;
}

template <class T>
void Deque<T>::extend() {
    T *aux = new T[2 * capacity];
    for (int i = 0; i < length; i++) {
        aux[front + i] = deque[front + i];
    }
    delete[] deque;
    deque = aux;
    capacity *= 2;
    calibrate();
}

template <class T>
void Deque<T>::calibrate() {
    T *aux = new T[capacity];
    int new_front = capacity / 4;
    int new_back = new_front + length - 1;
    for (int i = 0; i < length; i++) {
        aux[new_front + i] = deque[front + i];
    }
    delete[] deque;
    deque = aux;
    front = new_front;
    back = new_back;
}

template <class T>
void Deque<T>::enqueue_front(const T &val) {
    if (front == 0) {
        extend();
    }
    if (length == 0) {
        deque[front] = val;
    } else {
        deque[--front] = val;
    }
    length++;
}

template <class T>
void Deque<T>::enqueue_back(const T &val) {
    if (back == capacity - 1) {
        extend();
    }
    if (length == 0) {
        deque[back] = val;
    } else {
        deque[++back] = val;
    }
    length++;
}

template <class T>
T Deque<T>::dequeue_front() {
    if (empty()) {
        throw std::runtime_error("deque index out of bound");
    }
    length--;
    return deque[front++];
}

template <class T>
T Deque<T>::dequeue_back() {
    if (empty()) {
        throw std::runtime_error("deque index out of bound");
    }
    length--;
    return deque[back--];
}

template <class T>
T Deque<T>::peek_front() const {
    if (empty()) {
        throw std::runtime_error("deque index out of bound");
    }
    return deque[front];
}

template <class T>
T Deque<T>::peek_back() const {
    if (empty()) {
        throw std::runtime_error("deque index out of bound");
    }
    return deque[back];
}

template <class T>
T Deque<T>::operator+(int index) const {
    if (index >= length || index < 0) {
        throw std::runtime_error("deque index out of bound");
    }
    return deque[front + index];
}

template <class T>
T Deque<T>::operator[](int index) const {
    if (index >= length || index < 0) {
        throw std::runtime_error("deque index out of bound");
    }
    return deque[front + index];
}

template <class T>
void Deque<T>::operator=(const Deque &q) {
    deque = new T[capacity];
    for (int i = 0; i < q.size(); i++) {
        enqueue_back(q[q.front + i]);
    }
}

template <class T>
bool Deque<T>::empty() const {
    if (length == 0) {
        return true;
    }
    return false;
}

template <class T>
void Deque<T>::print() const {
    for (int i = front; i <= back; i++) {
        std::cout << deque[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
int Deque<T>::size() const {
    return length;
}
} // namespace ds