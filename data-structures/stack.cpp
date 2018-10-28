/**
 * Data Structures - stack
 * stack.cpp
 * Purpose: Implementation of Stack
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>
using namespace std;

template <class T>
class Stack {
  private:
    T *stack;
    int length = 0;
    int capacity;

  public:
    Stack() {
        this->capacity = 10;
        this->stack = new T[this->capacity];
    }

    Stack(int capacity) {
        this->capacity = capacity;
        this->stack = new T[this->capacity];
    }

    void push(T val) {
        if (this->length == this->capacity) {
            T *aux = new T[2 * this->capacity];
            for (int i = 0; i < this->length; i++) {
                aux[i] = this->stack[i];
            }
            delete[] this->stack;
            this->stack = aux;
        }
        this->stack[this->length++] = val;
    }

    T pop() {
        if (this->length == 0) {
            return NULL;
        }
        T elem = peek();
        this->length--;
        return elem;
    }

    T peek() {
        if (this->length == 0) {
            return NULL;
        }
        return this->stack[this->length - 1];
    }

    bool isEmpty() {
        if (this->length == 0) {
            return true;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < this->length; i++) {
            cout << this->stack[i] << " ";
        }
        cout << endl;
    }

    int size() {
        return this->length;
    }
};