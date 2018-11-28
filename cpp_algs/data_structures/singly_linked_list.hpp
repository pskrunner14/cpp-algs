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
#include <vector>

#include "node.hpp"

namespace ds {

// Singly Linked List interface
template <typename T>
class SinglyLinkedList {
  private:
    SingleNode<T> *head;
    SingleNode<T> *tail;
    int size = 0;

  public:
    SinglyLinkedList();

    SinglyLinkedList(const vector<T> &);

    SinglyLinkedList(const SinglyLinkedList &);

    ~SinglyLinkedList();

    SinglyLinkedList &operator=(const SinglyLinkedList &);

    void insertNode(const T &);

    void insertArray(const vector<T> &);

    void deleteNode(const T &);

    SingleNode<T> *search(const T &) const;

    void reverse();

    inline int getSize() const;

    inline SingleNode<T> *getLinkedList() const;

    void print() const;
};

// Singly Linked List implementation
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(NULL), tail(NULL) {}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const vector<T> &vec) {
    insertArray(vec);
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
    SAFE_DELETE(head);
    SAFE_DELETE(tail);
}

template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(const SinglyLinkedList &s) {
    if (this != s) {
        SingleNode<T> *temp = s.getLinkedList();
        while (temp != NULL) {
            insertNode(temp->value);
            temp = temp->next;
        }
    }
    return *this;
}

template <typename T>
void SinglyLinkedList<T>::insertNode(const T &value) {
    SingleNode<T> *new_node = new SingleNode<T>(value);
    if (head == NULL) {
        head = new_node;
        tail = new_node;
        size = 1;
    } else {
        tail->next = new_node;
        tail = new_node;
        size++;
    }
}

template <typename T>
void SinglyLinkedList<T>::insertArray(const vector<T> &vec) {
    for (const auto &elem : vec) {
        insertNode(elem);
    }
}

template <typename T>
void SinglyLinkedList<T>::deleteNode(const T &value) {
    SingleNode<T> *temp = head->next;
    if (head->value == value) {
        if (temp != NULL) {
            delete head;
            head = temp;
        } else {
            delete head;
            head = NULL;
            tail = NULL;
        }
        size--;
    } else if (tail->value == value) {
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    } else {
        SingleNode<T> *p_temp = head;
        while (temp != NULL) {
            if (temp->value == value) {
                p_temp->next = temp->next;
                delete temp;
                size--;
                break;
            }
            p_temp = temp;
            temp = temp->next;
        }
    }
}

template <typename T>
SingleNode<T> *SinglyLinkedList<T>::search(const T &value) const {
    if (head->value == value) {
        return head;
    } else if (tail->value == value) {
        return tail;
    } else {
        SingleNode<T> *temp = head;
        while (temp != NULL && temp->value != value) {
            temp = temp->next;
        }
        return temp;
    }
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
        std::cout << temp->value << ' ';
    std::cout << '\n';
}
} // namespace ds