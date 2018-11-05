#pragma once

/**
 * Data Structures - linked list
 * doubly_linked_list.hpp
 * Purpose: Doubly Linked List interface
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/

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
} // namespace ds