#include <iostream>

int main()
{
	if (0)
	{
		bool con = false;
		//Quiz = 2의 배수일 경우, "2의 배수 입니다." 아니면 "2의 배수가 아닙니다."
		for (int i = 0; i <= 10; i++)
		{
			int input = i;

			con = input % 2;

			if (con == 0)
			{
				std::cout << i << " 2의 배수입니다. " << std::endl;
			}
			else
			{
				std::cout << i << " 2의 배수가 아닙니다. " << std::endl;
			}
		}
		/*
		int input = 8;
		con = input % 2;
		if (con == 0)
		{
			std::cout << "2의 배수입니다." << std::endl;
		}
		else
		{
			std::cout << "2의 배수가 아닙니다." << std::endl;
		}
		*/
	}

	//if (/*true vs false from bool, <, >, <=, >=, ==, !=, */)
	int score = 80;

	if(score >= 100)
	{
		std::cout << "A+학점 입니다." << std::endl;
	}
	else if(score>=90 && score<100)
	{
		std::cout << "A학점입니다." << std::endl;
	}
	else if (score >= 80 && score < 90)
	{
		std::cout << "B+학점입니다." << std::endl;
	}
	else if (score >= 70 && score < 80)
	{
		std::cout << "B학점입니다." << std::endl;
	}
	else if (score >= 60 && score < 0)
	{
		std::cout << "C+학점입니다." << std::endl;
	} 
	else
	{
		std::cout << "C학점입니다." << std::endl;
	}

	int value = 10;
	switch (value)
	{
	case 10: 
	{
		std::cout << "A+학점 입니다." << std::endl;
		break;
	}
	case 9:
	{
		std::cout << "B학점 입니다." << std::endl;
		break;
	}
	case 8:
	{
		std::cout << "C학점 입니다." << std::endl;
		break;
	}
	case 7:
	{
		std::cout << "D학점 입니다." << std::endl;
		break;
	}
	default: 
		break;
	}
	
	//Quize
	// Dan*Step = GuGuResult
	// Dan : 5
	// Step: 1~9;
	// 구구단의 결과를 수식과 결과를 출력하세요
	for (size_t step = 1; step <= 9; step++)
	{
		for (size_t dan = 2; dan <= 9; dan++)
			if (dan % 2 == 0)
				std::cout << dan << "x" << step << "=" << dan * step << "\t";
		std::cout << std::endl;
	}

	return 1;
}

