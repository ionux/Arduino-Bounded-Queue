/**
 * QueueElement.cpp
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


#include "QueueElement.h"


QueueElement::QueueElement()
{
}

QueueElement::~QueueElement()
{
}

QueueElement *QueueElement::getNext()
{
    return nullptr;
}

void QueueElement::setNext(QueueElement *e)
{
}

void QueueElement::setPrevious()
{
}

QueueElement *QueueElement::getPrevios()
{
    return nullptr;
}

void *QueueElement::getData()
{
    return nullptr;
}

void QueueElement::setData(void *d)
{
}

char *QueueElement::getTag()
{
    return nullptr;
}

void QueueElement::setTag(char *t)
{
}

char *QueueElement::getDescription()
{
    return nullptr;
}

void QueueElement::setDescription(char *d)
{
}

void QueueElement::initialize()
{
}

bool QueueElement::isUsed()
{
    return false;
}
