/**************************************************************************
 File name:  	mainList.c
 Author:     	Computer Science, Pacific University
 Date:       	9.28.16
 Class:				CS300
 Assignment:	In Class Valgrind Lab
 Purpose:			Practice finding memory errors with Valgrind
 This code is seeded with ERRORS!

 TODO
 1. Let's look over how the linked list is made
 2. Run the program with the given data file. Correct?
 3. Run Valgrind. Errors?
 4. Fix Valgrind errors
 5. Fix logic errors
 6. Run Valgrind. Errors?
 7. Fix Valgrind errors (if there are any)
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_NAME 16
typedef struct StringNode *StringNodePtr;
typedef struct StringNode
{
	char *pStr;
	StringNodePtr psNext;
} StringNode;

/****************************************************************************
 Function: 	 		printSizes

 Description: 	This function prints to the screen the size of primitive types

 Parameters:		None

 Returned:			None
 ****************************************************************************/
int printSizes ()
{
	printf ("\nSizeof(int) : %d\n", sizeof(int));
	printf ("Sizeof(short) : %d\n", sizeof(short));
	printf ("Sizeof(long) : %d\n", sizeof(long));
	printf ("Sizeof(long long) : %d\n", sizeof(long long));
	printf ("Sizeof(char) : %d\n", sizeof(char));
	printf ("Sizeof(float) : %d\n", sizeof(float));
	printf ("Sizeof(double) : %d\n", sizeof(double));
	printf ("Sizeof(int*) : %d\n", sizeof(int*));
	printf ("Sizeof(char*) : %d\n", sizeof(char*));
}

void printList (StringNodePtr psHead)
{
	while (psHead->psNext != NULL)
	{
		printf ("\n%s", psHead->pStr);
		psHead = psHead->psNext;
	}
	printf ("\n\n");

}

int length (StringNodePtr psHead)
{
	int count = 0;
	while (psHead->psNext != NULL)
	{
		++count;
		psHead = psHead->psNext;
	}
	return count;
}

int main ()
{
	FILE *pFile;
	int number;
	int size;
	int i;
	char str[MAX_STR_NAME];

	StringNodePtr psHead = NULL; // the head of the linked list
	StringNodePtr psCurrent = NULL;

	puts ("Executing mainList");
	puts ("Start Valgrind Lab");

	printSizes ();

	pFile = fopen ("data/data.txt", "r");
	if (NULL == pFile)
	{
		puts ("Error Opening File");
		exit (EXIT_FAILURE);
	}

	// read a number of integers from the user.
	// the first integer is the number of integers to follow.
	fscanf (pFile, "%d", &size);

	// Read integers from the file and add each one to the end
	// of the linked list.
	psCurrent = psHead;

	for (i = 0; i <= size; i++)
	{
		fscanf (pFile, "%s", str);

		if (NULL == psCurrent)
		{
			psHead = (StringNodePtr) malloc (sizeof(struct StringNode));
			psCurrent = psHead;
		}
		else
		{
			psCurrent->psNext = (StringNodePtr) malloc (sizeof(struct StringNode));
			psCurrent = psCurrent->psNext;
		}

		psCurrent->psNext = NULL;
		psCurrent->pStr = str;
	}

	printf ("List Size = %d\n", length (psHead));
	printList (psHead);

	free (psHead);

	fclose (pFile);

	puts ("End Valgrind Lab");

	return EXIT_SUCCESS;
}
