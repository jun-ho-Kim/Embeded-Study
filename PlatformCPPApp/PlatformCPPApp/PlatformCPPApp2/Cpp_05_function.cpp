//function - �Լ�
//�Լ�...���, Ư���� �۾��� �����ϱ� ���� ��ɹ��� �׷�
//ǥ���Լ�, ����� ���� �Լ�
//ǥ���Լ� ... standard function - C/C++ ǥ�ض��̺귯��(std) ����
//				#include <string> ����� �����ϰ� ��ɰ� ȣ������ �˸� ���
//����� ���� �Լ�, (user defined function)
//	�����ڰ� �ʿ信 ���� ����� ����ϴ� �Լ�
//	����� ���Ǹ� �ؾ�, ���� �������, �ҽ����� (����/����) �θ� ���Ϸ� ������ �־�� ��
//�Լ� ����....usage
//	[��ȯ�� ������ Ÿ��] [�Լ��̸�] [(�Ű�����)]

//�Լ����� ���
//	[��ȯ�� ������ Ÿ��] [�Լ��̸�] [(�Ű�����)] 
// {
//		return [��ȯ�� ������ Ÿ��];
//	}
//�Լ� ȣ����
//	[�Լ��̸�](�Ű�����)

#include <iostream>
void showName(const char* pMsg = nullptr, int length = 10);
//�Լ� ���� ���� �������ִ� ��� �� �Ű������� default ���̴�.

void swap1(int* lhs = nullptr, int* rhs = nullptr);
void swap2(int* lhs = nullptr, int* rhs = nullptr);

void ShowGuGuDan(int DanStart, int DanFinish, int StepStart=1, int StepFinish=9)
{
	for (int i = StepStart; i <= StepFinish; i++)
	{
		for (int j = DanStart; j <= DanFinish; j++)
		{
			std::cout << j << " * " << i << "\t";
		}
		std::cout << std::endl;
	}

	/*
	2 * 1 = 2	3 * 1 = 3 ... 9 * 1 = 9;
	2 * 2 = 4	3 * 2 = 6 ... 9 * 2 = 18;
	...	...		...
	2 * 9 = 18	3 * 9 = 27 ... 9 * 9 = 81;
	*/

}

int main()
{
	if (0)
	{
		showName("KCCI");
		showName("Intel", 5);

		int a = 10;
		int b = 20;

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		swap1(&a, &b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		a = 10;
		b = 20;

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		swap2(&a, &b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
	}

	ShowGuGuDan(5, 8);

	return 1;
}

void swap1(int* lhs, int* rhs)
{
	int tmp = *lhs; //�ӽð�ü�� ���� -> ���� ������ -> ����
	*lhs = *rhs;	//���踦 ������ �����͸� ����(*lhs = *rhs) ? true
	*rhs = tmp;		//�ӽð�ü�� ������ �ִ� ���渦 ����(*rhs == tmp) ? true
}

void swap2(int* lhs, int* rhs)
{
	int* tmp = lhs; //�ӽð�ü�� ���� -> ���� ������ -> ����
	lhs = rhs;	//���踦 ������ �����͸� ����(*lhs = *rhs) ? true
	rhs = tmp;		//�ӽð�ü�� ������ �ִ� ���渦 ����(*rhs == tmp) ? true
}


void showName(const char* pMsg, int length)
{
	std::cout << pMsg << "_______" << length << std::endl;

	return;
}
