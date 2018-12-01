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
#include <memory>
#include <vector>

#include "node.hpp"

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class DoublyLinkedList {
  private:
    std::shared_ptr<DoubleNode<T>> head;
    std::shared_ptr<DoubleNode<T>> tail;
    int size = 0;

  public:
    DoublyLinkedList();

    DoublyLinkedList(const vector<T> &);

    DoublyLinkedList(const DoublyLinkedList &);

    void insertNode(const T &);

    void insertArray(const vector<T> &);

    void deleteNode(const T &);

    std::shared_ptr<DoubleNode<T>> search(const T &) const;

    bool contains(const T &) const;

    void reverse();

    inline int getSize() const;

    inline std::shared_ptr<DoubleNode<T>> getLinkedList() const;

    void print() const;
};

// -------------------------------------------- Implementation --------------------------------------------------//

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const vector<T> &vec) {
    insertArray(vec);
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &d) {
    std::shared_ptr<DoubleNode<T>> temp = d.getLinkedList();
    while (temp != NULL) {
        insertNode(temp->data);
        temp = temp->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertNode(const T &data) {
    std::shared_ptr<DoubleNode<T>> new_node(new DoubleNode<T>(data));
    if (head == NULL) {
        head = new_node;
        tail = new_node;
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
void DoublyLinkedList<T>::deleteNode(const T &data) {
    std::shared_ptr<DoubleNode<T>> temp = head->next;
    if (head->data == data) {
        head = temp;
        head->prev = NULL;
        size--;
    } else if (tail->data == data) {
        temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    } else {
        while (temp != NULL) {
            if (temp->data == data) {
                temp->prev->next = temp->next;
                size--;
                break;
            }
            temp = temp->next;
        }
    }
}

template <typename T>
std::shared_ptr<DoubleNode<T>> DoublyLinkedList<T>::search(const T &data) const {
    if (head->data == data) {
        return head;
    } else if (tail->data == data) {
        return tail;
    } else {
        std::shared_ptr<DoubleNode<T>> temp_s = head->next;
        std::shared_ptr<DoubleNode<T>> temp_e = tail->prev;
        while (temp_s != NULL && temp_e != NULL) {
            if (temp_s->data == data)
                return temp_s;
            temp_s = temp_s->next;
            if (temp_e->data == data)
                return temp_e;
            if (temp_s == temp_e)
                return NULL;
            temp_e = temp_e->prev;
        }
        return NULL;
    }
}

template <typename T>
bool DoublyLinkedList<T>::contains(const T &data) const {
    if (head->data == data) {
        return true;
    } else if (tail->data == data) {
        return true;
    } else {
        std::shared_ptr<DoubleNode<T>> temp_s = head->next;
        std::shared_ptr<DoubleNode<T>> temp_e = tail->prev;
        while (temp_s != NULL && temp_e != NULL) {
            if (temp_s->data == data)
                return true;
            temp_s = temp_s->next;
            if (temp_e->data == data)
                return true;
            if (temp_s == temp_e)
                return false;
            temp_e = temp_e->prev;
        }
    }
    return false;
}

template <typename T>
void DoublyLinkedList<T>::reverse() {
    std::shared_ptr<DoubleNode<T>> temp = NULL;
    std::shared_ptr<DoubleNode<T>> current = head;
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
inline std::shared_ptr<DoubleNode<T>> DoublyLinkedList<T>::getLinkedList() const {
    return head;
}

template <typename T>
void DoublyLinkedList<T>::print() const {
    for (std::shared_ptr<DoubleNode<T>> temp = head; temp != NULL; temp = temp->next)
        std::cout << temp->data << ' ';
    std::cout << '\n';
}
} // namespace ds