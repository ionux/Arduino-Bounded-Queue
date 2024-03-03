/**
 * ARDUINO BOUNDED QUEUE
 *
 * This file is part of the Arduino Bounded Queue project. You can always find the latest
 * version of this class and project at: https://github.com/ionux/Arduino-Bounded-Queue
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

#ifndef ARDUINO_BOUNDED_QUEUE_H
#define ARDUINO_BOUNDED_QUEUE_H

#include <cstdlib>
#include <cstring>

#include "BoundedQueueConstants.h"
#include "BoundedQueueElement.h"

/// @brief Arduino Bounded Queue project namespace
namespace BoundedQueue
{
  /// @brief Arduino Bounded Queue class
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
    bool enqueue(void *data);

    /// @brief
    /// @param e
    /// @return
    bool enqueue(Element *e);

    /// @brief
    /// @return
    Element *dequeue();

    /// @brief
    /// @return
    Element *peek();

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
    bool copyElement(Element *source, Element *destination);

    /// @brief
    Element *head;

    /// @brief
    Element *tail;

    /// @brief
    Element *next;

    /// @brief
    Element *previous;

    /// @brief
    unsigned int sizeTotal;

    /// @brief
    unsigned int sizeUsed;

    Element elements[MAX_QUEUE_SIZE];
  };

} // namespace BoundedQueue

#endif // ARDUINO_BOUNDED_QUEUE_H
