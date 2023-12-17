/**
 * QueueElement.h
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


/// @brief 
class QueueElement
{
  public:
    /// @brief 
    QueueElement();

    /// @brief 
    ~QueueElement();

    /// @brief 
    /// @return 
    QueueElement* getNext();

    /// @brief 
    /// @return 
    QueueElement* getPrevios();

    /// @brief 
    /// @return 
    void* getData();

    /// @brief 
    /// @param d 
    void setData(void *d);

    /// @brief 
    /// @return 
    char* getTag();

    /// @brief 
    /// @param t 
    void setTag(char* t);

    /// @brief 
    /// @return 
    char* getDescription();

    /// @brief 
    /// @param d 
    void setDescription(char* d);

    /// @brief 
    void initialize();

    /// @brief 
    /// @return 
    bool isUsed();

  private:
    /// @brief 
    void *data;

    /// @brief 
    char tag[32];

    /// @brief 
    char description[256];

    /// @brief 
    bool used;

    /// @brief 
    QueueElement *next;

    /// @brief 
    QueueElement *prev;

    /// @brief 
    /// @param e 
    void setNext(QueueElement* e);

    /// @brief 
    void setPrevious();
};
