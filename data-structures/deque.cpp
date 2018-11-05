/**
 * Data Structures - deque
 * deque.cpp
 * Purpose: Implementation of Deque
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>

#include "deque.hpp"

namespace ds {

template <class T>
Deque<T>::Deque() {
    this->deque = new T[this->capacity];
}

template <class T>
Deque<T>::Deque(const int &capacity) {
    this->capacity = capacity;
    this->front = this->capacity / 2;
    this->back = this->front;
    this->deque = new T[this->capacity];
}

template <class T>
Deque<T>::Deque(const Deque &q) {
    this->deque = new T[this->capacity];
    for (int i = 0; i < q.size(); i++) {
        this->enqueue_back(q[q.front + i]);
    }
}

template <class T>
Deque<T>::~Deque() {
    delete[] this->deque;
}

template <class T>
void Deque<T>::extend() {
    T *aux = new T[2 * this->capacity];
    for (int i = 0; i < this->length; i++) {
        aux[this->front + i] = this->deque[this->front + i];
    }
    delete[] this->deque;
    this->deque = aux;
    this->capacity *= 2;
    this->calibrate();
}

template <class T>
void Deque<T>::calibrate() {
    T *aux = new T[this->capacity];
    int new_front = this->capacity / 4;
    int new_back = new_front + this->length - 1;
    for (int i = 0; i < this->length; i++) {
        aux[new_front + i] = this->deque[this->front + i];
    }
    delete[] this->deque;
    this->deque = aux;
    this->front = new_front;
    this->back = new_back;
}

template <class T>
void Deque<T>::enqueue_front(const T &val) {
    if (this->front == 0) {
        this->extend();
    }
    if (this->length == 0) {
        this->deque[this->front] = val;
    } else {
        this->deque[--this->front] = val;
    }
    this->length++;
}

template <class T>
void Deque<T>::enqueue_back(const T &val) {
    if (this->back == this->capacity - 1) {
        this->extend();
    }
    if (this->length == 0) {
        this->deque[this->back] = val;
    } else {
        this->deque[++this->back] = val;
    }
    this->length++;
}

template <class T>
T Deque<T>::dequeue_front() {
    if (this->empty()) {
        throw std::runtime_error("deque index out of bound");
    }
    this->length--;
    return this->deque[this->front++];
}

template <class T>
T Deque<T>::dequeue_back() {
    if (this->empty()) {
        throw std::runtime_error("deque index out of bound");
    }
    this->length--;
    return this->deque[this->back--];
}

template <class T>
T Deque<T>::peek_front() const {
    if (this->empty()) {
        throw std::runtime_error("deque index out of bound");
    }
    return this->deque[this->front];
}

template <class T>
T Deque<T>::peek_back() const {
    if (this->empty()) {
        throw std::runtime_error("deque index out of bound");
    }
    return this->deque[this->back];
}

template <class T>
T Deque<T>::operator+(int index) const {
    if (index >= this->length || index < 0) {
        throw std::runtime_error("deque index out of bound");
    }
    return this->deque[this->front + index];
}

template <class T>
T Deque<T>::operator[](int index) const {
    if (index >= this->length || index < 0) {
        throw std::runtime_error("deque index out of bound");
    }
    return this->deque[this->front + index];
}

template <class T>
void Deque<T>::operator=(const Deque &q) {
    this->deque = new T[this->capacity];
    for (int i = 0; i < q.size(); i++) {
        this->enqueue_back(q[q.front + i]);
    }
}

template <class T>
bool Deque<T>::empty() const {
    if (this->length == 0) {
        return true;
    }
    return false;
}

template <class T>
void Deque<T>::print() const {
    for (int i = this->front; i <= this->back; i++) {
        std::cout << this->deque[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
int Deque<T>::size() const {
    return this->length;
}
}; // namespace ds