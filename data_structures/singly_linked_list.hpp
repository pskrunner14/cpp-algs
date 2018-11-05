#pragma once

/**
 * Data Structures - linked list
 * singly_linked_list.hpp
 * Purpose: Singly Linked List interface
 * 
 * @author Prabhsimran Singh
 * @version 2.0 27/10/18
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
class SinglyLinkedList {
  private:
    SingleNode<T> *head;
    SingleNode<T> *tail;

    int size = 0;

  public:
    SinglyLinkedList();

    SinglyLinkedList(const T &);

    SinglyLinkedList(T *, const int &);

    SinglyLinkedList(const SinglyLinkedList &);

    ~SinglyLinkedList();

    void insertNode(const T &);

    void insertArray(T *, const int &);

    void deleteNode(const T &);

    SingleNode<T> *search(const T &) const;

    void reverse();

    inline int getSize() const;

    inline SingleNode<T> *getLinkedList() const;

    void print() const;
};
}; // namespace ds