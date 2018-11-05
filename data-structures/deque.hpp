#pragma once

/**
 * Data Structures - deque
 * deque.hpp
 * Purpose: Deque Interface
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
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
}; // namespace ds