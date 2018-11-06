#pragma once

/**
 * Data Structures - linked list
 * circular_linked_list.hpp
 * Purpose: Circular Linked List interface
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>

namespace ds {

template <class T>
class SingleNode {
  public:
    T value;
    SingleNode<T> *next;

    SingleNode(const T &);

    SingleNode(const T &, SingleNode *);
};

// Single Node implementation
template <class T>
SingleNode<T>::SingleNode(const T &value) {
    this->value = value;
    this->next = NULL;
}

template <class T>
SingleNode<T>::SingleNode(const T &value, SingleNode *s) {
    this->value = value;
    this->next = s;
}

template <class T>
class CircularSinglyLinkedList {
  private:
    SingleNode<T> *head;

    SingleNode<T> *tail;

    int size = 0;

  public:
    CircularSinglyLinkedList();

    CircularSinglyLinkedList(const T &);

    CircularSinglyLinkedList(T *, const int &);

    CircularSinglyLinkedList(const CircularSinglyLinkedList &);

    ~CircularSinglyLinkedList();

    void insertNode(const T &);

    void insertArray(T *, const int &);

    void deleteNode(const T &);

    SingleNode<T> *search(const T &) const;

    inline int getSize() const;

    inline SingleNode<T> *getLinkedList() const;

    void print() const;
};

// circular singly linked list implementation
template <class T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList() : head(NULL), tail(NULL) {}

template <class T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList(const T &value) {
    this->insertNode(value);
}

template <class T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList(T *arr, const int &size) {
    this->insertArray(arr, size);
}

template <class T>
CircularSinglyLinkedList<T>::~CircularSinglyLinkedList() {
    // delete linked list when object is destroyed
    delete this->head;
    delete this->tail;
}

template <class T>
void CircularSinglyLinkedList<T>::insertNode(const T &value) {
    if (this->head == NULL) {
        this->head = new SingleNode<T>(value);
        this->tail = this->head;
        this->tail->next = this->head;
        this->head->next = this->tail; // circular
        this->size = 1;
        return;
    }
    SingleNode<T> *new_node = new SingleNode<T>(value, this->tail->next);
    this->tail->next = new_node;
    this->tail = new_node;
    this->size++;
}

template <class T>
void CircularSinglyLinkedList<T>::insertArray(T *arr, const int &size) {
    for (int i = 0; i < size; i++)
        insertNode(arr[i]);
}

template <class T>
void CircularSinglyLinkedList<T>::deleteNode(const T &value) {
    if (this->head->value == value) {
        SingleNode<T> *temp = this->head;
        this->tail->next = temp->next;
        delete this->head;
        this->head = temp;
    } else if (this->tail->value == value) {
        SingleNode<T> *temp = this->head;
        while (temp->next != this->tail) {
            temp = temp->next;
        }
        temp->next = this->head;
        delete this->tail;
        this->tail = temp;
    } else {
        SingleNode<T> *p_temp = this->head;
        SingleNode<T> *temp = this->head->next;
        while (temp != this->tail) {
            if (temp->value == value) {
                p_temp->next = temp->next;
                delete temp;
                this->size--;
                return;
            }
            p_temp = temp;
            temp = temp->next;
        }
    }
}

template <class T>
SingleNode<T> *CircularSinglyLinkedList<T>::search(const T &value) const {
    if (value == this->head->value) {
        return this->head;
    }
    SingleNode<T> *temp = this->head->next;
    while (temp != this->head) {
        if (temp->value == value) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

template <class T>
inline int CircularSinglyLinkedList<T>::getSize() const {
    return this->size;
}

template <class T>
inline SingleNode<T> *CircularSinglyLinkedList<T>::getLinkedList() const {
    return this->head;
}

template <class T>
void CircularSinglyLinkedList<T>::print() const {
    SingleNode<T> *temp = this->head;
    for (; temp != this->tail; temp = temp->next)
        std::cout << temp->value << " ";
    std::cout << temp->value << std::endl;
}
} // namespace ds