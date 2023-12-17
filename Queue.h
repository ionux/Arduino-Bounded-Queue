/**
 * ARDUINO QUEUE
 * 
 * This file is part of the Arduino Queue project. You can always find the latest
 * version of this class and project at: https://github.com/ionux/Arduino-Queue
 * 
 * MIT License
 * 
 * Copyright (c) 2023 Rich Morgan <rich.l.morgan@gmail.com>
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

#ifndef ARDUINO_QUEUE_H
#define ARDUINO_QUEUE_H

#include <cstdlib>
#include <cstring>

#include "QueueElement.h"

#define MAX_QUEUE_SIZE  256
#define MIN_QUEUE_SIZE    8

/// @brief 
enum ELEMENT_TYPE
{
  UNKNOWN = -1,
  HEAD    = 0,
  TAIL    = 1
};

/// @brief Arduino Queue class
class Queue
{
  public:
    /// @brief Class constructor
    Queue();

    /// @brief Class destructor
    ~Queue();

    /// @brief 
    /// @param data 
    /// @return 
    bool enqueue (void* data);

    /// @brief 
    /// @param e 
    /// @return 
    bool enqueue (QueueElement* e);

    /// @brief 
    /// @return 
    QueueElement* dequeue();

    /// @brief 
    /// @return 
    QueueElement* peek();

    /// @brief 
    /// @return 
    unsigned int getTotalSize();

    /// @brief 
    /// @return 
    unsigned int getUsedSize();

    /// @brief 
    void clear();

  private:
    /// @brief 
    void initialize();

    /// @brief 
    void destroy();

    /// @brief 
    /// @param d 
    bool shift_elements();

    /// @brief 
    /// @param e 
    /// @return 
    ELEMENT_TYPE check_type(QueueElement* e);

    /// @brief 
    /// @param first 
    /// @param second 
    void copy_element(QueueElement* first, QueueElement* second);

    /// @brief 
    QueueElement* head;

    /// @brief 
    QueueElement* tail;

    /// @brief 
    QueueElement* next;

    /// @brief 
    unsigned int size_total;

    /// @brief 
    unsigned int size_used;

    QueueElement elements[MAX_QUEUE_SIZE];
};

#endif // ARDUINO_QUEUE_H
