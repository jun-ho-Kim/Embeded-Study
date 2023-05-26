// 프로그래밍을 실행하다 보면 실행시간이 얼마나 걸리는지 알고 싶다.
// 프로그래밍 실행 시간을 재는 방법을 많이 사용할 것이다.
// 프로그램 실행시간을 측정하는 함수를 살펴보자
// sorting 하려는 예제

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

//debug 모드랑 release 모드랑 실행시간이 다르다.
//release 모드가 훨씬 빠르다.

// OS입장에서는 수 많은 프로그램 중 하나이다. 모든 리소스를 다 몰아서 돌리는 것도 아니고 컴퓨터가 클러도 돌고 그 때 마다 부팅을 할 지 옵션등등
// 우리의 프로그램 실행시간은 정말 많은 요소에 의해 달라진다. 그 요소들을 우리가 제어하기 어렵다. 그래서 최적화가 어렵다.
// 똑같은 프로그램도 하드웨어 따라 실행시간이 달라지기도 하고 자주 실행하면 캐시에 들어가 실행시간이 달라지기도 한다.
// 그래서 프로그램 시간을 0.0000002 줄이겠다고 무모하게 덤비는 것은 인생낭비이다.

using namespace std;

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> start_time = clock_t::now(); // 시작 시간, 클래스가 시작되는 시간에 현재시간 넣음

public:
	void elapsed()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();

		cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl; // 종료 시간, 클래스가 종료되는 시간에 현재시간 넣음
	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(10);

	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	std::shuffle(begin(vec), end(vec), mersenne_engine); // vecter의 순서를 섞어줌

	for (auto& e : vec) cout << e << " "; // 섞어준 순서를 출력
	cout << endl;

	Timer timer;

	std::sort(begin(vec), end(vec)); // 정렬
	 
	timer.elapsed(); // 시간을 출력해줌

	for (auto& e : vec) cout << e << " "; // 정렬이 잘 되었는지 확인
	cout << endl;

}