/**
 * MIT License
 *
 * Copyright (c) 2018 Prabhsimran Singh
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

/**
 * Data Structures - linked list
 * doubly_linked_list.hpp
 * Purpose: Doubly Linked List interface and impl.
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>
#include <vector>

#include "node.hpp"

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class DoublyLinkedList {
  private:
    DoubleNode<T> *head;
    DoubleNode<T> *tail;
    int size = 0;

  public:
    DoublyLinkedList();

    DoublyLinkedList(const vector<T> &);

    DoublyLinkedList(const DoublyLinkedList &);

    ~DoublyLinkedList();

    void insertNode(const T &);

    void insertArray(const vector<T> &);

    void deleteNode(const T &);

    DoubleNode<T> *search(const T &) const;

    void reverse();

    inline int getSize() const;

    inline DoubleNode<T> *getLinkedList() const;

    void print() const;
};

// -------------------------------------------- Implementation --------------------------------------------------//

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(NULL), tail(NULL) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const vector<T> &vec) {
    insertArray(vec);
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &d) {
    DoubleNode<T> *temp = d.getLinkedList();
    while (temp != NULL) {
        insertNode(temp->value);
        temp = temp->next;
    }
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    delete head;
    delete tail;
}

template <typename T>
void DoublyLinkedList<T>::insertNode(const T &value) {
    DoubleNode<T> *new_node = new DoubleNode<T>(value);
    if (head == NULL) {
        head = new_node;
        tail = head;
        size = 1;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        size++;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertArray(const vector<T> &vec) {
    for (const auto &elem : vec) {
        insertNode(elem);
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteNode(const T &value) {
    DoubleNode<T> *temp = head->next;
    if (head->value == value) {
        delete head;
        head = temp;
        head->prev = NULL;
        size--;
    } else if (tail->value == value) {
        temp = tail->prev;
        delete tail;
        temp->next = NULL;
        tail = temp;
        size--;
    } else {
        while (temp != NULL) {
            if (temp->value == value) {
                temp->prev->next = temp->next;
                delete temp;
                size--;
                break;
            }
            temp = temp->next;
        }
    }
}

template <typename T>
DoubleNode<T> *DoublyLinkedList<T>::search(const T &value) const {
    if (head->value == value) {
        return head;
    } else if (tail->value == value) {
        return tail;
    } else {
        DoubleNode<T> *temp_s = head->next;
        DoubleNode<T> *temp_e = tail->prev;
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
}

template <typename T>
void DoublyLinkedList<T>::reverse() {
    DoubleNode<T> *temp = NULL;
    DoubleNode<T> *current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    current = tail;
    tail = head;
    head = current;
    head->next = temp->prev;
}

template <typename T>
inline int DoublyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
inline DoubleNode<T> *DoublyLinkedList<T>::getLinkedList() const {
    return head;
}

template <typename T>
void DoublyLinkedList<T>::print() const {
    for (DoubleNode<T> *temp = head; temp != NULL; temp = temp->next)
        std::cout << temp->value << ' ';
    std::cout << '\n';
}
} // namespace ds