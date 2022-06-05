/****************************************************************************
 File name:  	mainArrays.c
 Author:     	chadd
 Date:       	6/11/2019
 Class:				CS300
 Assignment:	In Class Valgrind Lab
 Purpose:			Practice finding memory errors with Valgrind
 This code is seeded with ERRORS!
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

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

/****************************************************************************
 Function: 	 		sum

 Description: 	calculate the sum of all the integers in the array

 Parameters:		pArray - the array
 	 	 	 	 	 	 	  size - the size of the array

 Returned:	 		the sum, an int
 ****************************************************************************/
int sum (int *pArray, int size)
{
	// pass a pointer!

	int theSum = 0;
	int i;
	for (i = 0; i <= size; i++)
	{
		theSum += pArray[i];
	}

	return theSum;
}

/****************************************************************************
 Function: 	 		expand

 Description: 	reallocate a larger array, and copy the data from the smaller
 	 	 	 	 	 	 	 	array into the larger array.  the empty spots in the larger
 	 	 	 	 	 	 	  array are filled with -42.  The original, smaller array must
 	 	 	 	 	 	 	 	be deallocated in this function.

 Parameters:		pArray - the handle to the array
 	 	 	 	 	 	 	  size - the size of the array
 	 	 	 	 	 	 	  newSize - the size of the new array

 Returned:	 		none
 ****************************************************************************/
int* expand (int *pArray, int size, int newSize)
{
	// pass a handle

	int *pNewArray = (int*) malloc (newSize * sizeof(int));
	int i;

	for (i = 0; i < newSize; i++)
	{
		pNewArray[i] = (pArray)[i];
	}

	for (i = size; i < size; i++)
	{
		pNewArray[i] = -42;
	}
	free (pArray);
	pArray = pNewArray;
	return pArray;
}

/****************************************************************************
 Function: 	 		main

 Description: 	main driver to exercise the above functions.

 Parameters:		none

 Returned:	 		none
 ****************************************************************************/
int main ()
{
	int *pArray;
	int size = 0;
	int i = 0;
	const int NEW_SIZE = 4096;

	FILE *pFile;

	printSizes ();

	pFile = fopen ("data/numbers.txt", "r");

	// read a number of integers from the user.
	// the first integer is the number of integers to follow.
	// malloc an array to contain the integers

	fscanf (pFile, "%d", size);

	pArray = (int*) malloc (sizeof(int) * size);

	for (i = 0; i < size; i++)
	{
		fscanf (pFile, "%d", &(pArray[i]));
	}

	fclose (pFile);

	// print all the integers to the screen, using array notation
	// all on one line, separated by a space
	for (i = 0; i < size; i++)
	{
		printf (" %d", (pArray[i++]));
	}
	printf ("\n");

	// print all the integers to the screen, using pointer notation
	// all on one line, separated by a space
	for (i = 0; i < size; i++)
	{
		printf (" %d", *(pArray + i));
	}
	printf ("\n");

	pArray = expand (pArray, size, NEW_SIZE);

	// print all the integers to the screen, using array notation
	// all on one line, separated by a space
	for (i = NEW_SIZE - 10; i < NEW_SIZE; i++)
	{
		printf (" %d", *(pArray + i));
	}

	// deallocate pArray
	free (*pArray);

	return EXIT_SUCCESS;
}
