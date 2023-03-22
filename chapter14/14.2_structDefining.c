#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include <string.h> // malloc(), free()

#define MAX 41

struct  person 
{
	char name[MAX];	// member
	int age;		// member
	float height;	// member
};
// 구조체 안에서 멤버를 선언한 후 구조체 변수가 선언이 되어야 메모리가 할당이 된다.
// 구조체 선언만으로는 메모리 할당 X

int main()
{
	int flag; // Recevies return value of scanf()

	/* Structure variable */

	struct person genie;

	/* dot(.) is structure membership operator (member access operator, member operator) */
	
	strcpy(genie.name, "Will Smith");
	//strncpy(genie.name, "Will Smith", MAX);
	genie.age = 1000;


	// dot(.) has higer precedence than &
	flag = scanf("%f", &genie.height); // &(genie.height)
	printf("%f\n", genie.height);

	/* Initializaion */
	struct person princess = { "Naomi Scott", 18, 160.f };

	struct person princess2 = { 
		"Naomi Scott", 
		18, 
		160.f 
	};

	strcpy(princess.name, "Naomi Scott");
	princess.age = 18;
	princess.height = 160.f;

	/* Designated initializers */

	struct person beauty = {
		.age = 19,
		.name = "Bell",
		.height = 150.f
	};

	/* struct person beauty = { .age = 19, .name = "Bell", .height = 150.f }; */

	/* Pointer to a structure variable */
	struct person* someone;

	someone = &genie;
	//someone = (struct person*)malloc(sizeof(struct person)); //and free later

	/* Indirect member(ship) operator (or structure pointer operator) */

	someone->age = 1001; // arrow(->) operator
	printf("%s %d\n", someone->name, (*someone).age);
	// Pointer Struct의 access opertor 는 ->(arrow operator)이다.

	/* Sturcture declarations in a function */

	struct book 
	{
		char title[MAX];
		float price;
	};

	/* No tag */

	struct {
		char farm[MAX];
		float price;
	} apple, apple2; // 잠깐 사용할 구조체라면 tag 없이 선언해주어도 된다.

	strcpy(apple.farm, "Trade Joe");
	apple.price = 1.2f;

	strcpy(apple2.farm, "Safeway");
	apple2.price = 5.6f;

	/* typedef and structure */

	typedef struct person my_person;

	my_person p3;

	typedef struct person person;

	person p4;

	typedef struct {
		char name[MAX];
		char hobby[MAX];
	} friend;

	friend f4;

	return 0;
}