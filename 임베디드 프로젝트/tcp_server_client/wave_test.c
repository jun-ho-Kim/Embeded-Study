#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int tring = 23;
	int echo = 24;
	int led_1 = 17;
	int start_time, end_time;
	float distance;

	if(wiringPiSetup() == -1 ) exit(1);


	pinMode(tring, OUTPUT);
	pinMode(echo, INPUT);

	while(1) {
		digitalWrite(tring, LOW);
		delay(500);
		digitalWrite(tring, HIGH);
		delayMicroseconds(10);
		digitalWrite(tring, LOW);
		while(digitalRead(echo) == 0);
		start_time = micros();
		while(digitalRead(echo) == 1);
		end_time = micros();
		distance = (end_time - start_time) / 29. / 2.;

		printf("distance %.2f cm\n", distance);
	}
	
	return 0;




	
}
