#include <iostream>

int main()
{
	if (0)
	{
		bool con = false;
		//Quiz = 2�� ����� ���, "2�� ��� �Դϴ�." �ƴϸ� "2�� ����� �ƴմϴ�."
		for (int i = 0; i <= 10; i++)
		{
			int input = i;

			con = input % 2;

			if (con == 0)
			{
				std::cout << i << " 2�� ����Դϴ�. " << std::endl;
			}
			else
			{
				std::cout << i << " 2�� ����� �ƴմϴ�. " << std::endl;
			}
		}
		/*
		int input = 8;
		con = input % 2;
		if (con == 0)
		{
			std::cout << "2�� ����Դϴ�." << std::endl;
		}
		else
		{
			std::cout << "2�� ����� �ƴմϴ�." << std::endl;
		}
		*/
	}

	//if (/*true vs false from bool, <, >, <=, >=, ==, !=, */)
	int score = 80;

	if(score >= 100)
	{
		std::cout << "A+���� �Դϴ�." << std::endl;
	}
	else if(score>=90 && score<100)
	{
		std::cout << "A�����Դϴ�." << std::endl;
	}
	else if (score >= 80 && score < 90)
	{
		std::cout << "B+�����Դϴ�." << std::endl;
	}
	else if (score >= 70 && score < 80)
	{
		std::cout << "B�����Դϴ�." << std::endl;
	}
	else if (score >= 60 && score < 0)
	{
		std::cout << "C+�����Դϴ�." << std::endl;
	} 
	else
	{
		std::cout << "C�����Դϴ�." << std::endl;
	}

	int value = 10;
	switch (value)
	{
	case 10: 
	{
		std::cout << "A+���� �Դϴ�." << std::endl;
		break;
	}
	case 9:
	{
		std::cout << "B���� �Դϴ�." << std::endl;
		break;
	}
	case 8:
	{
		std::cout << "C���� �Դϴ�." << std::endl;
		break;
	}
	case 7:
	{
		std::cout << "D���� �Դϴ�." << std::endl;
		break;
	}
	default: 
		break;
	}
	
	//Quize
	// Dan*Step = GuGuResult
	// Dan : 5
	// Step: 1~9;
	// �������� ����� ���İ� ����� ����ϼ���
	for (size_t step = 1; step <= 9; step++)
	{
		for (size_t dan = 2; dan <= 9; dan++)
			if (dan % 2 == 0)
				std::cout << dan << "x" << step << "=" << dan * step << "\t";
		std::cout << std::endl;
	}

	return 1;
}

