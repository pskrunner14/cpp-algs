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

#include "node.hpp"

namespace ds {

template <typename T>
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
template <typename T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList() : head(NULL), tail(NULL) {}

template <typename T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList(const T &value) {
    insertNode(value);
}

template <typename T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList(T *arr, const int &size) {
    insertArray(arr, size);
}

template <typename T>
CircularSinglyLinkedList<T>::~CircularSinglyLinkedList() {
    // delete linked list when object is destroyed
    delete head;
    delete tail;
}

template <typename T>
void CircularSinglyLinkedList<T>::insertNode(const T &value) {
    if (head == NULL) {
        head = new SingleNode<T>(value);
        tail = head;
        tail->next = head;
        head->next = tail; // circular
        size = 1;
        return;
    }
    SingleNode<T> *new_node = new SingleNode<T>(value, tail->next);
    tail->next = new_node;
    tail = new_node;
    size++;
}

template <typename T>
void CircularSinglyLinkedList<T>::insertArray(T *arr, const int &size) {
    for (int i = 0; i < size; i++)
        insertNode(arr[i]);
}

template <typename T>
void CircularSinglyLinkedList<T>::deleteNode(const T &value) {
    if (head->value == value) {
        SingleNode<T> *temp = head;
        tail->next = temp->next;
        delete head;
        head = temp;
    } else if (tail->value == value) {
        SingleNode<T> *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    } else {
        SingleNode<T> *p_temp = head;
        SingleNode<T> *temp = head->next;
        while (temp != tail) {
            if (temp->value == value) {
                p_temp->next = temp->next;
                delete temp;
                size--;
                return;
            }
            p_temp = temp;
            temp = temp->next;
        }
    }
}

template <typename T>
SingleNode<T> *CircularSinglyLinkedList<T>::search(const T &value) const {
    if (value == head->value) {
        return head;
    }
    SingleNode<T> *temp = head->next;
    while (temp != head) {
        if (temp->value == value) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

template <typename T>
inline int CircularSinglyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
inline SingleNode<T> *CircularSinglyLinkedList<T>::getLinkedList() const {
    return head;
}

template <typename T>
void CircularSinglyLinkedList<T>::print() const {
    SingleNode<T> *temp = head;
    for (; temp != tail; temp = temp->next)
        std::cout << temp->value << " ";
    std::cout << temp->value << std::endl;
}
} // namespace ds