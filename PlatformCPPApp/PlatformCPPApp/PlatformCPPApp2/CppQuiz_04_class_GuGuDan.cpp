//아래 명세서에 알맞게 class를 설계해보세요.
//class 명세서
//class Name : GuGuDan
//GuGuDan 특성
// int dan, step 멤버 데이터
// int array[81] GuGuDan 결과
//GuGuDan 행위
//setDanStep(int& dan, int& step)
//doGuGuDan(int& danStart, int& danFinish, int& stepStart, int&stepFinish)
// -> row, col = (step, dan) -> array[index]=result 값을 저장
//::출력
// showGuGU()
// -> array[index] 값을 출력
// ex)		2  3  4  5  6  7  8  9
//---------------------------------
//		1	2  3  4  5			 9	
//		2	4  6  8  10			 18
//		3	
//		4
//		9   18 27 36 45			 81
//---------------------------------

#include <iostream>
//using namespace std;

class GuGuDan
{
public:
	GuGuDan() 
		: _dan(0)
		, _step(0)
		, _danStart(0)
		, _danFinish(0)
		, _stepStart(0)
		, _stepFinish(0)
	{
		std::cout << "GuGuDan::Ctor" << std::endl;
	}
	~GuGuDan() 
	{
		std::cout << "GuGuDan::Dtor" << std::endl;
	}

	void setDanStep(int& dan, int& step)
	{
		_dan = dan;
		_step = step;
	}

	//void setDanStep(int* dan, int* step) // pointer
	//void setDanStep(int& dan, int& step) // reference // rename, 외부에서 참소를 할 때는 int a = 0;//instance->int&
	//void setDanStep(int dan, int step) // variable // copy
	//알고리즘
	void doGuGuDan(int& danStart, int& danFinish, int& stepStart, int& stepFinish)
	{
		_danStart = danStart;
		_danFinish = danFinish;
		_stepStart = stepStart;
		_stepFinish = stepFinish;
		//danStart = danStart;
		//danFinish = danFinish;
		//stepStart = stepStart;
		//stepFinish = stepFinish;
		for (size_t step = stepStart; step < stepFinish; step++)
		{
			for (size_t dan = stepStart; dan < danFinish; dan++)
			{
				int result = dan * step;
				int index = step * 9 + dan;
				//row * value + column
				_data[index] = result;
			}
		}
	}

	void showGuGu()
	{
		std::cout << "		2\t3\t4\t5\t" << std::endl;
		for (size_t step = _stepStart; step < _stepFinish; step++)
		{
			for (size_t dan = _stepStart; dan < _danFinish; dan++)
			{
				int result = dan * step;
				int index = step * 9 + dan;
				//row * value + column
				_data[index] = result;
			}
		}
	}
protected:
	int* GetData() { return _data; }
private:
	static const int DATASIZE = 81;
	int _dan, _step;//맴버 데이터
	int _data[DATASIZE] = {0,};//GuGuDan 결과
	int _danStart, _danFinish;
	int _stepStart, _stepFinish;
	int* GetData() { return _data; }
	int GetStep() { return _step; }
	//int GetDan()
};

class GuGuDanChild
{
public:
	GuGuDanChild();
	~GuGuDanChild();
	double getValue()
	{
		std::cout << "dan = " << "step = " << _step << std::endl;
	}
private:

};

GuGuDanChild::GuGuDanChild()
{
}

GuGuDanChild::~GuGuDanChild()
{
}

/*
//내가 짠 코드
class GuGuDan
{
private:
	int* dan;
	int* step;
	int danStart;
	int danFinish;
	int stepStart;
	int stepFinish;
	int array[81];
public:
	GuGuDan()
	{
		dan = 0, step = 0;
		danStart = 0;
		danFinish = 0;
		stepStart = 0;
		stepFinish = 0;
		std::cout << "GuGuDan::ctor" << std::endl;
	}
	
	~GuGuDan()
	{
		std::cout << "GuGuDan::dtor" << std::endl;
	};

	void setDanStep(int& dan, int& step)
	{
		dan = dan, step = step;
		//danStart = danStart;
		//danFinish = danFinish;
		//stepStart = stepStart;
		//stepFinish = stepFinish;
	}

	void doGuGuDan(int& danStart, int& danFinish, int& stepStart, int& stepFinish)
	{
		int initStep = stepStart;
		for (int idx = 0; idx < 81; idx++)
		{
			if (danStart == danFinish + 1)
				break;
			array[idx] = danStart * stepStart;
			++stepStart;
			if (stepStart == stepFinish + 1)
			{
				danStart++;
				stepStart = initStep;
			}
		}
	}

	void showGuGU()
	{
		for (int i = 2; i <= 9; i++)
		{
			std::cout << "\t" << i;
		}
		std::cout << std::endl;
	
		showLine(70);

		int idx = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				std::cout << array[idx++] << "\t";
			}
			std::cout << std::endl;
		}

		showLine(70);
	}

private:
	void showLine(int num)
	{
		for (int i = 1; i <= num; i++)
		{
			std::cout << "-";
		}
		std::cout << std::endl;
	}

};
*/
int main()
{
	GuGuDan gg;
	gg.setDanStep(5, 3);
	gg.doGuGuDan(2, 5, 1, 9);
	/*
	//내가 짠 코드
	GuGuDan doGugudan;


	int dan = 1;
	int step = 9;

	int danStart = 1;
	int danFinish = 9;
	int stepStart = 1;
	int stepFinish = 9;
	doGugudan.setDanStep(dan, step);
	doGugudan.doGuGuDan(danStart, danFinish, stepStart, stepFinish);
	doGugudan.showGuGU();
	*/
	return 0;
}