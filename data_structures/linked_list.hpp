#pragma once
/**
 * Data Structures - linked list
 * linked_list.cpp
 * Purpose: Linked List Interface
 * 
 * @author Prabhsimran Singh
 * @version 2.0 27/10/18
*/

namespace ds {

template <class T>
struct LinkNode {
    T value;
};

template <class T>
class LinkedList {
  private:
    LinkNode<T> *head;
    int size = 0;

  public:
    LinkedList();

    LinkedList(const T &);

    LinkedList(T *, const int &);

    LinkedList(const LinkedList &);

    ~LinkedList();

    virtual LinkNode<T> *insertValue(const T &, LinkNode<T> *) = 0;

    virtual void insertArray(T *, const int &) = 0;

    virtual void deleteValue(const T &) = 0;

    virtual LinkNode<T> *search(const T &) const = 0;

    virtual void reverse() = 0;

    inline int getSize() const {
        return this->size;
    }

    virtual LinkNode<T> *getLinkedList() const = 0;

    virtual void print() const;
};
} // namespace ds