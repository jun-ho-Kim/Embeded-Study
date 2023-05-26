// ���α׷����� �����ϴ� ���� ����ð��� �󸶳� �ɸ����� �˰� �ʹ�.
// ���α׷��� ���� �ð��� ��� ����� ���� ����� ���̴�.
// ���α׷� ����ð��� �����ϴ� �Լ��� ���캸��
// sorting �Ϸ��� ����

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

//debug ���� release ���� ����ð��� �ٸ���.
//release ��尡 �ξ� ������.

// OS���忡���� �� ���� ���α׷� �� �ϳ��̴�. ��� ���ҽ��� �� ���Ƽ� ������ �͵� �ƴϰ� ��ǻ�Ͱ� Ŭ���� ���� �� �� ���� ������ �� �� �ɼǵ��
// �츮�� ���α׷� ����ð��� ���� ���� ��ҿ� ���� �޶�����. �� ��ҵ��� �츮�� �����ϱ� ��ƴ�. �׷��� ����ȭ�� ��ƴ�.
// �Ȱ��� ���α׷��� �ϵ���� ���� ����ð��� �޶����⵵ �ϰ� ���� �����ϸ� ĳ�ÿ� �� ����ð��� �޶����⵵ �Ѵ�.
// �׷��� ���α׷� �ð��� 0.0000002 ���̰ڴٰ� �����ϰ� ����� ���� �λ������̴�.

using namespace std;

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> start_time = clock_t::now(); // ���� �ð�, Ŭ������ ���۵Ǵ� �ð��� ����ð� ����

public:
	void elapsed()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();

		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl; // ���� �ð�, Ŭ������ ����Ǵ� �ð��� ����ð� ����
	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(10);

	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	std::shuffle(begin(vec), end(vec), mersenne_engine); // vecter�� ������ ������

	for (auto& e : vec) cout << e << " "; // ������ ������ ���
	cout << endl;

	Timer timer;

	std::sort(begin(vec), end(vec)); // ����
	 
	timer.elapsed(); // �ð��� �������

	for (auto& e : vec) cout << e << " "; // ������ �� �Ǿ����� Ȯ��
	cout << endl;

}