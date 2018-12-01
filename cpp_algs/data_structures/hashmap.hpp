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
 * Data Structures - hashmap
 * hashmap.hpp
 * Purpose: Hash Map interface and impl.
 *
 * @author Kailash Uniyal, Prabhsimran Singh
 * @version 1.0 30/10/18
*/
#include <iostream>

#include "node.hpp"

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class HashMap {
  private:
    MapNode<T> **buckets;

    int count = 0;

    int num_buckets = 5;

  public:
    HashMap();

    HashMap(const HashMap &);

    ~HashMap();

    inline int size() const;

    int getBucketIndex(const std::string &) const;

    inline double getLoadFactor() const;

    void rehash();

    void insert(const std::string &, const T &);

    T getValue(const std::string &key) const;

    T remove(const std::string &);

    void print() const;
};

// -------------------------------------------- Implementation --------------------------------------------------//

template <typename T>
HashMap<T>::HashMap() {
    buckets = new MapNode<T> *[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
    }
}

template <typename T>
HashMap<T>::HashMap(const HashMap &h) {
    count = h.count;
    num_buckets = h.num_buckets;
    for (int i = 0; i < num_buckets; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
    buckets = new MapNode<T> *[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = h.buckets[i];
    }
}

template <typename T>
HashMap<T>::~HashMap() {
    for (int i = 0; i < num_buckets; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
}

template <typename T>
inline int HashMap<T>::size() const {
    return count;
}

template <typename T>
int HashMap<T>::getBucketIndex(const std::string &key) const {
    int hashCode = 0;
    int currentCoeff = 1;
    for (int i = key.length(); i >= 0; i--) {
        hashCode += key[i] * currentCoeff;
        hashCode %= num_buckets;
        currentCoeff *= 37;
        currentCoeff %= num_buckets;
    }
    return hashCode % num_buckets;
}

template <typename T>
inline double HashMap<T>::getLoadFactor() const {
    return (1.0 * count) / num_buckets;
}

template <typename T>
void HashMap<T>::rehash() {
    MapNode<T> **temp = buckets;
    buckets = new MapNode<T> *[2 * num_buckets];
    for (int i = 0; i < 2 * num_buckets; i++) {
        buckets[i] = NULL;
    }
    int oldBucketCount = num_buckets;
    num_buckets *= 2;
    count = 0;
    for (int i = 0; i < oldBucketCount; i++) {
        MapNode<T> *head = temp[i];
        while (head != NULL) {
            std::string key = head->key;
            T data = head->data;
            insert(key, data);
            head = head->next;
        }
    }
    for (int i = 0; i < oldBucketCount; i++) {
        delete[] temp[i];
    }
    delete[] temp;
}

template <typename T>
void HashMap<T>::insert(const std::string &key, const T &data) {
    int bucketIndex = getBucketIndex(key);
    MapNode<T> *head = buckets[bucketIndex];
    while (head != NULL) {
        if (head->key == key) {
            head->data = data;
            return;
        }
        head = head->next;
    }
    head = buckets[bucketIndex];
    MapNode<T> *node = new MapNode<T>(key, data);
    node->next = head;
    buckets[bucketIndex] = node;
    count++;
    if (getLoadFactor() > 0.7) {
        rehash();
    }
}

template <typename T>
T HashMap<T>::getValue(const std::string &key) const {
    int bucketIndex = getBucketIndex(key);
    MapNode<T> *head = buckets[bucketIndex];
    while (head != NULL) {
        if (head->key == key) {
            return head->data;
        }
        head = head->next;
    }
    return 0;
}

template <typename T>
T HashMap<T>::remove(const std::string &key) {
    int bucketIndex = getBucketIndex(key);
    MapNode<T> *head = buckets[bucketIndex];
    MapNode<T> *prev = NULL;
    while (head != NULL) {
        if (head->key == key) {
            if (prev == NULL) {
                buckets[bucketIndex] = head->next;
            } else {
                prev->next = head->next;
            }
            T data = head->data;
            head->next = NULL;
            delete head;
            count--;
            return data;
        }
        prev = head;
        head = head->next;
    }
    return NULL;
}

template <typename T>
void HashMap<T>::print() const {
    for (int i = 0; i < num_buckets; i++) {
        MapNode<int> *head = buckets[i];
        while (head != NULL) {
            std::cout << head->key << " : ";
            std::cout << head->data << '\n';
            head = head->next;
        }
    }
}
} // namespace ds
