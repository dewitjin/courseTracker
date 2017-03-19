# courseTracker

## Synopsis

This project grabs data from a text file filled with data about courses I am taking, stores the data in a list and displays a menu with option for sorting the data.

## Code Example

Using C to create a list of anything requires basic knowledge about pointers and structures.  Unlike most programming languages, lists in C (linked list, stacks and quences) have to be created using pointers and structures.  So for example, this application creates a structure of courses to hold the data and in the structure I have inserted a pointer that points to the previous and next list node.  These pointers are what allows me to traverse through the list and displays the list in sorted order.  Lastly, the reason why I am creating a linked list instead of a standard array is because I don’t know how many list nodes I will need (how many courses I will take). By creating a linked list, the program can dynamically change the list size, which means in the future if I take 1 or 100 more courses, the program will be able to handle the data. 

TODO: In order for to develop this application in one weekend, I borrowed course codes to insert node, delete node, and print list.  In class, I learnt a basic pattern to deal with how to insert/delete/print and the functions can be use in various way for any type of structure (courses, contacts, companies etc.)

TODO: Here are examples of insert, delete etc. that I learnt and I am borrowing from class.

## Motivation


This project exists because I need something to replace my current method of keeping track of what courses I am taking.  Currently, after I register for a course, I will get the course information and insert the data into an excel spreadsheet.  Since I am in multiple schools, I need a place to track all my courses and to help me get organize.   Since I am learning C programming right now, I have written the program in C.  Using C to create a list versus other programming languages is a bit more challenging but worth the challenge.

## Installation

In order to run this code, you need an integrated development environment like Visual Studio.  This program is created using Visual Studio 2015 and started with an empty Win32 Console Application.

## API Reference

None.

## Tests

No test.

## Contributors

The best way to reach me is via my email at dewi.tjin + @ + gmail.com.

If you would like to contribute please fork the repo and I will review code.

## License

Copyright 2017 DEWI TJIN

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
