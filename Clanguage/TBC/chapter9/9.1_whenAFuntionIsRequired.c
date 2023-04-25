//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 40
#define NAME "Junho Kim"
#define ADDRESS "Seoul, Korea"

void print_multiple_chars(char c, int n_starts, bool end1);
void print_centered_str(char str[]); // prototype
//void print_centered_str(char);  // 프로토 타입에는 변수 명이 없어도 됨, 타입만 있어도 가능

int main()
{
	print_multiple_chars('*', WIDTH, true); // argument // actual argument / parameter

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");

	print_multiple_chars('*', WIDTH, true);
	

	return 0;
}

void print_multiple_chars(char c, int n_starts, bool end1) //parameter // formal argument / parameter
{
	for (int i = 0; i < n_starts; ++i) 
		printf("%c", c);
	if(end1)
		printf("\n");
}

void print_centered_str(char str[])
{
	int n_blanks = 0;
	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks, false);
	printf("%s\n", str);
}