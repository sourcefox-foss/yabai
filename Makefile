GCC = clang
FLAGS = -g -I.

run: all example_source_file
	yabai example_source_file

all: main.c
	$(GCC) $(FLAGS) main.c -o yabai
