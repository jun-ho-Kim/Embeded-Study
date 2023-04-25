#include <iostream>
#include <vector>

int main()
{
	//절차적 프로그래밍
	////일련의 순차적인 행위를 하는 프로그래밍을 의미
	//객체지향 프로그래밍
	////모듈화된 추상화 개념의 프로그래밍을 의미

	//C, C++
	//절차...모듈화된 확장 가능한 프로그래밍 언어
	//C...low level
	//C++는 C의 low level 기반으로 클래스의 기능을 확대하여 
	//	객체로써 모듈화된 프로그램을 다형성 있도록 
	//	지원하는 언어입니다.

	//Basic
	//기본 데이터 형...
	int a = 0; //4bytes 정보를 담을 수 있는 그릇
	//선언... 자료형[타입] 변수이름 = 데이터초기화
	//예약어 include # return ...변수 이름을 사용하지 않도록 바람

	//자료형
	[signed] int, short, char, double, float; //음수, 양수
	[unsigned] int; // 양수 only
	int arr[10]; // 배열...논리적 공간...물리적 공간과 차이 size int*10
	struct _stStudent 
	{
	//stuct는 public으로만 사용 가능
	(public:)
		void function1() {};
		void function2() {};
	};
	class _stStudent
	{
	public: // 접근지정자...누구나
		_CStudent() {};
		~_CStudent() {};
	private: // VIP...나만
	protected://너만
	}; 
	//C++
	//확장타입: vector<int>, map<key, value>

	//Python
	//기본타입 : int double string... 정수, 실수, 문자
	//확장타입 : tuple, list, dict...

	//pointer...
	//데이터에 접근할 수 있는 방법
	//주소와 열쇠가 있으면 데이터에 접근을 할 수 있다.
	//address...주소값...메모리의 주소값을 의미한다.
	//컴퓨터...cpu(계산)..memory(임시로 데이터를 로딩/저장)...hdd
	//pointer++, --pointer
	//증감 되는 크기는 pointer의 선언되는 자료형에 의존됨
	int* pArr = nullptr; //4byte씩 증분
	pointer start address:: 0x000 -> 0x004 -> 0x008;
	pointer start address + data space[int - 4bytes];

	//동적인 환경
	int* pArr = new int[10]; //lvalue와 rvalue의 타입이 동일
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
	//malloc 인자는
	pAddress->특정한 메모리 공간을 가리키다.;
	data space는 void 타입형으로는 알 수 없다.즉 return을 알 수 없다.
		return 형태를 모르기 때문에 형태를 재 해석할 수 있다.;

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

	//수학....
	---> x..크기...y;

	//debugging
	watch...조사식창
	console 출력 ... std::cout << "hello" << std::endl;
	int input;
	console 입력 ... std::cint >> input;

	//타입변환
	//casting
	//강제변환...c-style
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
	// 변수1=함수()
	// 변수2=변수1
	// 변수2=함수()...함수1(변수1)
	//dynamic_cast
	
	//input...function...output

	//조건문...반복문
	if/switch...
		//1회만 수행
		//조건식....true or false
	for..while...do-while // 최악의 경우 무한루프에 빠지게 되는데 시스템을 죽여야된다.
		//break를 통해 빠져나갈 지점을 추가해주는 것이 좋다.
		//로직이 반복 수해잉 되면서 목적 결과를 도출
		//
	return 1;
}