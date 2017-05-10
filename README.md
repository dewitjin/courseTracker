# courseTracker

## Synopsis

This project grabs data from a text file filled with data about courses I am taking, stores the data in a list and displays a menu with option for sorting the data.

<br/>

![alt tag](https://cloud.githubusercontent.com/assets/6993716/24091648/931e9134-0d06-11e7-9e4b-bbd3eff7e944.PNG)

## Code Example

Upon execution, menu is displayed:<br/>

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25879441/952f3bba-34e6-11e7-9931-14c42bab42ac.PNG)
<br/>
This is the old menu. I will keep this image here for reference.<br/>
![alt tag](https://cloud.githubusercontent.com/assets/6993716/25874625/34d3cb3c-34c8-11e7-865d-29c08799746a.PNG)

TODO: create a menu option to insert, delete old data and then update binary file or txt file ?? Note to self: may not need to use pointers for this part.

TODO: Using C to create a list of anything requires basic knowledge about pointers and structures.  Unlike most programming languages, lists in C (linked list, stacks and quences) have to be created using pointers and structures.  So for example, this application creates a structure of courses to hold the data and in the structure I have inserted a pointer that points to the previous and next list node.  These pointers are what allows me to traverse through the list and displays the list in sorted order.  Lastly, the reason why I am creating a linked list instead of a standard array is because I don’t know how many list nodes I will need (how many courses I will take). By creating a linked list, the program can dynamically change the list size, which means in the future if I take 1 or 100 more courses, the program will be able to handle the data.  

<br/>

In C, however, using linked list is not efficient when you have really large list because in order to search for a particular item, you have to loop through the entire list to find a match.  Items may be inserted from various nodes (TODO check this assumption) . For stacks, items are inserted/removed from the front.  For quences, items are inserted from the back of the list and removed from the front.  

TODO: In order for to develop this application in one weekend, I borrowed course codes to insert node, delete node, and print list.  In class, I learnt a basic pattern to deal with how to insert/delete/print and the functions can be use in various way for any type of structure (courses, contacts, companies etc.)

TODO: Here are examples of insert, delete etc. that I learnt and I am borrowing from class.

This program parses each line from the file and then separate data by tokenizing the line using fgets(). Look in convert.c for the example.

## Motivation

This project exists because I need something to replace my current method of keeping track of what courses I am taking.  Currently, after I register for a course, I will get the course information and insert the data into an excel spreadsheet.  Since I am in multiple schools, I need a place to track all my courses and to help me get organize.   Since I am learning C programming right now, I have written the program in C.  Using C to create a list versus other programming languages is a bit more challenging but worth the challenge.

## Installation

In order to run this code, you need an integrated development environment like Visual Studio.  This program is created using Visual Studio 2015 and started with an empty Win32 Console Application.

This program uses cmd line arguments to get file input name.  In visual studio, you would input the file name like this:
<br/>

This is for convert.c:
![alt tag](https://cloud.githubusercontent.com/assets/6993716/25874659/5e702e86-34c8-11e7-9652-f800d8f07109.PNG)

This is for display.c:
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


## Other Helpful Images

Currently, the program does not check if the user really wants to override the output file.  I have coded it so that the check is disabled.  It is good practice though to check with the user that the user knows the file will be overwritten.

This code to check for this is in convert.c:
<br/>
![alt tag](https://cloud.githubusercontent.com/assets/6993716/25875247/433c2112-34cb-11e7-96d6-554be2e021a9.PNG)

<br/>
The output message is this:
<br/>

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25874667/665d75e0-34c8-11e7-8d7e-d733118d6e68.PNG)

<br/>

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25874671/6a09e0ca-34c8-11e7-9519-1e24d4e35828.PNG)

<br/>

display.c option 1 will give you the above image and also write to a text file, which will contain all the same data.

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25877906/a283c44e-34db-11e7-9258-d4367893179b.PNG)

Note: if you wanted to send this program to a client, you would create an empty folder and insert the executable with the data files like this:

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25875109/a9c60570-34ca-11e7-9453-d4ab94cd3332.PNG)

If you are using Visual Studio 2015, the executable file would be in the parent debug folder like this:

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25875112/ad6fd14c-34ca-11e7-9274-440d36e570fa.PNG)

Note: originally, the executable is named with the same name as your project file (all my test projects are named foo, but you can rename the executable to something more meangingful)

In order for this executable to run properly, however, I had to edit code to this:

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25875696/bc989728-34cd-11e7-9ddb-fbb38caf1cc3.PNG)

<br/>

Alternatively, instead of hardcoding the data input file name in VS, you can run the executable with the data in file name in the command prompt. <br/>

This is the executable for display.c - I renamed it to courseTracker.exe for this image:

<br/>

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25878043/a982ac00-34dc-11e7-83c9-e4a509acad37.PNG)

<br/>

Using the command prompt you would instruct the prompt to open the executable with the one argument - clients.dat

<br/>

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25877904/9e7532b6-34db-11e7-9231-32e4c66f2971.PNG)

TODO: As of May 9, 2017 I am getting the client.dat input to display the correct data on the console and txt file using Visual Studio, but the program is not writing to the text file using just the executable via the command prompt. - need to fix

<br/>

With the new menu (implemented on May 9, 2017), users will get a message like this:

<br/>

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25879521/f34406ae-34e6-11e7-8c0b-a9d2290b1c04.PNG)

<br/>

Option 3 - new record added displays data on prompt like this:

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25879558/23d2e9a2-34e7-11e7-9eac-42da25af3f4a.PNG)

<br/>

Confirmation of new record inserted in text file.

<br/>

![alt tag](https://cloud.githubusercontent.com/assets/6993716/25879561/27c73932-34e7-11e7-8c5f-50e1dc9848ed.PNG)


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
