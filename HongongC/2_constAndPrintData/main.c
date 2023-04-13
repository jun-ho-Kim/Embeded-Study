#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("2-3------------------------------------------\n");
	printf("Goot\bd\tchance\n");
	printf("Cow\r\a\n");

	printf("2-4------------------------------------------\n");
	printf("%d\n", 10);
	printf("%lf\n", 3.4);
	printf("%.1lf\n", 3.45);
	printf("%.10lf\n", 3.4123456789123456789);
	
	printf("%d과 %d의 합은 %d입니다.\n", 10, 20, 10+20);
	printf("%.1f-%.1f = %.1f\n", 3.4, 1.2, 3.4 -1.2);
	
	printf("2-5------------------------------------------\n");
	printf("%d\n", 12);
	printf("%d\n", 014);
	printf("%d\n", 0xc);
	
	printf("2-6------------------------------------------\n");
	printf("%.1lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);
	printf("%le\n", 0.0000314);
	printf("%.1le\n", 0.0000317);
	
	printf("2-7------------------------------------------\n");
	printf("%c\n", 'A'); // A
	printf("%c\n", "A"); //  // printf("%s\n", "A");
	printf("%c\n", 'A'); // A
	printf("%d\n", "A"); // 4210946
	
	printf("%c은 %s입니다.\n", '1', "fisrt"); // 1은 fisrt입니다.
	
	return 0;
}
