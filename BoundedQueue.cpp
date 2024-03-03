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

#include "BoundedQueue.h"

namespace BoundedQueue
{
  Queue::Queue()
  {
    this->initialize();
  }

  Queue::~Queue()
  {
    this->destroy();
  }

  bool Queue::enqueue(void *data)
  {
    if (this->shiftElements())
    {
      return false;
    }

    this->elements[0].setData(data);

    return true;
  }

  bool Queue::enqueue(Element *e)
  {
    if (this->shiftElements())
    {
      return false;
    }

    this->copyElement(e, &this->elements[0]);

    return true;
  }

  Element *Queue::dequeue()
  {
    return this->head;
  }

  Element *Queue::peek()
  {
    // TODO
    return nullptr;
  }

  unsigned int Queue::getTotalSize()
  {
    return this->sizeTotal;
  }

  unsigned int Queue::getUsedSize()
  {
    return this->sizeUsed;
  }

  bool Queue::clear()
  {
    this->initialize();
  }

  bool Queue::destroy()
  {
    this->initialize();
  }

  bool Queue::shiftElements()
  {
    if (this->sizeUsed >= (this->sizeTotal - 1))
    {
      // Queue is full!
      return false;
    }

    Element *curr_element = nullptr;
    Element *next_element = nullptr;

    for (unsigned int i = this->sizeTotal - 1; i > 0; i--)
    {
      *curr_element = this->elements[i];
      *next_element = this->elements[i + 1];

      this->copyElement(curr_element, next_element);

      // erase current
      curr_element->initialize();
    }

    // set head element to last (size used)
    *this->head = this->elements[this->sizeTotal - 1];

    // reset tail to reference new first element
    *this->tail = this->elements[1];

    // erase first element
    this->elements[0].initialize();

    return true;
  }

  bool Queue::initialize()
  {
    this->sizeTotal = MAX_QUEUE_SIZE;
    this->sizeUsed = 0;

    for (unsigned int i = 0; i < this->sizeTotal; i++)
    {
      this->elements[i].initialize();
    }
  }

  unsigned int Queue::getFreeSpace()
  {
    return MAX_QUEUE_SIZE - this->sizeUsed;
  }

  bool Queue::copyElement(Element *source, Element *destination)
  {
    // deep copy source into destination
    destination->setData(source->getData());
    destination->setDescription(source->getDescription());
    destination->setTag(source->getTag());
  }

} // namespace BoundedQueue
