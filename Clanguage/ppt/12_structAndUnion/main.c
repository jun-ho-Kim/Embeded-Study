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
	return addr_book; // 구조체로 통째로 리턴 
}

struct point1
{
	int x, y;
};

struct point2
{
	int x, y;
};

struct complex 
{
	double x, y;
} z, *pz;

struct point1 a;

int main(int argc, char *argv[]) {
	int i =1, j=2;


	printf("%p\n", addr_book); 
	printf("%p\n", addr_book[0]); 
	
	addr_book[i] = addr_book[i]; // 구조체 대입 
	//addr_book[i] = function(addr_book[j]);// 구조체 통째로 건네준다.
	
	*addr_book[2].addr = "jumhozip";
	addr_book[2].birth = 1120;

	int x = 5;
	
	struct point1 b;
	struct point2 c;
	
	a.x=10;
	a.y=20;
	b.x=30;
	c.x=40;
	
	
	printf("a.x=%d\n", a.x);
	printf("b.x=%d\n", b.x);
	printf("c.x=%d\n", c.x);
	
	pz=&z;
	z.x=3.0;
	(*pz).x=3.0;
	(*pz).y=4.0;
	printf("size = %d byte!!\n", sizeof(a.x));
	printf("z.x=%f\n", z.x);
	printf("z.y=%f\n", z.y);
	printf("z.x=%f\n", (*pz).x);
	printf("z.y=%f\n", (*pz).y);
	printf("a.x=%f\n", a.x);
	printf("a.y=%f\n", a.y);
	
	printf("z.x=%f\n", (*pz).y);
	
	return 0;
}
