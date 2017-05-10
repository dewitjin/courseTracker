#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	This program takes the DAT file that convert.c outputs and reads 
	and displays the data onto the console.

	TODO: displays an option to insert/delete courses, updating the DAT
	file, and displaying the DAT file again and sending data to TXT file for print version.

	TODO: add an option to write the new TXT file for printing separately from just printing to console?

	TODO: add option to sort data in various ways, ascending, descending order etc.

	TODO: add option to update, delete, insert a new course
*/

#define INPUT_FILE "courses.dat" //program reads from a DAT file
#define OUTPUT_FILE "newCourseList.txt" //program creates a text file for printing

#define MAX_CSV_LINE_LENGTH 2000	

#define MAX_SCHOOL_NAME_LENTGH			100
#define MAX_COURSE_ID_LENGTH			100
#define MAX_COURSE_NAME_LENGTH			100
#define MAX_FIRST_NAME_LENGTH			40
#define MAX_LAST_NAME_LENGTH			40
#define MAX_COURSE_OUTCOME_LENGTH		100
#define MAX_COURSE_EXTRA_INFO_LENGTH	100

#define DIVIDER "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------"

//prototypes:
int enterChoice(void);
void printToConsoleAndTextFile(FILE *fpInputFile, FILE *fpOuput);

void newRecord(FILE *fpInputFile);

typedef struct {

	char schoolName[MAX_SCHOOL_NAME_LENTGH + 1];//plus one ensures there is enough space for null
	int	 year;
	char courseName[MAX_COURSE_NAME_LENGTH + 1];
	char courseID[MAX_COURSE_ID_LENGTH + 1];
	char teacherFirstName[MAX_FIRST_NAME_LENGTH + 1];
	char teacherLastName[MAX_LAST_NAME_LENGTH + 1];
	char courseOutcome[MAX_COURSE_OUTCOME_LENGTH + 1];
	char extraInfo[MAX_COURSE_EXTRA_INFO_LENGTH + 1];

} Course;


int main(int argc, char *argv[]) {		//argc number of arguments passed, argv array of strings passed

	//uncomment when testing in VS
	char *pDataOutTxt = argv[1];		//courses.dat - passed via cmdline, index zero is the project name

	//char *pDataOutTxt = "courses.dat";//use this to create executable

	FILE *fpInputFile = fopen(pDataOutTxt, "rb"); //make sure we have '+' or else we can't update etc - not sure if we need this since we are just reading the binary file once and not writing to it back
	
	//testing
	FILE *fpOutput = fopen(OUTPUT_FILE, "w");//remember we are reading a binary file courses.dat but writing to newCourseList.txt
	//end of testing



	//check if the file to be read is called courses.dat
	if (argc == 2) {
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

	int choice; //user input
	
	//fopen opens the file; exit if file cannot be opened
	if (!fpInputFile) {
		printf("Error - Unable to open/create file <%s>.\n", INPUT_FILE);
		return 1;
	}
	else {
		while ((choice = enterChoice()) != 5)
		{
			switch (choice)
			{

			case 1:
				printToConsoleAndTextFile(fpInputFile, fpOutput);//testing
				break;

			case 2:
				//updateRecord(fpInputFile); TODO not done
				break;

			case 3:
				newRecord(fpInputFile);
				break;

			case 4:
				//deleteRecord(fpInputFile); TODO not done
				break;

			default:
				printf("Incorrect choice\n");
				break;
			}
		}
	}

	//close files
	fclose(fpInputFile);
	fclose(fpOutput); //file gets open when user prints out stuff but close it at the end of program for safety

	system("pause");
	return 0;
}

//add a new course
void newRecord(FILE *fpInputFile) {

	Course temp = { { 0 }, 0,{ 0 },{ 0 },{ 0 },{ 0 },{ 0 },{ 0 } };	//note {0} is an empty string

	char courseID[20];	//remember to create an array here and not a pointer like char *courseID, because scanf takes a pointer, and array names are actually pointers already!

	//obtain the course ID to insert
	printf("Enter a new course ID (must contain no spaces): ");
	scanf("%s", courseID);
	while (getchar() != '\n');
	
	// read record from file
	fread(&temp, sizeof(Course), 1, fpInputFile);

	if (strcmp(temp.courseID, courseID) == 0 ) { //read the courses inside the DAT file and see if the course already exists, compare with strcmp or else we aren't comparing actually string content just the address
		printf("Course < %s > is already in < %s >.\n",
			temp.courseID, fpInputFile);
	}
	else {

		//get user input
		printf("Enter school name: ");
		fgets(&temp.schoolName, 100, stdin);
		char *pSchoolName = temp.schoolName;//whenever fgets is used, we have to do this
		while (*pSchoolName != '\0')
		{
			pSchoolName++;
		}
		*(pSchoolName - 1) = '\0';//fgets adds a new line character so need to replace the new line with a null

		printf("Enter year: ");
		scanf("%d", &temp.year);
		while (getchar() != '\n');

		printf("Enter course name: ");
		fgets(&temp.courseName, 100, stdin);
		char *pCourseName = temp.courseName;
		while (*pCourseName != '\0')
		{
			pCourseName++;
		}
		*(pCourseName - 1) = '\0';

		strcpy(temp.courseID,courseID);//don't need to ask user for course ID again just assign it with strcpy or else the content won't be copied properly

		printf("Enter first name (no spaces allowed): ");
		scanf("%s", &temp.teacherFirstName);
		while (getchar() != '\n');

		printf("Enter last name (no spaces allowed): ");
		scanf("%s", &temp.teacherLastName);
		while (getchar() != '\n');

		printf("Enter course outcome: ");
		fgets(&temp.courseOutcome, 100, stdin);
		char *pCourseOutcome = temp.courseOutcome;
		while (*pCourseOutcome != '\0')
		{
			pCourseOutcome++;
		}
		*(pCourseOutcome - 1) = '\0';

		printf("Enter extra info: ");
		fgets(&temp.extraInfo, 100, stdin);
		char *pExtraInfo = temp.extraInfo;
		while (*pExtraInfo != '\0')
		{
			pExtraInfo++;
		}
		*(pExtraInfo - 1) = '\0';
		
		// insert record in to DAT file courses.csv not the newCourseList.txt, txt is updated when you enter option 1
		fwrite(&temp, sizeof(Course), 1, fpInputFile);

		//TODO add some kind of count check read DAT file make sure one more row is added ??

		//print to console to check
		printf("\nYou have entered this to < %s >\n", INPUT_FILE);
		printf("Warning - changes to txt file might not happened right away.\n");
		printf("%-12s %d %-28s %-20s %-20s %-20s %-50s %-50s\n",
			temp.schoolName,
			temp.year,
			temp.courseName,
			temp.courseID,
			temp.teacherFirstName,
			temp.teacherLastName,
			temp.courseOutcome,
			temp.extraInfo);
	}
}

//print data to console and new text file for printing
void printToConsoleAndTextFile(FILE *fpInputFile, FILE *fpOutput) {

	//FILE *fpOutput = fopen(OUTPUT_FILE, "w");//remember we are reading a binary file courses.dat but writing to newCourseList.txt

	Course temp = { { 0 }, 0,{ 0 },{ 0 },{ 0 },{ 0 },{ 0 },{ 0 } };	//note {0} is an empty string

	if (!fpOutput) {
		printf("Error - Unable to open/create file <%s>.\n", OUTPUT_FILE);
		return 1;
	}
	else 
	{													
		//print header to console for debug
		//start of code to read from binary file to console
		printf("%-12s %s %-28s %-20s %-20s %-20s %-50s %-50s\n", "SCHOOL NAME", "YEAR", "COURSE NAME", "COURSE ID", "PROF FIRST NAME", "PROF LAST NAME", "COURSE OUTCOME", "EXTRA INFO"); //start printing header
		printf("%s\n", DIVIDER);

		//print out the header to text file
		fprintf(fpOutput, "%s\n", "test");//write to new file


		fprintf(fpOutput, "%-12s %s %-28s %-20s %-20s %-20s %-50s %-50s\n", 
			"SCHOOL NAME", "YEAR", "COURSE NAME", "COURSE ID", 
			"PROF FIRST NAME", "PROF LAST NAME", "COURSE OUTCOME", "EXTRA INFO"); //start printing header
		
		fprintf(fpOutput, "%s\n", DIVIDER);

		//rewind(fpInputFile);//set pointer to beginning of file
		while (!feof(fpInputFile)) {

			int bytesRead = fread(&temp, sizeof(Course), 1, fpInputFile);//reading from a binary file
			if (bytesRead > 0) {

				//print to console
				printf("%-12s %d %-28s %-20s %-20s %-20s %-50s %-50s\n",
					temp.schoolName,
					temp.year,
					temp.courseName,
					temp.courseID,
					temp.teacherFirstName,
					temp.teacherLastName,
					temp.courseOutcome,
					temp.extraInfo);

				////print to txt file
				fprintf(fpOutput,"%-12s %d %-28s %-20s %-20s %-20s %-50s %-50s\n",
					temp.schoolName,
					temp.year,
					temp.courseName,
					temp.courseID,
					temp.teacherFirstName,
					temp.teacherLastName,
					temp.courseOutcome,
					temp.extraInfo);
			}//end of if
		}

		printf("%s\n", DIVIDER);
		fprintf(fpOutput, "%s\n", DIVIDER);

	}//end of else
}


//start of menu option, code borrowed from class
int enterChoice(void)
{
	int menuChoice;

	printf("\nEnter your choice\n"
		"1 - store a formatted text file of courses called\n"
		"    < %s > for printing\n"
		"2 - update an course\n"
		"3 - add a new course\n"
		"4 - delete an course\n"
		"5 - end program\n? ", OUTPUT_FILE);

	scanf("%d", &menuChoice);
	while (getchar() != '\n');
	return menuChoice;
}

//TODO when insertering, updating, or deleting records, remember to update the DAT file or else the new text file will not be the most updated
