#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//������ �����Ѵٴ� ���� ������ �̸��� ���ؼ� �޸𸮰����� ����ϴ� ���̴�.
		//���α׷��� ȿ�������� ¥�� ���ؼ��� �޸𸮰� ��� ��ġ�� �ְ� �󸶳� ���� �޸𸮸� ����ؾ��ϴ��� �˾ƾ� �Ѵ�. 
		// ũ�Ⱑ ū ���α׷��� ���� ���� ���� �����͸� ����ϸ� ���� ���� �����͸� �����ؼ� ���� ������ ����ϴ� ���� �����̴�.
			// �̷��� �ϸ� �����͸� �����ϴµ� �ð��� �ɸ��� �޸𸮵� ����ȴ�.
			// �����Ͱ� ��� �ִ��� �˰� ���α׷��� �ۼ��ϸ� ���α׷��� ȿ�������� �۵��� ���̴�.
 
	//�����ʹ� �޸� �ּҸ� �����Ͽ� ����Ű�� /*������*/���� ��Ȱ�� �Ѵ�.
	//�����͸� �������� ����  �Ʒ��� ���� ���� �� �տ� *�� �ٿ� ����Ѵ�.
	int a = 7; 
	int *a_ptr = &a;
	
	double b = 2;
	double *b_ptr = &b;
	
	printf("a variable address is %d\n", a_ptr); // 6487564
	printf("b variable address is %d\n", b_ptr); // 6487552
	
	//���� ���� ������ *
	printf("a pointer value is %d\n", *a_ptr); // a pointer value is 7
	printf("b pointer value is %.1lf\n", *b_ptr); // b pointer value is 2.0
	
	printf("a pointer is %d byte\n", sizeof(*a_ptr)); // a pointer is 4 byte
	printf("b pointer is %d byte\n", sizeof(*b_ptr)); // b pointer is 8 byte
	
	double c = 4;
	int *c_ptr = &c;
	printf("c pointer value is %f\n", *c_ptr); // c pointer value is 0.000000
	// ���� ������ ���� Ÿ�� ũ�⺸�� ū ������ �Ҵ����ָ� ���� 0���� ���´�. 
	
	int d = 9;
	double *d_ptr = &d;
	printf("d pointer value is %d\n", *d_ptr); // d pointer value is 9
	// �׷��ٸ� ������ ���� Ÿ�� ũ�⺸�� ���� ������ �Ҵ����ָ� ���� �� �������� ������ ������ �̿� �Ҵ��Ϸ��� ������ ũ�⸦ ��������.. 
	
	// ���⼭ ������ ������ ���� a�� �ּҸ� �����ϴµ� a �տ� &�� �ٿ� ����Ѵ�.
	// ������ ������ ũ��� int�� �Ҵ������� 4byte double�� �Ҵ������� 8byte�� �Ҵ�ȴ�. 
	
	//����� �������� �ʱⰪ�� �������� �ʴ� ��쿡�� NULL ������ �ʱ�ȭ ���ִ� ���� �⺻�̶���Ѵ�.
	// �� ������ ������ ���� NULl�� ��쿡 ����ó���� �����ϱ� �����̴�.
	 
	double *e_ptr = NULL; // ���� �ʱ�ȭ�� ������ ������ ������ ���� ����. 
	
	printf("e_ptr is %d", e_ptr); 
	
	if(e_ptr == NULL)
	{
		printf("e_ptr is NULL\n");
	}
	
	// const	
	// const ���� �� �������� ���� �ٲ� �� ����.
	// ������ ���ʿ� ���� const�� ���� ������ �� ����.
	// ������ �����ʿ� ���� const�� �ٸ� ������ ������ �Ҵ��� �ȵȴ�.
	const int arr[10] = { 456, 459, 465, 472, 474 };
	const int* f_cstprt = &arr;
	printf("f_cstprt is %d\n", f_cstprt);
	
	//f_cstprt = &a;

	
	printf("f_cstprt is %d, value is %d\n", f_cstprt, *f_cstprt);
	printf("f_cstprt is %d, value is %d\n", f_cstprt, *++f_cstprt);
	
	int* const g_cstprt = &arr;
	//*g_cstprt = 11; // Error

	
	// *g_cstprt++ //Error
	printf("g_cstprt is %d, value is %d\n", g_cstprt, *g_cstprt);
	
	printf("g_cstprt is %d, value is %d\n", g_cstprt, *g_cstprt);
	 
	return 0;
}
