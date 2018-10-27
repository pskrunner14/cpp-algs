/**
 * Data Structures - linked list
 * doubly_linked_list.cpp
 * Purpose: Implementation of Doubly Linked List
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/

#include <iostream>
using namespace std;

template <class T>
struct LinkNode {
    T value;
    LinkNode<T> *prev;
    LinkNode<T> *next;
};

template <class T>
class DoublyLinkedList {
  private:
    LinkNode<T> *head;
    LinkNode<T> *tail;

  public:
    DoublyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    DoublyLinkedList(T value) {
        insertUsingValue(value);
    }

    DoublyLinkedList(T *arr, int size) {
        insertUsingArray(arr, size);
    }

    ~DoublyLinkedList() {
        // delete linked list when object is destroyed
        delete this->head;
        delete this->tail;
    }

    void insertUsingValue(T value) {
        if (this->head == NULL) {
            this->head = new LinkNode<T>{value, NULL, NULL};
            this->tail = this->head;
            return;
        }
        LinkNode<T> *new_node = new LinkNode<T>{value, NULL, NULL};
        this->tail->next = new_node;
        new_node->prev = this->tail;
        this->tail = new_node;
    }

    void insertUsingArray(T *arr, int size) {
        for (int i = 0; i < size; i++)
            insertUsingValue(arr[i]);
    }

    void deleteUsingValue(T value) {
        if (head->value == value) {
            this->head = this->head->next;
            this->head->prev = NULL;
            return;
        }
        if (tail->value == value) {
            this->tail = this->tail->prev;
            this->tail->next = NULL;
            return;
        }
        LinkNode<T> *temp = this->head;
        while (temp != NULL) {
            if (temp->value == value) {
                LinkNode<T> *p_temp = temp->prev;
                p_temp->next = temp->next;
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void deleteUsingIndex(int index) {
        if (index == 0) {
            this->head = this->head->next;
            this->head->prev = NULL;
            return;
        }
        if (index == -1) {
            this->tail = this->tail->prev;
            this->tail->next = NULL;
            return;
        }
        LinkNode<T> *temp = this->head;
        int i = 0;
        while (temp != NULL) {
            if (i == index) {
                LinkNode<T> *p_temp = temp->prev;
                p_temp->next = temp->next;
                delete temp;
                return;
            }
            temp = temp->next;
            i++;
        }
    }

    LinkNode<T> *search(T value) {
        LinkNode<T> *temp_s = this->head;
        LinkNode<T> *temp_e = this->tail;
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

    void reverse() {
        LinkNode<T> *temp = NULL;
        LinkNode<T> *current = this->head;

        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        current = this->tail;
        this->tail = this->head;
        this->head = current;
        this->head->next = temp->prev;
    }

    void print() {
        cout << "Doubly Linked List: ";
        LinkNode<T> *temp = this->head;
        for (; temp != NULL; temp = temp->next)
            cout << temp->value << " ";
        cout << endl;
        delete temp;
    }
};