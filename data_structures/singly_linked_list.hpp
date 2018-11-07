#pragma once

/**
 * Data Structures - linked list
 * singly_linked_list.hpp
 * Purpose: Singly Linked List interface
 * 
 * @author Prabhsimran Singh
 * @version 2.0 27/10/18
*/
#include <iostream>

#include "node.hpp"

namespace ds {

template <typename T>
class SinglyLinkedList {
  private:
    SingleNode<T> *head;
    SingleNode<T> *tail;

    int size = 0;

  public:
    SinglyLinkedList();

    SinglyLinkedList(const T &);

    SinglyLinkedList(T *, const int &);

    SinglyLinkedList(const SinglyLinkedList &);

    ~SinglyLinkedList();

    void insertNode(const T &);

    void insertArray(T *, const int &);

    void deleteNode(const T &);

    SingleNode<T> *search(const T &) const;

    void reverse();

    inline int getSize() const;

    inline SingleNode<T> *getLinkedList() const;

    void print() const;
};

// Singly Linked List implementation
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const T &value) {
    insertNode(value);
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(T *arr, const int &size) {
    insertArray(arr, size);
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList &s) {
    SingleNode<T> *temp = s.getLinkedList();
    while (temp != NULL) {
        insertNode(temp->value);
        temp = temp->next;
    }
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    delete head;
    delete tail;
}

template <typename T>
void SinglyLinkedList<T>::insertNode(const T &value) {
    if (head == NULL) {
        head = new SingleNode<T>(value);
        tail = head;
        size = 1;
        return;
    }
    SingleNode<T> *new_node = new SingleNode<T>(value);
    tail->next = new_node;
    tail = new_node;
    size++;
    return;
}

template <typename T>
void SinglyLinkedList<T>::insertArray(T *arr, const int &size) {
    for (int i = 0; i < size; i++) {
        insertNode(arr[i]);
    }
}

template <typename T>
void SinglyLinkedList<T>::deleteNode(const T &value) {
    if (head->value == value) {
        head = head->next;
        size--;
        return;
    }
    SingleNode<T> *p_temp = head;
    SingleNode<T> *temp = head->next;
    while (temp != NULL) {
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

template <typename T>
SingleNode<T> *SinglyLinkedList<T>::search(const T &value) const {
    SingleNode<T> *temp = head;
    while (temp != NULL && temp->value != value) {
        temp = temp->next;
    }
    return temp;
}

template <typename T>
void SinglyLinkedList<T>::reverse() {
    SingleNode<T> *l_node = head;
    SingleNode<T> *rev_node = l_node->next;
    SingleNode<T> *next_node;
    if (l_node == head)
        l_node->next = NULL;
    if (rev_node != NULL)
        next_node = rev_node->next;
    while (rev_node != NULL) {
        rev_node->next = l_node;
        l_node = rev_node;
        rev_node = next_node;
        if (next_node != NULL) {
            next_node = next_node->next;
        }
    }
    head = l_node;
}

template <typename T>
inline int SinglyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
inline SingleNode<T> *SinglyLinkedList<T>::getLinkedList() const {
    return head;
}

template <typename T>
void SinglyLinkedList<T>::print() const {
    for (SingleNode<T> *temp = head; temp != NULL; temp = temp->next)
        std::cout << temp->value << " ";
    std::cout << std::endl;
}
} // namespace ds