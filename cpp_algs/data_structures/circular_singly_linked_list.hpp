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
 * circular_linked_list.hpp
 * Purpose: Circular Singly Linked List interface
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
class CircularSinglyLinkedList {
  private:
    SingleNode<T> *head;
    SingleNode<T> *tail;
    int size = 0;

  public:
    CircularSinglyLinkedList();

    CircularSinglyLinkedList(const vector<T> &);

    CircularSinglyLinkedList(const CircularSinglyLinkedList &);

    ~CircularSinglyLinkedList();

    void insertNode(const T &);

    void insertArray(const vector<T> &);

    void deleteNode(const T &);

    SingleNode<T> *search(const T &) const;

    inline int getSize() const;

    inline SingleNode<T> *getLinkedList() const;

    void print() const;
};

// -------------------------------------------- Implementation --------------------------------------------------//

template <typename T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList() : head(NULL), tail(NULL) {}

template <typename T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList(const vector<T> &vec) {
    insertArray(vec);
}

template <typename T>
CircularSinglyLinkedList<T>::~CircularSinglyLinkedList() {
    delete head;
    delete tail;
}

template <typename T>
void CircularSinglyLinkedList<T>::insertNode(const T &value) {
    SingleNode<T> *new_node = new SingleNode<T>(value);
    if (head == NULL) {
        head = new SingleNode<T>(value);
        head = new_node;
        tail = new_node;
        tail->next = head;
        head->next = tail;
        size = 1;
    } else {
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
        size++;
    }
}

template <typename T>
void CircularSinglyLinkedList<T>::insertArray(const vector<T> &vec) {
    for (const auto &elem : vec) {
        insertNode(elem);
    }
}

template <typename T>
void CircularSinglyLinkedList<T>::deleteNode(const T &value) {
    SingleNode<T> *temp = head->next;
    if (head->value == value) {
        tail->next = temp;
        delete head;
        head = temp;
    } else if (tail->value == value) {
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    } else {
        SingleNode<T> *p_temp = head;
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
    if (head->value == value) {
        return head;
    } else if (tail->value == value) {
        return tail;
    } else {
        SingleNode<T> *temp = head->next;
        while (temp != head) {
            if (temp->value == value) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
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
        std::cout << temp->value << ' ';
    std::cout << temp->value << '\n';
}
} // namespace ds