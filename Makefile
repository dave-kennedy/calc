calc : main.c calc.c
	cc -ansi -g -Wall -Wpedantic -I. -o calc main.c calc.c
