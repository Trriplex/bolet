#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "stack.c"
#include "execute.c"

int main(void) {
	// TODO: add types
	top = -1;

	char input[100];
	printf("> ");
	
	while (fgets(input, 100, stdin)) {
		int sl = strlen(input);
		input[sl-1] = '\0';
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
		printf("> ");
	}
	return 0;
}
