# courseTracker

## Synopsis

This project grabs data from a text file filled with data about courses I am taking, stores the data in a list and displays a menu with option for sorting the data.

The program outputs this to the console like this, minus the display menu:
![alt tag](https://cloud.githubusercontent.com/assets/6993716/24091648/931e9134-0d06-11e7-9e4b-bbd3eff7e944.PNG)

## Code Example

TODO: create a menu option to insert, delete old data and then update binary file or txt file ?? Note to self: may not need to use pointers for this part.

TODO: Using C to create a list of anything requires basic knowledge about pointers and structures.  Unlike most programming languages, lists in C (linked list, stacks and quences) have to be created using pointers and structures.  So for example, this application creates a structure of courses to hold the data and in the structure I have inserted a pointer that points to the previous and next list node.  These pointers are what allows me to traverse through the list and displays the list in sorted order.  Lastly, the reason why I am creating a linked list instead of a standard array is because I don’t know how many list nodes I will need (how many courses I will take). By creating a linked list, the program can dynamically change the list size, which means in the future if I take 1 or 100 more courses, the program will be able to handle the data. 

TODO: In order for to develop this application in one weekend, I borrowed course codes to insert node, delete node, and print list.  In class, I learnt a basic pattern to deal with how to insert/delete/print and the functions can be use in various way for any type of structure (courses, contacts, companies etc.)

TODO: Here are examples of insert, delete etc. that I learnt and I am borrowing from class.

This program parses each line from the file and then separate data by tokenizing the line using fgets(). Look in convert.c for the example.

## Motivation

This project exists because I need something to replace my current method of keeping track of what courses I am taking.  Currently, after I register for a course, I will get the course information and insert the data into an excel spreadsheet.  Since I am in multiple schools, I need a place to track all my courses and to help me get organize.   Since I am learning C programming right now, I have written the program in C.  Using C to create a list versus other programming languages is a bit more challenging but worth the challenge.

## Installation

In order to run this code, you need an integrated development environment like Visual Studio.  This program is created using Visual Studio 2015 and started with an empty Win32 Console Application.

This program uses cmd line arguments to get file input name.  In visual studio, you would input the file name like this:

![alt tag](https://cloud.githubusercontent.com/assets/6993716/24091287/732a33d0-0d04-11e7-9672-2544b89ca0eb.PNG)

Currently, I have all my courses in a spreadsheet saved as XLSX file.  XLSX is a file extension for an open XML spreadsheet file format used by Microsoft Excel.  In order to make the file work with this program, however, I had to save the file as a CSV.  CSV is a simple file format used to store tabular data, such as a spreadsheet or database.  CSV stands for "comma-separated values".  Saving the file to a CSV makes it easier to read the data and separate the columns because I can tell this program to separate the data by 'commas'.

In order to save a file to CSV, do this in excel:

![alt tag](https://cloud.githubusercontent.com/assets/6993716/24091524/d796e394-0d05-11e7-844d-0003a2b24e2c.PNG)

Note: 
In order to ensure readablilty, empty cells are manually inserted with 'N/A'.  
When I converted the spreadsheet to a CSV, I did not save the header information too.  I will add my own header via a printf function in display.c.

In the end, I had to delete a lot of the bad data in my csv file.  This program will not strip out the extra commas in sentences and does not deal with really long text well.  I ended up having to change the csv file so it looks simple like this:

![alt tag](https://cloud.githubusercontent.com/assets/6993716/24091547/f3b93a36-0d05-11e7-9f95-01ba7c3878ff.PNG)

TODO:feature to deal with clean up long text, and deal with commas and spaces in cell so I don't have to deal with it manually.

Program execution:

There are currently 2 files with a main function.  Run the file one at a time.

Step 1: run convert.c to convert a CSV file to a DAT file.

Step 2: run display.c to display the data from a DAT file, and produces a TXT file for printing.

This program converts the csv to a dat file only for demostration.  Users can merge the two files together and eliminate the code to convert to DAT, if desired.

When working with visual studio 2015, ensure all DAT, CSV files are in the project folders like this.  For this example, I created a project called foo because it is where I usually store all my testing code.

![alt tag](https://cloud.githubusercontent.com/assets/6993716/24091573/1a923ad6-0d06-11e7-9ef5-f5d8b11dbd0c.PNG)

## API Reference

None.

## Tests

No test.

## Contributors

The best way to reach me is via my email at dewi.tjin + @ + gmail.com.

If you would like to contribute please fork the repo and I will review code.  I would like help/advice on how to add a feature to deal with cleaning up long text in CSV files, and deal with commas and spaces in cell so I don't have to deal with it manually.

## License

Copyright 2017 DEWI TJIN

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
