#pragma once

/**
 * Data Structures - stack
 * stack.hpp
 * Purpose: Stack Interface
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
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

  public:
    // default constructor
    Stack();
    // constructor with user defined capacity
    Stack(const int &);
    // copy constructor to make deep copy of stack
    Stack(const Stack &);
    // destructor for freeing the stack memory once out of scope
    ~Stack();
    // extends the data stack size by a factor of 2
    void extend();
    // pushes an element onto stack
    void push(const T &);
    // removes and returns an element from top of stack
    T &pop();
    // returns the top element of stack
    T &top() const;
    // overloading the + operator behaviour
    T &operator+(int) const;
    // overloading the array access operator behaviour
    T &operator[](int) const;
    // assignment operator to make deep copy
    void operator=(const Stack &);
    // helper method to print the content of stack
    void print() const;
    // method that check if stack is empty
    bool empty() const;
    // returns the size of the stack
    int size() const;
};
}; // namespace ds