#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//Assignment 4 - Dewi Tjin
//Objective The purpose of this assignment is to practice pointer 
//manipulations in linked lists

// self-referential structure
struct listNode
{
	int data;
	struct listNode *pNext; // pointer to next node
};

typedef struct listNode ListNode;

// function prototypes
void printList(ListNode *pCurrent); //borrowed code
void insertNode(ListNode **pStart, int value); //borrowed code
ListNode *create();//return first node of ordered list
ListNode *merge(ListNode *pStartFirstList, ListNode *pStartSecondList);

int mainSecond() { //this program runs on it's own - in order to do so just pull this one file and change mainSecond to main()

	ListNode *pStartFirstList = NULL;
	ListNode *pStartSecondList = NULL;
	ListNode *pMergedList = NULL;

	printf("%s\n", "Input positive integers for the first list (end with a negative integer):");
	pStartFirstList = create();

	printf("\n%s\n", "Input positive integers for the second list (end with a negative integer):");
	pStartSecondList = create();

	printf("%s", "Contents of first list:\n");
	printList(pStartFirstList);

	printf("%s", "Contents of second list:\n");
	printList(pStartSecondList);

	printf("%s", "Contents of merged list:\n");
	pMergedList = merge(pStartFirstList, pStartSecondList);
	printList(pMergedList);

	system("pause");
}


//The create() function will return a pointer to the first node of the ordered list created.
ListNode *create() {

	int input;
	int badInput = 0;

	ListNode *pList = NULL;
	ListNode *pPrevious = NULL;

	//start of collecting input
	printf("? ");
	scanf("%d", &input); //remember the &, and double quotation
	while (getchar() != '\n');

	while (input >= badInput) {

		insertNode(&pList, input); //if this comes before the scanf then the badInput value will never get inserted into the list
		printf("? ");
		scanf("%d", &input); //remember the &, and double quotation
		while (getchar() != '\n');

	}

	return pList;
}

//TODO MH code only had one *
void insertNode(ListNode **pStart, int value) {
	ListNode *pNew;
	ListNode *pPrevious;
	ListNode *pCurrent;

	pNew = (ListNode*)malloc(sizeof(ListNode)); //first thing to do is to allocate memmory for pNew;

	if (pNew != NULL) { //initialize struct, set value and set pointers to null because we don't know where they need to be right now
		pNew->data = value;
		pNew->pNext = NULL;
		pPrevious = NULL;
		pCurrent = *pStart; //this only works if the parameter was **pStart not *pStart, then point the current pointer to the new pStart pointer 

							// loop to find the correct insertion point
		while (pCurrent != NULL && value > pCurrent->data) {
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}

		//insert the node at the head or not?
		if (pPrevious == NULL) {
			pNew->pNext = *pStart;
			*pStart = pNew;
		}
		else
		{
			//if we insert somewhere inside the list then we have to point pPrevious to pNew then update pNew->pNext to pCurrent
			pPrevious->pNext = pNew;
			pNew->pNext = pCurrent;
		}
	}
	else
	{
		printf("%d not inserted. No memory available.\n", value);
	}

}

//merge() function which receives as arguments pointers to the
//first node of each of the lists to be merged(determine if pointers to pointers are necessary
//for these arguments) and returns a pointer to the merged list.
ListNode *merge(ListNode *pStartFirstList, ListNode *pStartSecondList) {

	ListNode *pPrevious;
	ListNode *pCurrent;
	ListNode *pMergedList = NULL;

	while (1) {
		int value;

		if (pMergedList == NULL) {//initialize
			pMergedList = (ListNode*)malloc(sizeof(ListNode));
			pMergedList->pNext = NULL;
			pPrevious = NULL;
		}
		else if (pStartFirstList != NULL && pStartSecondList != NULL) {

			value = pStartFirstList->data;//initialize 
			pMergedList = pMergedList->pNext; //need to move list one ahead to avoid garbage value

			while (pStartFirstList != NULL && value > 0) {
				value = pStartFirstList->data;
				insertNode(&pMergedList, value);
				pStartFirstList = pStartFirstList->pNext;
			}

			while (pStartSecondList != NULL && value > 0) {
				value = pStartSecondList->data;
				insertNode(&pMergedList, value);
				pStartSecondList = pStartSecondList->pNext;
			}

			return pMergedList;
		}
		else if (pStartFirstList == NULL && pStartSecondList != NULL) {
			return pStartSecondList;
		}
		else if (pStartFirstList != NULL && pStartSecondList == NULL) {
			return pStartFirstList;
		}
		else {
			return NULL;
			break;
		}
	}//end of while

	return pMergedList;
}

//borrowed code
void printList(ListNode *pCurrent)
{
	if (pCurrent == NULL)
	{
		printf("(empty)\n\n");
	}
	else
	{

		while (pCurrent != NULL)
		{
			printf("%d --> ", pCurrent->data);
			pCurrent = pCurrent->pNext; // move to next element  
		}

		printf("NULL\n\n");
	}
}


