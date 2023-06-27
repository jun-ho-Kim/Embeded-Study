#include <stdio.h>

struct vision
{
	double left;
	double right;
};

struct vision exchange(struct vision robot);

int main(void)
{

	struct vision robot;

	printf("시력 입력 : ");
	scanf("%lf%lf", &(robot.left), &(robot.right));
	printf("main robot pointer is %p\n", &robot); // main robot value is 858993459
	printf("main robot value is %.1lf\n", robot); // main robot value is 1.2
	robot = exchange(robot);
	printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);

	int z = 3;

	return 0;
}

struct vision exchange(struct vision robot)
{
	printf("func robot pointer is %p\n", &robot);	// func robot pointer is 005AF988
	printf("func robot value is %.1lf\n", robot);	// func robot value is 1.2

	double temp;

	temp = robot.left;
	robot.left = robot.right;
	robot.right = temp;

	return robot;
}