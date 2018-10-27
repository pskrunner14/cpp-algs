/**
 * Data Structures - queue
 * queue.cpp
 * Purpose: Implementation of Queue
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>
using namespace std;

template <class T>
class Queue {
  public:
    Queue() {
        this->capacity = 10;
        this->queue = new T[this->capacity];
    }

    Queue(int capacity) {
        this->capacity = capacity;
        this->queue = new T[this->capacity];
    }

    void push(T val) {
        if (this->length == this->capacity) {
            T *aux = new T[2 * this->capacity];
            for (int i = 0; i < this->length; i++) {
                aux[i] = this->queue[i];
            }
            delete[] this->queue;
            this->queue = aux;
        }
        this->queue[this->length++] = val;
    }

    T pop() {
        if (this->length == 0) {
            return NULL;
        }
        T elem = this->queue[0];
        this->queue = this->queue + 1;
        this->length--;
        return elem;
    }

    void print() {
        cout << "Queue:" << endl;
        for (int i = 0; i < this->length; i++) {
            cout << this->queue[i] << " ";
        }
        cout << endl;
    }

    int size() {
        return this->length;
    }

  private:
    int length = 0;
    int capacity;
    T *queue;
};