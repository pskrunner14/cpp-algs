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
#include <stdexcept>
#include <string>
#include <vector>

#include "node.hpp"

namespace ds {

// Trie interface
class Trie {
  private:
    TrieNode *root;

    void remove(TrieNode *const &, const std::string &);

  public:
    Trie();

    Trie(const Trie &);

    ~Trie();

    void insertWord(const std::string &);

    void removeWord(const std::string &);

    bool contains(const std::string &) const;

    void print() const;
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
        temp = temp->getChild(str[i]);
        i++;
    }
    if (i == str.size() && temp->data == str[i - 1]) {
        temp->isTerminal = true;
        return;
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

bool Trie::contains(const std::string &str) const {
    TrieNode *temp = root;
    size_t i = 0;
    while (i < str.size() && temp->contains(str[i])) {
        temp = temp->getChild(str[i]);
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
        auto where = node->getChildPosition(str[0]);
        TrieNode *child = node->children.at(where - std::begin(node->children));
        remove(child, str.substr(1));
        if (child->children.empty() && !child->isTerminal) {
            node->children.erase(where);
            delete child;
        }
    }
}

void Trie::removeWord(const string &str) {
    if (root->contains(str[0])) {
        auto where = root->getChildPosition(str[0]);
        TrieNode *child = root->children.at(where - std::begin(root->children));
        remove(child, str.substr(1));
        // keep root safe
        if (child->children.empty() && !child->isTerminal) {
            root->children.erase(where);
            delete child;
        }
    }
}

void Trie::print() const {
    std::queue<TrieNode *> pending;
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