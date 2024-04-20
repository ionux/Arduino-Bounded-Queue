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

        /// @brief Get next element in queue.
        /// @return Element*
        const Element *getNext();

        /// @brief Set next element in queue.
        /// @return True or false if succeeded.
        bool setNext(Element *e);

        /// @brief Gets previous element in queue.
        /// @return Element*
        const Element *getPrevious();

        /// @brief Sets previous element in queue.
        /// @return True or false if succeeded.
        bool setPrevious(Element *e);

        /// @brief Returns pointer to data in that element.
        /// @return void*
        void *getData();

        /// @brief Returns pointer to data in that element.
        /// @param d
        /// @return True or false if succeeded.
        bool setData(void *d);

        /// @brief
        /// @return
        const char *getTag();

        /// @brief
        /// @param t
        /// @return True or false if succeeded.
        bool setTag(const char *t);

        /// @brief
        /// @return
        const char *getDescription();

        /// @brief
        /// @param d
        /// @return True or false if succeeded.
        bool setDescription(const char *d);

        /// @brief
        /// @return True or false if succeeded.
        bool initialize();

        /// @brief
        /// @return True or false if used.
        bool isUsed();

        /// @brief
        /// @param e
        /// @return
        const ELEMENT_TYPE getType();

        /// @brief
        /// @param t
        /// @return True or false if succeeded.
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
