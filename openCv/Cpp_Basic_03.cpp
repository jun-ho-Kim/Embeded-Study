#include <string>
#include <iostream>

using namespace std;

class CCalc
{
private:
	int sum = 0;
	double avg = 0.0;

public:
	void SetSumValue(int _sum)
	{
		sum = _sum;
	};
	void SetAvgValue(double _avg)
	{
		avg = _avg;
	};
	void DispSum()
	{
		cout << "sum is: " << sum << endl;
	}
	void DispAvg()
	{
		cout << "avg is: " << avg << endl;
	};
};

void Calc(int* pData, int size, CCalc* pCalc)
{
	cout << "pCalc addr: " << pCalc << endl;
	int _sum = 0;
	if (pData != nullptr && pCalc != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			_sum += pData[i];
		}
		pCalc->SetSumValue(_sum);

		pCalc->SetAvgValue(static_cast<double>(_sum) / static_cast<double>(size));
	}
}


int main()
{
	int arr[10] = { 1,2,3,4,1,2,3,12,2,10 };
	int size = sizeof(arr) / sizeof(arr[0]);

	CCalc _Calc;
	cout << "_Calc addr: " << &_Calc << endl;

	Calc(arr, size, &_Calc);

	_Calc.DispSum();
	_Calc.DispAvg();

	int z = 3;

	return 1;
}