# courseTracker

## Synopsis

This project grabs data from a text file filled with data about courses I am taking, stores the data in a list and displays a menu with option for sorting the data.

## Code Example

TODO: create a menu option to insert, delete old data and then update binary file or txt file ??

TODO: Using C to create a list of anything requires basic knowledge about pointers and structures.  Unlike most programming languages, lists in C (linked list, stacks and quences) have to be created using pointers and structures.  So for example, this application creates a structure of courses to hold the data and in the structure I have inserted a pointer that points to the previous and next list node.  These pointers are what allows me to traverse through the list and displays the list in sorted order.  Lastly, the reason why I am creating a linked list instead of a standard array is because I don’t know how many list nodes I will need (how many courses I will take). By creating a linked list, the program can dynamically change the list size, which means in the future if I take 1 or 100 more courses, the program will be able to handle the data. 

TODO: In order for to develop this application in one weekend, I borrowed course codes to insert node, delete node, and print list.  In class, I learnt a basic pattern to deal with how to insert/delete/print and the functions can be use in various way for any type of structure (courses, contacts, companies etc.)

TODO: Here are examples of insert, delete etc. that I learnt and I am borrowing from class.

## Motivation


This project exists because I need something to replace my current method of keeping track of what courses I am taking.  Currently, after I register for a course, I will get the course information and insert the data into an excel spreadsheet.  Since I am in multiple schools, I need a place to track all my courses and to help me get organize.   Since I am learning C programming right now, I have written the program in C.  Using C to create a list versus other programming languages is a bit more challenging but worth the challenge.

## Installation

In order to run this code, you need an integrated development environment like Visual Studio.  This program is created using Visual Studio 2015 and started with an empty Win32 Console Application.

TODO: add an image to insert cmd arguments using visual studio

Currently, I have all my courses in a spreadsheet saved as XLSX file.  XLSX is a file extension for an open XML spreadsheet file format used by Microsoft Excel.  In order to make the file work with this program, however, I had to save the file as a CSV.  CSV is a simple file format used to store tabular data, such as a spreadsheet or database.  CSV stands for "comma-separated values".  Saving the file to a CSV makes it easier to read the data and separate because I can tell this program to separate the data by 'commas'.

In order to save a file to CSV, do this:

TODO: add image of excel spreadsheet and save as option.



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
