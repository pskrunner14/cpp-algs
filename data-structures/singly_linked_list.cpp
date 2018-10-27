/**
 * Data Structures - linked list
 * singly_linked_list.cpp
 * Purpose: Implementation of Singly Linked List
 * 
 * @author Prabhsimran Singh
 * @version 2.0 27/10/18
*/
#include <iostream>
using namespace std;

template <class T>
struct LinkNode {
    T value;
    LinkNode<T> *next;
};

template <class T>
class SinglyLinkedList {
  private:
    LinkNode<T> *head;

  public:
    SinglyLinkedList() {
        this->head = NULL;
    }

    SinglyLinkedList(T value) {
        insertUsingValue(value);
    }

    SinglyLinkedList(T *arr, int size) {
        insertUsingArray(arr, size);
    }

    ~SinglyLinkedList() {
        // delete linked list when object is destroyed
        delete this->head;
    }

    LinkNode<T> *insertUsingValue(T value, LinkNode<T> *aux = NULL) {
        if (this->head == NULL) {
            this->head = new LinkNode<T>{value, NULL};
            return this->head;
        }
        LinkNode<T> *temp;
        if (aux == NULL) {
            temp = this->head;
        } else {
            // save on traversal computation
            temp = aux;
        }
        LinkNode<T> *new_node = new LinkNode<T>{value, NULL};
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        return new_node;
    }

    void insertUsingArray(T *arr, int size) {
        LinkNode<T> *temp;
        if (this->head == NULL) {
            this->head = insertUsingValue(arr[0]);
            temp = this->head;
        } else {
            temp = insertUsingValue(arr[0], this->head);
        }
        for (int i = 1; i < size; i++)
            temp = insertUsingValue(arr[i], temp);
    }

    void deleteUsingValue(T value) {
        if (head->value == value) {
            this->head = this->head->next;
            return;
        }
        LinkNode<T> *p_temp = this->head;
        LinkNode<T> *temp = this->head->next;
        while (temp != NULL) {
            if (temp->value == value) {
                p_temp->next = temp->next;
                delete temp;
                return;
            }
            p_temp = temp;
            temp = temp->next;
        }
    }

    void deleteUsingIndex(int index) {
        if (index == 0) {
            this->head = this->head->next;
            return;
        }
        LinkNode<T> *p_temp = this->head;
        LinkNode<T> *temp = this->head->next;
        int i = 1;
        while (temp != NULL) {
            if (i == index) {
                p_temp->next = temp->next;
                delete temp;
                return;
            }
            p_temp = temp;
            temp = temp->next;
            i++;
        }
    }

    LinkNode<T> *search(T value) {
        LinkNode<T> *temp = this->head;
        while (temp != NULL) {
            if (temp->value == value)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void reverse() {
        LinkNode<T> *l_node = this->head;
        LinkNode<T> *rev_node = l_node->next;
        LinkNode<T> *next_node;
        if (l_node == this->head)
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
        this->head = l_node;
    }

    void print() {
        cout << "Singly Linked List: ";
        LinkNode<T> *temp = this->head;
        for (; temp != NULL; temp = temp->next)
            cout << temp->value << " ";
        cout << endl;
        delete temp;
    }
};