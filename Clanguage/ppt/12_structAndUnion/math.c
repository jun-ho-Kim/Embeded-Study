#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct complex1 {float x; float y;};

struct point {int x, y;} pt1={1,2};
struct rect {struct point pt1, pt2;};
struct complex {float x,y;};
struct address {
	char name[20];
	char addr[60];
	char tel[14];
	int age;
} addr_book={"kinag w.C", "seoul gangseo apt", "778-8888", 21,};

int main(int argc, char *argv[]) 
{
	struct complex1 z1 = {2.0, 1.03};
	struct complex1 z2 = {3.0, 4.0};
	struct complex1 z3;

	printf("z1 = (%f %f)\n z2=(%f, %f)\n \n", z1.x, z1.y, z2.x, z2.y);
	//printf("z1 = (%f %f)\n z2=(%f, %f)\n \n", z1.x, z1.y, z2.x, z2.y);
	
	z3.x = z1.x + z2.x;
	z3.y = z1.y + z2.y;
	printf("z1+z2=(%f %f)\n", z3.x, z3.y);
	
	z3.x = z1.x - z2.x;
	z3.y = z1.y - z2.y;
	printf("z1-z2=(%f %f)\n", z3.x, z3.y);
	
	//sum=sqrt(z2.x*z2.x+pow(z2.y,2));
	//angle= atan(z2.y/z2.x)*180/PI;
	
	//prntf("크기 = %f, 각도 %f", sum, angle);
	
	struct complex zz1 = {3.,4.}, zz2={100.,};
	static struct rect r={{3.,4.}, {1.,2.}};
	puts("Input your name");
	puts(addr_book.addr);
	puts(addr_book.name);
	puts(addr_book.tel);
	
	puts("Change name");
	gets(addr_book.name);
	puts(addr_book.name);
}
