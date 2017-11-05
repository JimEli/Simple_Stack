#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Node {
	struct Node *next;
	int value;
};

typedef struct Node *Stack;

#define STACK_EMPTY (0)

// Function definitions.
bool stackPush(Stack *s, int value);
bool stackPop(Stack *s, int *value);
bool peekStack(const Stack *s, int *value);
int stackEmpty(const Stack *s);
size_t sizeStack(Stack *s);
void stackPrint(const Stack *s);
bool destroyStack(Stack *s);

#endif
