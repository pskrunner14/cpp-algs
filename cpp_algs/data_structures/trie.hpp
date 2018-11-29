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

// ---------------------------------------------- Interface ---------------------------------------------------//

class Trie {
  private:
    // pointer to root
    TrieNode *root;

    // recursive remove func.
    void remove(TrieNode *const &, const std::string &);

    // recursive print func.
    void print(TrieNode *, string) const;

  public:
    // trie default constructor
    Trie();

    // trie copy constructor
    Trie(const Trie &);

    // trie destructor
    ~Trie();

    // inserts word into trie
    void insertWord(const std::string &);

    // removes the word from trie if present
    void removeWord(const std::string &);

    // checks if trie contains the given word
    bool containsWord(const std::string &) const;

    // prints all the words in the trie
    void printWords() const;
};

// -------------------------------------------- Implementation --------------------------------------------------//

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