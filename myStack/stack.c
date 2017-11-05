#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "stack.h"

// Push a new value onto top of stack.
bool stackPush(Stack *s, int value) {
	struct Node *node = malloc(sizeof(struct Node));
	if (node == NULL)
		return false;

	node->value = value;
	node->next = *s;
	*s = node;
	return true;
}

// Pop value from top of stack.
bool stackPop(Stack *s, int *value) {
	if (stackEmpty(s))
		return false;

	*value = (*s)->value;
	/* patch out first element */
	struct Node *node = *s;
	*s = node->next;
	free(node);
	return true;
}

// Peek top node on stack.
bool peekStack(const Stack *s, int *value) {
	if (stackEmpty(s))
		return false;

	*value = (*s)->value;
	return true;
}

// Check if stack is empty.
int stackEmpty(const Stack *s) {
	return (*s == 0);
}

// Print contents of stack.
void stackPrint(const Stack *s) {
	for (struct Node *node = *s; node != 0; node = node->next)
		printf("%d ", node->value);
	putchar('\n');
}

// Return stack count.
size_t sizeStack(Stack *s) {
	int count = 0;

	// Walk the stack, counting nodes.
	for (struct Node *node = *s; node != 0; node = node->next)
		count++;

	return count;
}

// Release all memory allocated by stak.
bool destroyStack(Stack *s) {
	while (!stackEmpty(s)) {
		int i;
		stackPop(s, &i);
	}
	return true;
}

