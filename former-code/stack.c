// A piece of data can be a string, or an int
typedef union data {
	int i;
	char* s;
} data;

data stack[50];
data rstack;
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
