#pragma once

/**
 * Data Structures - linked list
 * circular_linked_list.hpp
 * Purpose: Circular Linked List interface
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/

namespace ds {

template <class T>
class SingleNode {
  public:
    T value;
    SingleNode<T> *next;

    SingleNode(const T &);

    SingleNode(const T &, SingleNode *);
};

template <class T>
class CircularSinglyLinkedList {
  private:
    SingleNode<T> *head;

    SingleNode<T> *tail;

    int size = 0;

  public:
    CircularSinglyLinkedList();

    CircularSinglyLinkedList(const T &);

    CircularSinglyLinkedList(T *, const int &);

    CircularSinglyLinkedList(const CircularSinglyLinkedList &);

    ~CircularSinglyLinkedList();

    void insertNode(const T &);

    void insertArray(T *, const int &);

    void deleteNode(const T &);

    SingleNode<T> *search(const T &) const;

    inline int getSize() const;

    inline SingleNode<T> *getLinkedList() const;

    void print() const;
};
} // namespace ds