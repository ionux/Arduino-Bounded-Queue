/**
 * ARDUINO BOUNDED QUEUE
 * 
 * This file is part of the Arduino Bounded Queue project. You can always find the latest
 * version of this class and project at: https://github.com/ionux/Arduino-Queue
 * 
 * MIT License
 * 
 * Copyright (c) 2024 Rich Morgan <rich.l.morgan@gmail.com>
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

#include "QueueConstants.h"
#include "QueueElement.h"


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
    unsigned int getMaxSize();

    /// @brief 
    /// @return 
    unsigned int getUsedSize();

    /// @brief 
    /// @return 
    unsigned int getFreeSpace();

    /// @brief 
    bool clear();

  private:
    /// @brief 
    bool initialize();

    /// @brief 
    bool destroy();

    /// @brief 
    /// @param d 
    bool shiftElements();

    /// @brief 
    /// @param first 
    /// @param second 
    bool copyElement(QueueElement* source, QueueElement* destination);

    /// @brief 
    QueueElement* head;

    /// @brief 
    QueueElement* tail;

    /// @brief 
    QueueElement* next;

    /// @brief 
    QueueElement* previous;

    /// @brief 
    unsigned int sizeTotal;

    /// @brief 
    unsigned int sizeUsed;

    QueueElement elements[MAX_QUEUE_SIZE];
};

#endif // ARDUINO_QUEUE_H
