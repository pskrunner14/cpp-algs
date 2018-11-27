#pragma once

/**
 * Data Structures - trie
 * trie.hpp
 * Purpose: Trie interface
 *
 * @author Prabhsimran Singh
 * @version 1.0 27/11/18
*/
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#include "node.hpp"

namespace ds {

// Trie interface
class Trie {
  private:
    TrieNode *root;

  public:
    Trie();

    Trie(const Trie &);

    void insertWord(const string &);

    void print() const;
};

// Trie implementation
Trie::Trie() {
    root = new TrieNode('\0');
}

Trie::Trie(const Trie &t) {
}

void Trie::insertWord(const string &str) {
    TrieNode *temp = root;
    int i = 0;
    while (i < str.size() && temp->contains(str[i])) {
        temp = temp->getChild(str[i]);
        i++;
    }
    for (; i < str.size() - 1; i++) {
        TrieNode *child = new TrieNode(str[i]);
        temp->addChild(child);
        temp = temp->getChild(str[i]);
    }
    if (i < str.size()) {
        TrieNode *child = new TrieNode(str[i], true);
        temp->addChild(child);
    }
}

void Trie::print() const {
    queue<TrieNode *> pending;
    pending.push(root);

    while (!pending.empty()) {
        TrieNode *current = pending.front();
        pending.pop();

        if (current->isTerminal) {
            cout << '*';
        }
        if (current == root) {
            cout << "root: ";
        } else {
            cout << current->data << ':' << ' ';
        }
        for (TrieNode *const &child : current->children) {
            pending.push(child);
            cout << child->data << ' ';
        }
        cout << '\n';
    }
}

} // namespace ds