#include <iostream>
#include <vector>

int main()
{
	//������ ���α׷���
	////�Ϸ��� �������� ������ �ϴ� ���α׷����� �ǹ�
	//��ü���� ���α׷���
	////���ȭ�� �߻�ȭ ������ ���α׷����� �ǹ�

	//C, C++
	//����...���ȭ�� Ȯ�� ������ ���α׷��� ���
	//C...low level
	//C++�� C�� low level ������� Ŭ������ ����� Ȯ���Ͽ� 
	//	��ü�ν� ���ȭ�� ���α׷��� ������ �ֵ��� 
	//	�����ϴ� ����Դϴ�.

	//Basic
	//�⺻ ������ ��...
	int a = 0; //4bytes ������ ���� �� �ִ� �׸�
	//����... �ڷ���[Ÿ��] �����̸� = �������ʱ�ȭ
	//����� include # return ...���� �̸��� ������� �ʵ��� �ٶ�

	//�ڷ���
	[signed] int, short, char, double, float; //����, ���
	[unsigned] int; // ��� only
	int arr[10]; // �迭...���� ����...������ ������ ���� size int*10
	struct _stStudent 
	{
	//stuct�� public���θ� ��� ����
	(public:)
		void function1() {};
		void function2() {};
	};
	class _stStudent
	{
	public: // ����������...������
		_CStudent() {};
		~_CStudent() {};
	private: // VIP...����
	protected://�ʸ�
	}; 
	//C++
	//Ȯ��Ÿ��: vector<int>, map<key, value>

	//Python
	//�⺻Ÿ�� : int double string... ����, �Ǽ�, ����
	//Ȯ��Ÿ�� : tuple, list, dict...

	//pointer...
	//�����Ϳ� ������ �� �ִ� ���
	//�ּҿ� ���谡 ������ �����Ϳ� ������ �� �� �ִ�.
	//address...�ּҰ�...�޸��� �ּҰ��� �ǹ��Ѵ�.
	//��ǻ��...cpu(���)..memory(�ӽ÷� �����͸� �ε�/����)...hdd
	//pointer++, --pointer
	//���� �Ǵ� ũ��� pointer�� ����Ǵ� �ڷ����� ������
	int* pArr = nullptr; //4byte�� ����
	pointer start address:: 0x000 -> 0x004 -> 0x008;
	pointer start address + data space[int - 4bytes];

	//������ ȯ��
	int* pArr = new int[10]; //lvalue�� rvalue�� Ÿ���� ����
	if (pArr)
	{
		delete[] pArr;
	}
	//C-style
	void* __cdecl malloc(
		_In_ _CRT_GUARDOVERFLOW size_t _Size
		//int runtime size_t
	);
	void* malloc(size_t _Size); //memory space - negative->positive
	//malloc ���ڴ�
	pAddress->Ư���� �޸� ������ ����Ű��.;
	data space�� void Ÿ�������δ� �� �� ����.�� return�� �� �� ����.
		return ���¸� �𸣱� ������ ���¸� �� �ؼ��� �� �ִ�.;

	int* p = (int*)malloc(10*sizeof(int));
	free(p);
	malloc(10);

	//vector
	vector<int> vArr(10);
	vArr[0]
	vArr[1]
	vArr[2]
	vArr[3]
	vArr[4]

	//����....
	---> x..ũ��...y;

	//debugging
	watch...�����â
	console ��� ... std::cout << "hello" << std::endl;
	int input;
	console �Է� ... std::cint >> input;

	//Ÿ�Ժ�ȯ
	//casting
	//������ȯ...c-style
	int b = (int)(double a);
	int* b = (int*)(double* a);
	int b = static_cast<int>(double a);
	//static_cast
	//const_cast
	//const char* pMsg
	//char* pMMsg = const_cast<char*>(pMsg)
	//(int*)(void*) malloc
	// void* pMen = malloc()
	//reinterept_cast
	//int* pArr = reinterpret_cast<int*>(malloc())//temp object {void* pMem}
	// ����1=�Լ�()
	// ����2=����1
	// ����2=�Լ�()...�Լ�1(����1)
	//dynamic_cast
	
	//input...function...output

	//���ǹ�...�ݺ���
	if/switch...
		//1ȸ�� ����
		//���ǽ�....true or false
	for..while...do-while // �־��� ��� ���ѷ����� ������ �Ǵµ� �ý����� �׿��ߵȴ�.
		//break�� ���� �������� ������ �߰����ִ� ���� ����.
		//������ �ݺ� ������ �Ǹ鼭 ���� ����� ����
		//
	return 1;
}