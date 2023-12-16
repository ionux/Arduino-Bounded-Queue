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


#include "Queue.h"

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
  return insert_next(data);
}

QueueElement *Queue::dequeue()
{
  return remove_next();
}

QueueElement *Queue::peek()
{
  return nullptr;
}

unsigned int Queue::count()
{
  return 0;
}

void Queue::initialize()
{
  this->size = 0;
  this->head = nullptr;
  this->tail = nullptr;
}

void Queue::destroy()
{
  bool loopCondition = true;

  while (this->size > 0 && loopCondition == true)
  {
    if (remove_next() == nullptr)
    {
      loopCondition = false;
    }
  }

  this->size = 0;
}

bool Queue::insert_next(const void *data)
{
  bool returnCondition = false;

  QueueElement *new_element = nullptr;

  // Allocate storage for the element.
  // TODO: refactor to be fixed size queue
  if ((new_element = (QueueElement *)malloc(sizeof(QueueElement))) == NULL)
  {
    return -1;
  }

  new_element->data = (void *)data;

  if (this->size == 0)
  {
    this->tail = new_element;
  }

  new_element->next = this->head;
  this->head = new_element;

  //  Adjust the size of the list to account for the inserted element.
  this->size++;

  return returnCondition;
}

QueueElement *Queue::remove_next()
{
  if (this->size <= 0 || this->head == nullptr || this->tail == nullptr)
  {
    this->size = 0;

    return nullptr;
  }

  QueueElement *element_to_return = nullptr;

  
  
  this->size--;

  return element_to_return;
}

QueueElement *Queue::get_head()
{
  return this->head;
}

QueueElement *Queue::get_tail()
{
  return this->tail;
}

bool Queue::element_is_head(QueueElement *e)
{
  return false;
}

bool Queue::element_is_tail(QueueElement *e)
{
  return false;
}
