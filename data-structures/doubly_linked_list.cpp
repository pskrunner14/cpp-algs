/**
 * Data Structures - linked list
 * doubly_linked_list.cpp
 * Purpose: Implementation of Doubly Linked List
 * 
 * @author Prabhsimran Singh
 * @version 1.0 11/09/18
*/

// TODO(1): refactor for doubly
#include <iostream>
using namespace std;

template <class T>
struct LinkNode {
    T val;
    LinkNode<T>* prev;
    LinkNode<T>* next;
};

template <class T>
void printLinkedList(LinkNode<T>* head) {
    cout << "Doubly Linked List: ";
    for (LinkNode<T>* temp = head; temp != NULL; temp = temp->next)
        cout << temp->val << " ";
    cout << endl;
}

template <class T>
LinkNode<T>* insertLinkNodeUsingValue(LinkNode<T>* last, T val) {
    if (last == NULL) {
        LinkNode<T>* temp = new LinkNode<T>{val};
        return temp;
    }
    LinkNode<T>* new_node = new LinkNode<T>{val};
    new_node->prev = last;
    last->next = new_node;
    return new_node;
}

template <class T>
LinkNode<T>* insertLinkNodesUsingArray(LinkNode<T>* head, T* arr, int size) {
    LinkNode<T>* temp;
    if (head == NULL) {
        head = insertLinkNodeUsingValue(head, arr[0]);
        temp = head;
    } else {
        temp = insertLinkNodeUsingValue(head, arr[0]);
    }
    for (int i = 1; i < size; i++)
        temp = insertLinkNodeUsingValue(temp, arr[i]);
    return head;
}

template <class T>
LinkNode<T>* createLinkedListUsingValue(T val) {
    LinkNode<T>* head = new LinkNode<T>{val};
    return head;
}

template <class T>
LinkNode<T>* createLinkedListUsingArray(T* arr, int size) {
    LinkNode<T>* head = NULL;
    return insertLinkNodesUsingArray(head, arr, size);
}

template <class T>
void deleteLinkNodeUsingValue(LinkNode<T>* head, T val) {
    if (head->val == val) {
        delete head;
        return;
    }
    LinkNode<T>* p_temp = NULL;
    LinkNode<T>* temp = head;
    while (temp != NULL) {
        if (temp->val == val) {
            p_temp->next = temp->next;
            delete temp;
            return;
        }
        p_temp = temp;
        temp = temp->next;
    }
}

template <class T>
void deleteLinkNodeUsingIndex(LinkNode<T>* head, int index) {
    if (index == 0) {
        delete head;
        return;
    }
    LinkNode<T>* p_temp = NULL;
    LinkNode<T>* temp = head;
    int i = 0;
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

template <class T>
bool searchLinkedList(LinkNode<T>* head, T val) {
    LinkNode<T>* temp = head;
    while (temp != NULL) {
        if (temp->val == val)
            return true;
        temp = temp->next;
    }
    return false;
}

template <class T>
LinkNode<T>* reverseLinkedList(LinkNode<T>* head) {
    LinkNode<T>* l_node = head;
    LinkNode<T>* rev_node = l_node->next;
    LinkNode<T>* next_node;
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
    return l_node;
}