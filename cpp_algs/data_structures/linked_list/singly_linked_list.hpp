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
 * Purpose: Singly Linked List interface
 * 
 * @author Prabhsimran Singh
 * @version 2.0 27/10/18
*/
#include <iostream>
#include <memory>
#include <vector>

#include "linked_list.hpp"

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class SinglyLinkedList : public LinkedList<T, SingleNode<T>> {
  private:
    std::shared_ptr<SingleNode<T>> head;
    std::shared_ptr<SingleNode<T>> tail;
    int m_size = 0;

  public:
    SinglyLinkedList();

    explicit SinglyLinkedList(const vector<T> &);

    SinglyLinkedList(const SinglyLinkedList &);

    SinglyLinkedList &operator=(const SinglyLinkedList &);

    void insertNode(const T &) override;

    void insertArray(const vector<T> &) override;

    void deleteNode(const T &) override;

    std::shared_ptr<SingleNode<T>> search(const T &) const override;

    bool contains(const T &) const override;

    void reverse();

    inline int size() const override;

    inline std::shared_ptr<SingleNode<T>> getHead() const override;

    void print() const override;
};

// -------------------------------------------- Implementation --------------------------------------------------//

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const vector<T> &vec) {
    insertArray(vec);
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList &s) {
    std::shared_ptr<SingleNode<T>> temp = s.getHead();
    while (temp != NULL) {
        insertNode(temp->data);
        temp = temp->next;
    }
}

template <typename T>
SinglyLinkedList<T> &SinglyLinkedList<T>::operator=(const SinglyLinkedList &s) {
    if (this != s) {
        std::shared_ptr<SingleNode<T>> temp = s.getHead();
        while (temp != NULL) {
            insertNode(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

template <typename T>
void SinglyLinkedList<T>::insertNode(const T &data) {
    std::shared_ptr<SingleNode<T>> new_node(new SingleNode<T>(data));
    if (head == NULL) {
        head = new_node;
        tail = new_node;
        m_size = 1;
    } else {
        tail->next = new_node;
        tail = new_node;
        m_size++;
    }
}

template <typename T>
void SinglyLinkedList<T>::insertArray(const vector<T> &vec) {
    for (const auto &elem : vec) {
        insertNode(elem);
    }
}

template <typename T>
void SinglyLinkedList<T>::deleteNode(const T &data) {
    std::shared_ptr<SingleNode<T>> temp = head->next;
    if (head->data == data) {
        if (temp != NULL) {
            head = temp;
        } else {
            head = NULL;
            tail = NULL;
        }
        m_size--;
    } else if (tail->data == data) {
        if (temp != tail) {
            while (temp->next != tail) {
                temp = temp->next;
            }
        } else {
            temp = head;
        }
        temp->next = NULL;
        tail = temp;
        m_size--;
    } else {
        std::shared_ptr<SingleNode<T>> p_temp = head;
        while (temp != NULL) {
            if (temp->data == data) {
                p_temp->next = temp->next;
                m_size--;
                break;
            }
            p_temp = temp;
            temp = temp->next;
        }
    }
}

template <typename T>
std::shared_ptr<SingleNode<T>> SinglyLinkedList<T>::search(const T &data) const {
    if (head->data == data) {
        return head;
    } else if (tail->data == data) {
        return tail;
    } else {
        std::shared_ptr<SingleNode<T>> temp = head;
        while (temp != NULL && temp->data != data) {
            temp = temp->next;
        }
        return temp;
    }
}

template <typename T>
bool SinglyLinkedList<T>::contains(const T &data) const {
    if (head->data == data) {
        return true;
    } else if (tail->data == data) {
        return true;
    } else {
        std::shared_ptr<SingleNode<T>> temp = head;
        while (temp != NULL && temp->data != data) {
            temp = temp->next;
        }
        if (temp != NULL) {
            return true;
        }
    }
    return false;
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
inline int SinglyLinkedList<T>::size() const {
    return m_size;
}

template <typename T>
inline std::shared_ptr<SingleNode<T>> SinglyLinkedList<T>::getHead() const {
    return head;
}

template <typename T>
void SinglyLinkedList<T>::print() const {
    for (std::shared_ptr<SingleNode<T>> temp = head; temp != NULL; temp = temp->next)
        std::cout << temp->data << ' ';
    std::cout << '\n';
}
} // namespace ds