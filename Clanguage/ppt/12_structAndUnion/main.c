#include <stdio.h>
#include <stdlib.h>
#define MAX 50

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct address 
{
	char name[7];
	char addr[60];
	char tel[9];
	int birth;
} addr_book[MAX];

struct address function(struct address addr_book)
{
	return addr_book; // ����ü�� ��°�� ���� 
}

int main(int argc, char *argv[]) {
	int i =1, j=2;


	printf("%p\n", addr_book); 
	printf("%p\n", addr_book[0]); 
	
	addr_book[i] = addr_book[i]; // ����ü ���� 
	//addr_book[i] = function(addr_book[j]);// ����ü ��°�� �ǳ��ش�.
	
	addr_book[2].addr = "jumhozip";
	addr_book[2].birth = 1120;

	int x = 5;
	return 0;
}
