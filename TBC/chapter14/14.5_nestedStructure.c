#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define LEN 20

struct names {
	char given[LEN];
	char family[LEN];
};

struct reservation {
	struct names guest;
	struct names host;
	char food[LEN];
	char place[LEN];

	// time
	int year;
	int month;
	int day;
	int hours;
	int minutes;
};

int main()
{
	struct  reservation res =
	{
		.guest = {"Nick", "carraway"},
		.host = {"Jay", "Gastby"},
		.place = {"the Gasby mansion"},
		.food = {"Escargot"},
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};

	const char* formatted =
		"\
		Dear %s %s, \n I would like to serve you %s. \n\
		Please visit the %s on %d / %d / %d at %d:%d \n\
		Sincerely, \n\
		%s %s\
		";

	printf(formatted, res.guest.given, res.guest.family, res.food, res.place, 
		res.day, res.month, res.year, res.hours, res.minutes, 
		res.host.given, res.host.family);

	return 0;
}