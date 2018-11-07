#pragma once

/**
 * Data Structures - node
 * node.hpp
 * Purpose: Node interface and implementation
 * 
 * @author Prabhsimran Singh
 * @version 1.0 27/10/18
*/
#include <iostream>

namespace ds {

template <typename T>
class SingleNode {
  public:
    T value;
    SingleNode<T> *next;

    SingleNode(const T &);

    SingleNode(const T &, SingleNode *);

    ~SingleNode();
};

// Single Node implementation
template <typename T>
SingleNode<T>::SingleNode(const T &value) : value(value), next(NULL) {}

template <typename T>
SingleNode<T>::SingleNode(const T &value, SingleNode *next) : value(value), next(next) {}

template <typename T>
SingleNode<T>::~SingleNode() {
    delete next;
}

template <typename T>
class DoubleNode {
  public:
    T value;
    DoubleNode<T> *prev;
    DoubleNode<T> *next;

    DoubleNode(const T &);

    DoubleNode(const T &, DoubleNode *, DoubleNode *);

    ~DoubleNode();
};

// Double Node implementation
template <typename T>
DoubleNode<T>::DoubleNode(const T &value) : value(value), prev(NULL), next(NULL) {}

template <typename T>
DoubleNode<T>::DoubleNode(const T &value, DoubleNode *prev, DoubleNode *next) : value(value), prev(prev), next(next) {}

template <typename T>
DoubleNode<T>::~DoubleNode() {
    delete prev;
    delete next;
}

template <typename T>
class MapNode {
  public:
    const std::string key;
    T value;
    MapNode<T> *next;

    MapNode(const std::string &, const T &);

    ~MapNode();
};

// MapNode implementation
template <typename T>
MapNode<T>::MapNode(const std::string &key, const T &value) : key(key), value(value), next(NULL) {}

template <typename T>
MapNode<T>::~MapNode() {
    delete next;
}
} // namespace ds