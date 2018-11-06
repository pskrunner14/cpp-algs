#pragma once

/**
 * Data Structures - linked list
 * doubly_linked_list.hpp
 * Purpose: Doubly Linked List interface and implementation
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>

namespace ds {

template <class T>
class DoubleNode {
  public:
    T value;
    DoubleNode<T> *prev;
    DoubleNode<T> *next;

    DoubleNode(const T &);

    DoubleNode(const T &, DoubleNode *, DoubleNode *);
};

// double node implementation
template <class T>
DoubleNode<T>::DoubleNode(const T &value) {
    this->value = value;
    this->prev = NULL;
    this->next = NULL;
}

template <class T>
DoubleNode<T>::DoubleNode(const T &value, DoubleNode *prev, DoubleNode *next) {
    this->value = value;
    this->prev = prev;
    this->next = next;
}

template <class T>
class DoublyLinkedList {
  private:
    DoubleNode<T> *head;

    DoubleNode<T> *tail;

    int size = 0;

  public:
    DoublyLinkedList();

    DoublyLinkedList(const T &);

    DoublyLinkedList(T *arr, const int &);

    DoublyLinkedList(const DoublyLinkedList &);

    ~DoublyLinkedList();

    void insertNode(const T &);

    void insertArray(T *, const int &);

    void deleteNode(const T &);

    DoubleNode<T> *search(const T &) const;

    void reverse();

    inline int getSize() const;

    inline DoubleNode<T> *getLinkedList() const;

    void print() const;
};

// doubly linked list implementation
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const T &value) {
    this->insertNode(value);
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(T *arr, const int &size) {
    this->insertArray(arr, size);
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &d) {
    DoubleNode<T> *temp = d.getLinkedList();
    while (temp != NULL) {
        this->insertNode(temp->value);
        temp = temp->next;
    }
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    // delete linked list when object is destroyed
    delete this->head;
    delete this->tail;
}

template <class T>
void DoublyLinkedList<T>::insertNode(const T &value) {
    if (this->head == NULL) {
        this->head = new DoubleNode<T>(value);
        this->tail = this->head;
        this->size = 1;
        return;
    }
    DoubleNode<T> *new_node = new DoubleNode<T>(value);
    this->tail->next = new_node;
    new_node->prev = this->tail;
    this->tail = new_node;
    this->size++;
}

template <class T>
void DoublyLinkedList<T>::insertArray(T *arr, const int &size) {
    for (int i = 0; i < size; i++) {
        this->insertNode(arr[i]);
    }
}

template <class T>
void DoublyLinkedList<T>::deleteNode(const T &value) {
    if (head->value == value) {
        DoubleNode<T> *temp = this->head->next;
        delete this->head;
        this->head = temp;
        this->head->prev = NULL;
        this->size--;
    } else if (tail->value == value) {
        DoubleNode<T> *temp = this->tail->prev;
        delete this->tail;
        this->tail = temp;
        this->tail->next = NULL;
        this->size--;
    } else {
        DoubleNode<T> *temp = this->head->next;
        while (temp != NULL) {
            if (temp->value == value) {
                DoubleNode<T> *p_temp = temp->prev;
                p_temp->next = temp->next;
                delete temp;
                this->size--;
                return;
            }
            temp = temp->next;
        }
    }
}

template <class T>
DoubleNode<T> *DoublyLinkedList<T>::search(const T &value) const {
    DoubleNode<T> *temp_s = this->head;
    DoubleNode<T> *temp_e = this->tail;
    while (temp_s != NULL && temp_e != NULL) {
        if (temp_s->value == value)
            return temp_s;
        temp_s = temp_s->next;
        if (temp_e->value == value)
            return temp_e;
        if (temp_s == temp_e)
            return NULL;
        temp_e = temp_e->prev;
    }
    return NULL;
}

template <class T>
void DoublyLinkedList<T>::reverse() {
    DoubleNode<T> *temp = NULL;
    DoubleNode<T> *current = this->head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    current = this->tail;
    this->tail = this->head;
    this->head = current;
    this->head->next = temp->prev;
}

template <class T>
inline int DoublyLinkedList<T>::getSize() const {
    return this->size;
}

template <class T>
inline DoubleNode<T> *DoublyLinkedList<T>::getLinkedList() const {
    return this->head;
}

template <class T>
void DoublyLinkedList<T>::print() const {
    for (DoubleNode<T> *temp = this->head; temp != NULL; temp = temp->next)
        std::cout << temp->value << " ";
    std::cout << std::endl;
}
} // namespace ds