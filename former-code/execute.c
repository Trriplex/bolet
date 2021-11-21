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
	} else if (strcmp("%", term) == 0) {
		int a = pop().i;
		int b = pop().i;
		push_i(b%a);
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
	} else if (strcmp("dup", term) == 0) {
		push(&stack[top]);
	} else if (strcmp("drp", term) == 0) {
		pop();
	} else if (strcmp("nip", term) == 0) {
		data a = pop();
		pop();
		push(&a);
	} else if (strcmp("over", term) == 0) {
		data a = pop();
		data b = pop();
		push(&b);
		push(&a);
		push(&b);
	} else if (strcmp(">r", term) == 0) {
		data a = pop();
		rstack = a;
	} else if (strcmp("r>", term) == 0) {
		push(&rstack);
	}
}
