GCC = clang
FLAGS = -g -I.

run: all main.bf
	yabai main.bf

all: main.c
	$(GCC) $(FLAGS) main.c -o yabai
