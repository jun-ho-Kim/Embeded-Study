//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	/*
		Simulation of a Moving Object
		
		- Speed = 1.0 m/s
		- dt = 1.0s
		- Distance traveled during dt = Speed * dt

		- Step 1 : 1.0m/s * 1.0s = 1.0m, dist = 1.0m
		- Step 2 : 1.0m/s * 1.0s = 1.0m, dist = 1.0m + 1.0m = 2.0m
		- Step 3 : 1.0m/s * 1.0s = 1.0m, dist = 2.0m + 1.0m = 3.0m
	*/

	/*
		Zeno`s Paradox
		- Step 1 : 1.0m/s * 1.0s = 1.0m, dist = 1.0m
		- Step 2 : 1.0m/s * 0.5s = 0.5m, dist = 1.0m + 0.5m = 1.5m
		- Step 3 : 1.0m/s * 0.25s = 0.25m, dist = 1.5m + 0.25m = 1.75m
	*/

	const double speed = 1.0;
	const unsigned repeat_max = 10;

	double dt = 1.0;
	double time = 0.0;
	double dist = 0.0;

	for (unsigned i = 1; i <= repeat_max; i++) {

		dist += speed * dt;
		time += dt;
		printf("Elased time = %f, Distance = %fm\n", time, dist);
		
		dt *= 0.5;
		//dt = dt / 2;
	}

	/* 내가 짠 코드
	for (double distance = 1; distance <= 10; ++distance) {
		printf("Elased time = %f, Distance = %fm\n", distance * dt, distance);
	}
	*/


	return 0;
}