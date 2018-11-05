/**
 * Data Structures - linked list
 * singly_linked_list.cpp
 * Purpose: Implementation of Singly Linked List
 * 
 * @author Prabhsimran Singh
 * @version 2.0 27/10/18
*/
#include <iostream>

#include "singly_linked_list.hpp"

using namespace ds;

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

// Singly Linked List implementation
template <class T>
SinglyLinkedList<T>::SinglyLinkedList() : head(NULL), tail(NULL) {}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const T &value) {
    this->insertNode(value);
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(T *arr, const int &size) {
    this->insertArray(arr, size);
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList &s) {
    SingleNode<T> *temp = s.getLinkedList();
    while (temp != NULL) {
        this->insertNode(temp->value);
        temp = temp->next;
    }
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    delete this->head;
    delete this->tail;
}

template <class T>
void SinglyLinkedList<T>::insertNode(const T &value) {
    if (this->head == NULL) {
        this->head = new SingleNode<T>(value);
        this->tail = this->head;
        this->size = 1;
        return;
    }
    SingleNode<T> *new_node = new SingleNode<T>(value);
    this->tail->next = new_node;
    this->tail = new_node;
    this->size++;
    return;
}

template <class T>
void SinglyLinkedList<T>::insertArray(T *arr, const int &size) {
    for (int i = 0; i < size; i++) {
        this->insertNode(arr[i]);
    }
}

template <class T>
void SinglyLinkedList<T>::deleteNode(const T &value) {
    if (head->value == value) {
        this->head = this->head->next;
        this->size--;
        return;
    }
    SingleNode<T> *p_temp = this->head;
    SingleNode<T> *temp = this->head->next;
    while (temp != NULL) {
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

template <class T>
SingleNode<T> *SinglyLinkedList<T>::search(const T &value) const {
    SingleNode<T> *temp = this->head;
    while (temp != NULL && temp->value != value) {
        temp = temp->next;
    }
    return temp;
}

template <class T>
void SinglyLinkedList<T>::reverse() {
    SingleNode<T> *l_node = this->head;
    SingleNode<T> *rev_node = l_node->next;
    SingleNode<T> *next_node;
    if (l_node == this->head)
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
    this->head = l_node;
}

template <class T>
inline int SinglyLinkedList<T>::getSize() const {
    return this->size;
}

template <class T>
inline SingleNode<T> *SinglyLinkedList<T>::getLinkedList() const {
    return this->head;
}

template <class T>
void SinglyLinkedList<T>::print() const {
    for (SingleNode<T> *temp = this->head; temp != NULL; temp = temp->next)
        std::cout << temp->value << " ";
    std::cout << std::endl;
}