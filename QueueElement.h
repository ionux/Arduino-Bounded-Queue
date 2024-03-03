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

#ifndef ARDUINO_QUEUE_ELEMENT_H
#define ARDUINO_QUEUE_ELEMENT_H

#include "QueueConstants.h"

/// @brief 
enum ELEMENT_TYPE
{
  UNKNOWN = -1,
  HEAD    = 0,
  TAIL    = 1,
  MEMBER  = 2
};


/// @brief 
class QueueElement
{
  public:
    /// @brief Default constructor.
    QueueElement();

    /// @brief Default destructor.
    ~QueueElement();

    /// @brief 
    /// @return 
    QueueElement* getNext();

    /// @brief 
    /// @return 
    bool setNext(QueueElement* e);

    /// @brief 
    /// @return 
    QueueElement* getPrevious();

    /// @brief 
    /// @return 
    bool setPrevious(QueueElement* e);

    /// @brief 
    /// @return 
    void* getData();

    /// @brief 
    /// @param d 
    bool setData(void *d);

    /// @brief 
    /// @return 
    char* getTag();

    /// @brief 
    /// @param t 
    bool setTag(char* t);

    /// @brief 
    /// @return 
    char* getDescription();

    /// @brief 
    /// @param d 
    bool setDescription(char* d);

    /// @brief 
    bool initialize();

    /// @brief 
    /// @return 
    bool isUsed();

    /// @brief 
    /// @param e 
    /// @return 
    ELEMENT_TYPE getType();

    /// @brief 
    /// @param t 
    /// @return 
    bool setType(ELEMENT_TYPE t);

  private:
    /// @brief 
    void *data;

    /// @brief 
    char tag[MAX_QE_TAG_SIZE];

    /// @brief 
    char description[MAX_QE_DESCRIPTION_SIZE];

    /// @brief 
    bool used;

    /// @brief 
    QueueElement *next;

    /// @brief 
    QueueElement *prev;

    /// @brief 
    ELEMENT_TYPE myType;
};

#endif // ARDUINO_QUEUE_ELEMENT_H
