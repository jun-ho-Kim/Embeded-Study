#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[]) {
	char cc;
	//	cc = getch();
	//	putch(cc);
	
	//scanf_s는 첫 번째 인자에 입력크기를 받는다. 
	
	scanf("%c", &cc);
	printf("%c", cc);
	
	
	
	return 0;
}
