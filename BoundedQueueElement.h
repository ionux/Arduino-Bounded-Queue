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

#ifndef ARDUINO_BOUNDED_QUEUE_ELEMENT_H
#define ARDUINO_BOUNDED_QUEUE_ELEMENT_H

#include "BoundedQueueConstants.h"

/// @brief Arduino Bounded Queue project namespace
namespace BoundedQueue
{
  /// @brief
  enum ELEMENT_TYPE
  {
    UNKNOWN = -1,
    HEAD = 0,
    TAIL = 1,
    MEMBER = 2
  };

  /// @brief
  class Element
  {
  public:
    /// @brief Default constructor.
    Element();

    /// @brief Default destructor.
    ~Element();

    /// @brief
    /// @return
    const Element *getNext();

    /// @brief
    /// @return
    bool setNext(Element *e);

    /// @brief
    /// @return
    const Element *getPrevious();

    /// @brief
    /// @return
    bool setPrevious(Element *e);

    /// @brief
    /// @return
    void *getData();

    /// @brief
    /// @param d
    bool setData(void *d);

    /// @brief
    /// @return
    const char *getTag();

    /// @brief
    /// @param t
    bool setTag(const char *t);

    /// @brief
    /// @return
    const char *getDescription();

    /// @brief
    /// @param d
    bool setDescription(const char *d);

    /// @brief
    bool initialize();

    /// @brief
    /// @return
    bool isUsed();

    /// @brief
    /// @param e
    /// @return
    const ELEMENT_TYPE getType();

    /// @brief
    /// @param t
    /// @return
    bool setType(const ELEMENT_TYPE t);

  private:
    /// @brief
    void *data;

    /// @brief
    char tag[MAX_TAG_SIZE];

    /// @brief
    char description[MAX_DESCRIPTION_SIZE];

    /// @brief
    bool used;

    /// @brief
    Element *next;

    /// @brief
    Element *prev;

    /// @brief
    ELEMENT_TYPE myType;
  };
} // namespace BoundedQueue

#endif // ARDUINO_BOUNDED_QUEUE_ELEMENT_H
