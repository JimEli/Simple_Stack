/*************************************************************************
* Title: myStack
* File: main.c
* Author: James Eli
* Date: 11/5/2017
*
* A simple stack implemetation.
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*************************************************************************
* Change Log:
*   11/05/2017: Initial release. JME
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "utils.h"

// C/C++ Preprocessor Definitions: _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996) 

// Program starts here.
int main(void) {
	Stack s = STACK_EMPTY; // Our demonstration stack.

	// Main command dispatch loop.
	while (1) {
		int i;  // Temporary holds stack values.

		switch (fetchCommand("12345qQ")) {

		case '1': // Push item on stack.
			if (getInteger("\nEnter an integer: ", MIN_INPUT, MAX_INPUT, &i)) {
				stackPush(&s, i);
				fputs("Stack contents: ", stdout);
				stackPrint(&s);
			}
			break;

		case '2': // Pop item from stack.
			if (stackPop(&s, &i))
				fprintf(stdout, "\nPopped: %d from stack.", i);
			if (stackEmpty(&s))
				fputs("\nStack is empty.\n", stdout);
			else {
				fputs("\nStack contents: ", stdout);
				stackPrint(&s);
			}
			break;

		case '3': // Display top of stack.
			if (peekStack(&s, &i))
				fprintf(stdout, "\nTop of stack: %d\n", i);
			else
				fputs("\nStack is empty.\n", stdout);
			break;

		case '4': // Display size of stack.
			if (!(i = (int)sizeStack(&s)))
				fputs("\nStack is empty.\n", stdout);
			else
				printf("\nSize of stack: %d\n", i);
			break;

		case '5':
			/* no break */
		case 'q':
			/* no break */
		case 'Q': // Empty the stack's allocated memory and quit.
			if (!destroyStack(&s))
				exit(EXIT_FAILURE);
			exit(EXIT_SUCCESS);
			break;

		case '\0':
			/* no break */
		default:
			// Unsupported command.
			fputs("\nUnsupported command entered.\n", stdout);
			break;
		}
	}
}

