# !!!!This is a Work In Progress!!!!

# Arduino-Queue
Helpful software library for quickly &amp; easily adding support for queues to your Arduino project.


## Description
A queue is a type of linear data structure that provides a consistent way to manage information.  Queues have a number of useful properties that make them perfect for situations when you need to "queue up" data to be processed in a sequential & orderly manner, like a buffer.

Basically, imagine standing in line to ride a roller coaster.  New riders are added to the end of the line when they walk up.  Only people at the front of the line are allowed to board & ride the coaster when it arrives at the station.  Everyone else in line are moved up when others are removed from the front.

This is exactly how a queue stores data:  new items are only added (enqueue) to the rear, existing items are only removed (dequeue) from the front.  Another operation, peek, allows you to see what the next item is without actually removing it.  In more formal terms, a queue is classified as a first-in, first-out (FIFO) data structure.


## Usage
See the Arduino sketch in the `examples/` folder for an example of how to use the Queue class in your sketches.


## Contributing
If you've found a bug or improvement, feel free to submit an update!  Here's how to do it for this project:
* Create a new branch off master for your changes.
* Clone the repository to your local development machine.
* Change to your new branch, make the updates & save the files.
* Add, commit & push your changes back to the repository.
* Create a new merge request so I can review your code.
* Once everything looks good and there are no errors or formatting issues, I'll approve & merge your code!


## License
MIT License

Copyright (c) 2023 Rich Morgan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
