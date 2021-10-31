#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// A piece of data can be a string, or an int
typedef union data {
	int i;
	char* s;
} data;

data stack[50];
short top;

// Pop from the stack
data pop(void) {
	top--;
	return stack[top+1];
}

// Push an int to the stack
void push_i(int n) {
	top++;
	stack[top].i = n;
}

// Push a string to the stack
void push_s(char* str) {
	top++;
	stack[top].s = str;
}

// Push a piece of data to the stack, it can be an int or a string
void push(data* d) {
	top++;
	stack[top] = *d;
}

void exe(char* term) {
	// TODO: Make this beter
	if (strcmp("+", term) == 0) {
		int a = pop().i;
		int b = pop().i;
		push_i(a+b);
	} else if (strcmp("-", term) == 0) {
		int a = pop().i;
		int b = pop().i;
		push_i(b-a);
	} else if (strcmp("*", term) == 0) {
		int a = pop().i;
		int b = pop().i;
		push_i(a*b);
	} else if (strcmp("/", term) == 0) {
		int a = pop().i;
		int b = pop().i;
		push_i(b/a);
	} else if (strcmp("print", term) == 0) {
		char* str = stack[top].s;
		printf("%s\n", str);
	} else if (strcmp("printn", term) == 0) {
		int n = stack[top].i;
		printf("%d\n", n);
	} else if (strcmp(".", term) == 0) {
		int a = pop().i;
		printf("%d\n", a);
	} else if (strcmp("..", term) == 0) {
		char* str = pop().s;
		printf("%s\n", str);
	} else if (strcmp("swp", term) == 0) {
		data a = pop();
		data b = pop();
		push(&a);
		push(&b);
	}
}

int main(void) {
	top = -1;
	
	char input[200];
	printf("> ");
	scanf("%[^\n]", input);

	int sl = strlen(input);

	for (int i = 0; i < sl; i++) {
		// Parse the input
		if (isdigit(input[i])) {
			char num[] = "";
			while (isdigit(input[i])) {
				sprintf(num, "%s%c", num, input[i]);
				i++;
			}
			push_i(atoi(num));
		} else if (input[i] == '"') {
			char str[] = "";
			unsigned short strl = 0;
			i++;
			while (input[i] != '"' && i < sl) {
				sprintf(str, "%s%c", str, input[i]);
				i++;
				strl++;
			}
			i++;
			// The string is allocated on the heap
			// TODO: Free this string
			char* astr = (char*)malloc(sizeof(char)*strl);
			strcpy(astr, str);
			push_s(astr);
		} else {
			char term[] = "";
			while (input[i] != ' ' && i < sl) {
				sprintf(term, "%s%c", term, input[i]);
				i++;
			}
			exe(term);
		}
	}

	// TODO: make a real REPL
	// TODO: add types
	return 0;
}
