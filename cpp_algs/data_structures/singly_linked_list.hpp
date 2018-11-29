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
 * singly_linked_list.hpp
 * Purpose: Singly Linked List int64_terface
 * 
 * @author Prabhsimran Singh
 * @version 2.0 27/10/18
*/
#include <iostream>
#include <memory>
#include <vector>

#include "node.hpp"

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class SinglyLinkedList {
  private:
    std::shared_ptr<SingleNode<T>> head;
    std::shared_ptr<SingleNode<T>> tail;
    int64_t size = 0;

  public:
    SinglyLinkedList();

    SinglyLinkedList(const vector<T> &);

    SinglyLinkedList(const SinglyLinkedList &);

    SinglyLinkedList &operator=(const SinglyLinkedList &);

    void insertNode(const T &);

    void insertArray(const vector<T> &);

    void deleteNode(const T &);

    std::shared_ptr<SingleNode<T>> search(const T &) const;

    void reverse();

    inline int64_t getSize() const;

    inline std::shared_ptr<SingleNode<T>> getLinkedList() const;

    void print() const;
};

// -------------------------------------------- Implementation --------------------------------------------------//

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(NULL), tail(NULL) {}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const vector<T> &vec) {
    insertArray(vec);
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList &s) {
    std::shared_ptr<SingleNode<T>> temp = s.getLinkedList();
    while (temp != NULL) {
        insertNode(temp->value);
        temp = temp->next;
    }
}

template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(const SinglyLinkedList &s) {
    if (this != s) {
        std::shared_ptr<SingleNode<T>> temp = s.getLinkedList();
        while (temp != NULL) {
            insertNode(temp->value);
            temp = temp->next;
        }
    }
    return *this;
}

template <typename T>
void SinglyLinkedList<T>::insertNode(const T &value) {
    std::shared_ptr<SingleNode<T>> new_node(new SingleNode<T>(value));
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
    std::shared_ptr<SingleNode<T>> temp = head->next;
    if (head->value == value) {
        if (temp != NULL) {
            head = temp;
        } else {
            head = NULL;
            tail = NULL;
        }
        size--;
    } else if (tail->value == value) {
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
    } else {
        std::shared_ptr<SingleNode<T>> p_temp = head;
        while (temp != NULL) {
            if (temp->value == value) {
                p_temp->next = temp->next;
                size--;
                break;
            }
            p_temp = temp;
            temp = temp->next;
        }
    }
}

template <typename T>
std::shared_ptr<SingleNode<T>> SinglyLinkedList<T>::search(const T &value) const {
    if (head->value == value) {
        return head;
    } else if (tail->value == value) {
        return tail;
    } else {
        std::shared_ptr<SingleNode<T>> temp = head;
        while (temp != NULL && temp->value != value) {
            temp = temp->next;
        }
        return temp;
    }
}

template <typename T>
void SinglyLinkedList<T>::reverse() {
    std::shared_ptr<SingleNode<T>> l_node = head;
    std::shared_ptr<SingleNode<T>> rev_node = l_node->next;
    std::shared_ptr<SingleNode<T>> next_node;
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
inline int64_t SinglyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
inline std::shared_ptr<SingleNode<T>> SinglyLinkedList<T>::getLinkedList() const {
    return head;
}

template <typename T>
void SinglyLinkedList<T>::print() const {
    for (std::shared_ptr<SingleNode<T>> temp = head; temp != NULL; temp = temp->next)
        std::cout << temp->value << ' ';
    std::cout << '\n';
}
} // namespace ds