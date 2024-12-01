#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Stack structure
struct Stack {
	char items[MAX_SIZE];
	int top;
};

// Stack operations
void initialize(struct Stack *s) {
	s->top = -1;
}

int isFull(struct Stack *s) {
	return s->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *s) {
	return s->top == -1;
}

void push(struct Stack *s, char value) {
	if (!isFull(s)) {
		s->items[++(s->top)] = value;
	}
}

char pop(struct Stack *s) {
	if (!isEmpty(s)) {
		return s->items[(s->top)--];
	}
	return '\0';
}

// Function to check if opening and closing brackets match
int isMatchingPair(char character1, char character2) {
	return (character1 == '(' && character2 == ')') ||
	       (character1 == '{' && character2 == '}') ||
	       (character1 == '[' && character2 == ']');
}

// Function to check if expression has balanced parentheses
int checkBalancedParentheses(char *expr) {
	struct Stack stack;
	initialize(&stack);

	for (int i = 0; expr[i]; i++) {
		if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
			push(&stack, expr[i]);
		}
		else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
			if (isEmpty(&stack)) {
				return 0; // Unbalanced
			}

			// Pop the top element and check if it matches
			if (!isMatchingPair(pop(&stack), expr[i])) {
				return 0; // Unbalanced
			}
		}
	}

	// Check if stack is empty at the end
	return isEmpty(&stack);
}

int main() {
	char expression[MAX_SIZE];

	printf("\nEnter an expression to check for balanced parentheses: ");
	scanf(" %[^\n]s", expression);

	if (checkBalancedParentheses(expression)) {
		printf("\nResult: Expression is Balanced\n");
	} else {
		printf("\nResult: Expression is Not Balanced\n");
	}


	return 0;
}