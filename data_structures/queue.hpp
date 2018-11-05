#pragma once

/**
 * Data Structures - queue
 * queue.hpp
 * Purpose: Queue Interface
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
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
    T &dequeue();

    // returns the front element of queue
    T &peek() const;

    // overloading the + operator behaviour
    T &operator+(int) const;

    // overloading the array access operator behaviour
    T &operator[](int) const;

    // assignment operator to make deep copy
    void operator=(const Queue &);

    // helper method to print the content of queue
    void print() const;

    // method that check if queue is empty
    bool empty() const;

    // returns the size of the queue
    int size() const;
};
}; // namespace ds