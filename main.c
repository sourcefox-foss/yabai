#include <stdio.h>
#include "brainfuck.h"

FILE* fp;
char tape[30000] = {0};
char* head = tape;
char com[100000000] = {0};

void
inc()
{
	++*head;
}

void
dec()
{
	--*head;
}

void
l()
{
	head--;
}

void
r()
{
	head++;
}

char*
jf(char* start) 
{
	if (*head == 0) {
		return match_right(start);
	} else {
		return start;
	}
}

char*
jb(char* start)
{
	if (*head != 0) {
		return match_left(start);
	} else {
		return start;
	}
}

void
p()
{
	putchar(*head);
}

char*
match_right(char* start)
{
	int head_index = 1;

	start++;
	while (head_index != 0) {
		if (*start == '[') head_index++;
		else if (*start == ']') head_index--;
		start++;
	}
	return --start;
}

char*
match_left(char* start)
{
	int head_index = 1;

	start--;
	while (head_index != 0) {
		if (*start == ']') head_index++;
		else if (*start == '[') head_index--;
		start--;
	}
	return ++start;
}

void
read_file(char* file)
{
	char temp;
	char* w = com;
	fopen_s(&fp, file, "r");
	do {
		temp = fgetc(fp);
		switch (temp) {
		case '+':
		case '-':
		case '>':
		case '<':
		case '[':
		case ']':
		case '.':
			*w = temp;
			w++;
			break;
		}	
	} while (temp != EOF);
}

void
run(char* c)
{
	char* start = c;
	while (*c) {
		switch (*c) {
		case '+':
			inc();
			break;
		case '-':
			dec();
			break;
		case '>':
			r();
			break;
		case '<':
			l();
			break;
		case '[':
			c = jf(c);
			break;
		case ']':
			c = jb(c);
			break;
		case '.':
			p();
			break;

		}
		c++;
	}
}

int
main(int argc, char* argv[])
{
	if (argc != 2) return 1;
	read_file(argv[1]);
	run(com);

	return 0;
}
