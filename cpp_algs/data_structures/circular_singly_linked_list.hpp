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
#include <memory>
#include <vector>

#include "node.hpp"

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class CircularSinglyLinkedList {
  private:
    std::shared_ptr<SingleNode<T>> head;
    std::shared_ptr<SingleNode<T>> tail;
    int size = 0;

  public:
    CircularSinglyLinkedList();

    explicit CircularSinglyLinkedList(const vector<T> &);

    CircularSinglyLinkedList(const CircularSinglyLinkedList &);

    void insertNode(const T &);

    void insertArray(const vector<T> &);

    void deleteNode(const T &);

    std::shared_ptr<SingleNode<T>> search(const T &) const;

    bool contains(const T &) const;

    inline int getSize() const;

    inline std::shared_ptr<SingleNode<T>> getLinkedList() const;

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
void CircularSinglyLinkedList<T>::insertNode(const T &data) {
    std::shared_ptr<SingleNode<T>> new_node(new SingleNode<T>(data));
    if (head == NULL) {
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
void CircularSinglyLinkedList<T>::deleteNode(const T &data) {
    std::shared_ptr<SingleNode<T>> temp = head->next;
    if (head->data == data) {
        tail->next = temp;
        head = temp;
    } else if (tail->data == data) {
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        tail = temp;
    } else {
        std::shared_ptr<SingleNode<T>> p_temp = head;
        while (temp != tail) {
            if (temp->data == data) {
                p_temp->next = temp->next;
                size--;
                return;
            }
            p_temp = temp;
            temp = temp->next;
        }
    }
}

template <typename T>
std::shared_ptr<SingleNode<T>> CircularSinglyLinkedList<T>::search(const T &data) const {
    if (head->data == data) {
        return head;
    } else if (tail->data == data) {
        return tail;
    } else {
        std::shared_ptr<SingleNode<T>> temp = head->next;
        while (temp != head) {
            if (temp->data == data) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
}

template <typename T>
bool CircularSinglyLinkedList<T>::contains(const T &data) const {
    if (head->data == data) {
        return true;
    } else if (tail->data == data) {
        return true;
    } else {
        std::shared_ptr<SingleNode<T>> temp = head->next;
        while (temp != head) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}

template <typename T>
inline int CircularSinglyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
inline std::shared_ptr<SingleNode<T>> CircularSinglyLinkedList<T>::getLinkedList() const {
    return head;
}

template <typename T>
void CircularSinglyLinkedList<T>::print() const {
    std::shared_ptr<SingleNode<T>> temp = head;
    for (; temp != tail; temp = temp->next)
        std::cout << temp->data << ' ';
    std::cout << temp->data << '\n';
}
} // namespace ds