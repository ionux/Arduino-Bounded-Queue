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

#include "BoundedQueueElement.h"

namespace BoundedQueue
{
    Element::Element()
    {
        // Ignoring return code for first initialization.
        (void)this->initialize();
    }

    Element::~Element()
    {
        // Ignoring return code for destruction.
        (void)this->initialize();
    }

    const Element *Element::getNext()
    {
        return this->next;
    }

    bool Element::setNext(Element *e)
    {
        this->next = e;

        return true;
    }

    bool Element::setPrevious(Element *e)
    {
        this->prev = e;

        return true;
    }

    const Element *Element::getPrevious()
    {
        return this->prev;
    }

    void *Element::getData()
    {
        return this->data;
    }

    bool Element::setData(void *d)
    {
        this->data = d;

        return true;
    }

    const char *Element::getTag()
    {
        return this->tag;
    }

    bool Element::setTag(const char *t)
    {
        if (t != NULL)
        {
            for (unsigned int i = 0; (i < MAX_TAG_SIZE) && (t[i] != '\0'); i++)
            {
                this->tag[i] = static_cast<char>(t[i]);
            }

            // Ensure the tag is null-terminated
            this->tag[MAX_TAG_SIZE - 1] = '\0';

            return true;
        }

        return false;
    }

    const char *Element::getDescription()
    {
        return this->description;
    }

    bool Element::setDescription(const char *d)
    {
        if (d != NULL)
        {
            for (unsigned int i = 0; (i < MAX_DESCRIPTION_SIZE) && (d[i] != '\0'); i++)
            {
                this->description[i] = static_cast<char>(d[i]);
            }

            // Ensure the description is null-terminated
            this->description[MAX_DESCRIPTION_SIZE - 1] = '\0';

            return true;
        }

        return false;
    }

    bool Element::initialize()
    {
        this->data = NULL;
        this->next = NULL;
        this->prev = NULL;

        this->myType = UNKNOWN;

        this->used = false;

        for (unsigned int i = 0; i < MAX_DESCRIPTION_SIZE; i++)
        {
            this->description[i] = '\0';
        }

        for (unsigned int i = 0; i < MAX_TAG_SIZE; i++)
        {
            this->tag[i] = '\0';
        }

        return true;
    }

    bool Element::isUsed()
    {
        return this->used;
    }

    const ELEMENT_TYPE Element::getType()
    {
        return this->myType;
    }

    bool Element::setType(const ELEMENT_TYPE t)
    {
        switch (t)
        {
        case HEAD:
            this->myType = HEAD;
            break;
        case TAIL:
            this->myType = TAIL;
            break;
        case MEMBER:
            // Member is an intermediate element, i.e. not head or tail but in the queue somewhere.
            this->myType = MEMBER;
            break;
        case UNKNOWN:
            // Should never assign this aside from initialization or deletion.
            // Intentional fall through.
        default:
            // Satisfies safety compliance guidelines. Log if enabled?
            this->myType = UNKNOWN;
            break;
        }

        return false;
    }
} // namespace BoundedQueue
