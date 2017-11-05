// Utility functions header file.

#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Minimum and maximum allowable input range.
#define MIN_INPUT -100
#define MAX_INPUT 100
// Maximum input attempts before aborting.
#define MAX_INPUT_ATTEMPTS 3
// Text displayed as menu prompt.
#define MENU_TEXT   "\nProgram Menu:\n"              \
	"1 - Push an insert onto the stack.\n"           \
	"2 - Pop an integer from the stack.\n"           \
	"3 - Display top item on the stack.\n"           \
	"4 - Display the count of items on the stack.\n" \
	"5 - Quit.\n"                                    \
	"Enter 1 - 5: "

// Get integer.
bool getInteger(const char *prompt, const int min, const int max, int *value);
// Command entry handled here.
char fetchCommand(const char *commands);

#endif /* _UTILS_H_ */
