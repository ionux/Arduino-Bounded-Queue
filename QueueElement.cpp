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

#include "QueueElement.h"

QueueElement::QueueElement()
{
  this->initialize();
}

QueueElement::~QueueElement()
{
  this->initialize();
}

QueueElement *QueueElement::getNext()
{
  return nullptr;
}

bool QueueElement::setNext(QueueElement *e)
{
  return false;
}

bool QueueElement::setPrevious(QueueElement *e)
{
  return false;
}

QueueElement *QueueElement::getPrevious()
{
  return nullptr;
}

void *QueueElement::getData()
{
  return nullptr;
}

bool QueueElement::setData(void *d)
{
  return false;
}

char *QueueElement::getTag()
{
  return nullptr;
}

bool QueueElement::setTag(char *t)
{
  return false;
}

char *QueueElement::getDescription()
{
  return nullptr;
}

bool QueueElement::setDescription(char *d)
{
  return false;
}

bool QueueElement::initialize()
{
  this->data = nullptr;
  this->next = nullptr;
  this->prev = nullptr;

  this->myType = ELEMENT_TYPE::UNKNOWN;

  this->used = false;

  for (unsigned int i = 0; i < MAX_QE_DESCRIPTION_SIZE; i++)
  {
    this->description[i] = {0};
  }

  for (unsigned int i = 0; i < MAX_QE_TAG_SIZE; i++)
  {
    this->tag[i] = {0};
  }

  return true;
}

bool QueueElement::isUsed()
{
  return this->used;
}

ELEMENT_TYPE QueueElement::getType()
{
  return this->myType;
}

bool QueueElement::setType(ELEMENT_TYPE t)
{
  switch (t)
  {
  case ELEMENT_TYPE::HEAD:
    this->myType = ELEMENT_TYPE::HEAD;
    break;
  case ELEMENT_TYPE::TAIL:
    this->myType = ELEMENT_TYPE::TAIL;
    break;
  case ELEMENT_TYPE::MEMBER:
    // Member is an intermediate element, i.e. not head or tail but in the queue somewhere.
    this->myType = ELEMENT_TYPE::MEMBER;
    break;
  case ELEMENT_TYPE::UNKNOWN:
    // Should never assign this aside from initialization or deletion.
    // Intentional fall through.
  default:
    // Satisfies safety compliance guidelines. Log if enabled?
    this->myType = ELEMENT_TYPE::UNKNOWN;
    break;
  }

  return false;
}
