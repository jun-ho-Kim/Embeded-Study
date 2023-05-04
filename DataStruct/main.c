#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, n = 0, *ptr;
	
	int sale[2][4] = {{63, 84, 140, 130},
					{157, 209, 251, 312}};
					
	ptr = &sale[0][0];
	for(i=0; i<8;i++)
	{
		printf("\n address : %u sale %d = %d,", ptr, i,  *ptr);
		ptr++; 
	}
	
	return 0;
}
