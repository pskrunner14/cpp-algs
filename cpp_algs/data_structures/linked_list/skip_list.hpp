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
 * Data Structures - linked list
 * skip_list.hpp
 * Purpose: Skip List interface
 * 
 * @author Prabhsimran Singh
 * @version 1.0 24/12/18
*/
#include <iostream>
#include <memory>
#include <vector>

#include "linked_list.hpp"

namespace ds {

// ---------------------------------------------- Interface ---------------------------------------------------//

template <typename T>
class SkipList : public LinkedList<T, SkipNode<T>> {
  private:
    std::shared_ptr<SkipNode<T>> head;
    std::shared_ptr<SkipNode<T>> tail;
    int m_size = 0;

  public:
    explicit SkipList();
};

// -------------------------------------------- Implementation --------------------------------------------------//