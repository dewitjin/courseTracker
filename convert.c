#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	This program reads a CSV file, parses each line, populates structures 
	and writes the struct to a file in binary format (overwriting the file if it exists).
	The only reason why I am converting the file to binary format is to show that you can do it.
	If security is not an issue, users can just change this code to wrtie to a normal text file 
	(by changing 'wb' to 'w' on line 49 and then changing the file names).

	TODO: displays an option to insert/delete course before writing to the binary file ? already did it in display.c might not need it here

*/

#define INPUT_FILE "courses.csv" 
#define OUTPUT_FILE "courses.dat" //use this to read in display.c

#define MAX_CSV_LINE_LENGTH 2000	

#define MAX_SCHOOL_NAME_LENTGH			100
#define MAX_COURSE_ID_LENGTH			100
#define MAX_COURSE_NAME_LENGTH			100
#define MAX_FIRST_NAME_LENGTH			40
#define MAX_LAST_NAME_LENGTH			40
#define MAX_COURSE_OUTCOME_LENGTH		100
#define MAX_COURSE_EXTRA_INFO_LENGTH	100


typedef struct {
	
	char schoolName			[MAX_SCHOOL_NAME_LENTGH + 1];
	int	 year;
	char courseName			[MAX_COURSE_NAME_LENGTH + 1];
	char courseID			[MAX_COURSE_ID_LENGTH + 1];
	char teacherFirstName	[MAX_FIRST_NAME_LENGTH + 1];
	char teacherLastName	[MAX_LAST_NAME_LENGTH + 1];
	char courseOutcome		[MAX_COURSE_OUTCOME_LENGTH + 1];
	char extraInfo			[MAX_COURSE_EXTRA_INFO_LENGTH + 1];
} Course;


int main(int argc, char *argv[]) {					//argc number of arguments passed, argv array of strings passed

	char *pDataOutTxt = argv[1];					//courses.csv - passed via cmdline

	FILE *fpInputFile = fopen(pDataOutTxt, "r");
	FILE *fpOutputFile = fopen(OUTPUT_FILE, "wb");	//convert courses.csv to a binary file named courses.dat, wb creates a file to write in binary mode, if the file exists, discard the current contents
									  
	if (argc == 2) {								//check if the file to be read is called courses.csv
		if (!(strcmp(argv[1], INPUT_FILE)) == 0) {
			printf("The argument supplied is incorrect.\nIt should be <%s> but instead it is <%s>.\n", INPUT_FILE, argv[1]);
			return 1;
		}
	}
	else if (argc > 2) {
		printf("Error - Too many arugments supplied.\n");
		return 1;
	}
	else {
		printf("Error - One argument expected.\n");
		return 1;
	}//end of (argc == 2)

	//fopen opens the file; exit if file cannot be opened
	if (!fpInputFile) {
		printf("Error - Unable to open/create file < %s >.\n", INPUT_FILE);
		return 1;
	}


	int promptInput;	//  while testing on terminal with Mac - I had prompt input like this char promptInput[0];  
	printf("%s%s",	"Warning - This program is design to override the existing file.\n", 
					"Press < 1 > to continue, or press < 0 > to exit program.\n\n");
	
	promptInput = 1;				//TODO delete this assignment after testing so you don't have to always enter < 1 >
	// scanf("%d", &promptInput); // TODO uncomment to start asking  user properly
	
	if (promptInput != 1) {
		printf("You did not entered < 1 > . Program will end now. Thank-you.\n");
		return 1;
	}
	else {
		printf("You entered < 1 > . <%s> will overwritten now.\n", OUTPUT_FILE);
	}

	Course temp = { { 0 }, 0, { 0 },{ 0 },{ 0 },{ 0 },{ 0 }, { 0 } };	//note {0} is an empty string
	char csvLine[MAX_CSV_LINE_LENGTH + 1] = { 0 };						//will contain the each line in file
	char *pToken = NULL;

	rewind(fpInputFile); //set pointer to beginning of file
	while (!feof(fpInputFile)) {

		if (fgets(csvLine, MAX_CSV_LINE_LENGTH, fpInputFile) != NULL) {//scan first line

			csvLine[strlen(csvLine) - 1] = '\0'; //gets rid of new line character in file
			pToken = strtok(csvLine, ",");		//parse line with spaces

			if (pToken != NULL) {

				strcpy(temp.schoolName, pToken);
				pToken = strtok(NULL, ",");
				
				temp.year = atoi(pToken);
				pToken = strtok(NULL, ",");

				strcpy(temp.courseName, pToken);
				pToken = strtok(NULL, ",");

				strcpy(temp.courseID, pToken);
				pToken = strtok(NULL, ",");

				strcpy(temp.teacherFirstName, pToken);
				pToken = strtok(NULL, ",");

				strcpy(temp.teacherLastName, pToken);
				pToken = strtok(NULL, ",");

				strcpy(temp.courseOutcome, pToken);
				pToken = strtok(NULL, ",");

				strcpy(temp.extraInfo, pToken);
				pToken = strtok(NULL, ",");

				pToken = strtok(NULL, ",");//loops through the same line until we find a NULL at the end of the line

				//uncomment if you want to see content on console for debugging
				/**printf("%-12s %d %-28s %-20s %-8s %-8s %-50s %-50s\n",
					temp.schoolName,
					temp.year,
					temp.courseName,
					temp.courseID,
					temp.teacherFirstName,
					temp.teacherLastName,
					temp.courseOutcome,
					temp.extraInfo);**/
				//end of uncomment debugging code					   
										   
				fwrite(&temp, sizeof(Course), 1, fpOutputFile);

			}//end of if
		}//end of fgets
	}

	//close files
	fclose(fpInputFile);
	fclose(fpOutputFile);

	return 0;
}

