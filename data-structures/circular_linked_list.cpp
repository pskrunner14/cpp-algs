/**
 * Data Structures - linked list
 * circular_linked_list.cpp
 * Purpose: Implementation of Circular Linked List
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>
using namespace std;

template <class T>
struct LinkNode {
    T value;
    LinkNode<T> *next;
};

template <class T>
class CircularLinkedList {
  private:
    LinkNode<T> *last;

  public:
    CircularLinkedList() {
        this->last = NULL;
    }

    CircularLinkedList(T value) {
        this->last = NULL;
        insertUsingValue(value);
    }

    CircularLinkedList(T *arr, int size) {
        this->last = NULL;
        insertUsingArray(arr, size);
    }

    ~CircularLinkedList() {
        // delete linked list when object is destroyed
        delete this->last;
    }

    void insertUsingValue(T value) {
        if (this->last == NULL) {
            this->last = new LinkNode<T>{value, NULL};
            this->last->next = this->last; // circular
            return;
        }
        LinkNode<T> *new_node = new LinkNode<T>{value, NULL};
        new_node->next = this->last->next;
        this->last->next = new_node;
        this->last = new_node;
    }

    void insertUsingArray(T *arr, int size) {
        for (int i = 0; i < size; i++)
            insertUsingValue(arr[i]);
    }

    void deleteUsingValue(T value) {
        if (last->value == value) {
            LinkNode<T> *aux = this->last;
            while (aux->next != this->last) {
                aux = aux->next;
            }
            aux->next = this->last->next;
            this->last = aux;
            return;
        }
        LinkNode<T> *p_temp;
        LinkNode<T> *temp = this->last->next;
        while (temp != this->last) {
            if (temp->value == value) {
                p_temp->next = temp->next;
                delete temp;
                return;
            }
            p_temp = temp;
            temp = temp->next;
        }
    }

    LinkNode<T> *search(T value) {
        if (this->last->value == value) {
            return this->last;
        }
        LinkNode<T> *temp = this->last->next;
        while (temp != this->last) {
            if (temp->value == value)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    LinkNode<T> *getLinkedList() {
        return this->last;
    }

    void print() {
        cout << "Circular Linked List: ";
        LinkNode<T> *temp = this->last->next;
        do {
            cout << temp->value << " ";
            temp = temp->next;
        } while (temp != this->last->next);
        cout << endl;
    }
};