#pragma once

/**
 * Data Structures - trie
 * trie.hpp
 * Purpose: Trie interface
 *
 * @author Prabhsimran Singh
 * @version 1.0 27/11/18
*/
#include <iostream>
#include <queue>
#include <string>

#include "node.hpp"

namespace ds {

// Trie interface
class Trie {
  private:
    TrieNode *root;

    void remove(TrieNode *const &, const std::string &);

    void print(TrieNode *, string) const;

  public:
    Trie();

    Trie(const Trie &);

    ~Trie();

    void insertWord(const std::string &);

    void removeWord(const std::string &);

    bool containsWord(const std::string &) const;

    void printWords() const;
};

// Trie implementation
Trie::Trie() {
    root = new TrieNode('\0');
}

Trie::Trie(const Trie &t) {
    throw NotImplementedError();
}

Trie::~Trie() {
    SAFE_DELETE(root);
}

void Trie::insertWord(const std::string &str) {
    TrieNode *temp = root;
    size_t i = 0;
    while (i < str.size() && temp->contains(str[i])) {
        temp = temp->children[str[i]];
        i++;
    }
    if (i == str.size() && temp->data == str[i - 1]) {
        temp->isTerminal = true;
        return;
    }
    for (; i < str.size() - 1; i++) {
        TrieNode *child = new TrieNode(str[i]);
        temp->children[str[i]] = child;
        temp = child;
    }
    if (i < str.size()) {
        TrieNode *child = new TrieNode(str[i], true);
        temp->children[str[i]] = child;
    }
}

bool Trie::containsWord(const std::string &str) const {
    TrieNode *temp = root;
    size_t i = 0;
    while (i < str.size() && temp->contains(str[i])) {
        temp = temp->children[str[i]];
        i++;
    }
    if (i == str.size()) {
        if (temp->isTerminal) {
            return true;
        }
    }
    return false;
}

void Trie::remove(TrieNode *const &node, const string &str) {
    if (str.empty()) {
        node->isTerminal = false;
        return;
    }
    if (node->contains(str[0])) {
        TrieNode *child = node->children[str[0]];
        remove(child, str.substr(1));
        if (child->children.empty() && !child->isTerminal) {
            node->remove(str[0]);
            delete child;
        }
    }
}

void Trie::removeWord(const string &str) {
    if (root->contains(str[0])) {
        TrieNode *child = root->children[str[0]];
        // keep root safe
        remove(child, str.substr(1));
        if (child->children.empty() && !child->isTerminal) {
            root->remove(str[0]);
            delete child;
        }
    }
}

void Trie::print(TrieNode *node, string str) const {
    str += node->data;
    if (node->isTerminal) {
        cout << str << endl;
    }
    for (const auto &child : node->children) {
        print(child.second, str);
    }
}

void Trie::printWords() const {
    string str = "";
    for (const auto &child : root->children) {
        print(child.second, str);
    }
}
} // namespace ds