/**
 * Data Structures - linked list
 * circular_linked_list.cpp
 * Purpose: Implementation of Circular Linked List
 * 
 * @author Prabhsimran Singh
 * @version 1.0 11/09/18
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
        insertUsingValue(value);
    }

    CircularLinkedList(T *arr, int size) {
        insertUsingArray(arr, size);
    }

    ~CircularLinkedList() {
        // delete linked list when object is destroyed
        delete this->last;
    }

    void insertUsingValue(T value) {
        if (this->last == NULL) {
            this->last = new LinkNode<T>{value};
            this->last->next = this->last; // circular
            return;
        }
        LinkNode<T> *new_node = new LinkNode<T>{value};
        this->last->next = new_node;
        this->last = new_node;
    }

    void insertUsingArray(T *arr, int size) {
        for (int i = 1; i < size; i++)
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

    void deleteUsingIndex(int index) {
        if (index == 0) {
            LinkNode<T> *aux = this->last;
            while (aux->next != this->last) {
                aux = aux->next;
            }
            aux->next = this->last->next;
            this->last = aux;
            return;
        }
        LinkNode<T> *p_temp = this->last;
        LinkNode<T> *temp = this->last->next;
        int i = 1;
        while (temp != this->last) {
            if (i == index) {
                p_temp->next = temp->next;
                delete temp;
                return;
            }
            p_temp = temp;
            temp = temp->next;
            i++;
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

    void print() {
        cout << "Circular Linked List: ";
        for (LinkNode<T> *temp = this->last->next; temp != this->last; temp = temp->next)
            cout << temp->value << " ";
        cout << endl;
    }
};