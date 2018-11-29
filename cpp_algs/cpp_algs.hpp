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

// project wide includes
#include <boost/assert.hpp>
#include <stdexcept>

// project wide members
class NotImplementedError : public std::logic_error {
  public:
    NotImplementedError() : std::logic_error("Function not yet implemented"){};
};

// Algorithms

// Searching
#include "algorithms/search.hpp"

// Sorting
#include "algorithms/sort.hpp"

// String Matching

// Graphs

// Misc
#include "algorithms/misc.hpp"

// Data Structures

// Basic
#include "data_structures/deque.hpp"
#include "data_structures/queue.hpp"
#include "data_structures/stack.hpp"

// Trees
#include "data_structures/binary_search_tree.hpp"
#include "data_structures/tree.hpp"
#include "data_structures/trie.hpp"

// Linked Lists
#include "data_structures/circular_singly_linked_list.hpp"
#include "data_structures/doubly_linked_list.hpp"
#include "data_structures/singly_linked_list.hpp"

// Misc
#include "data_structures/hashmap.hpp"
