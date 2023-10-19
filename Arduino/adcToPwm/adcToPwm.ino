/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

int led = 9;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(A1);
  Serial.print("ADC : ");
  // print out the value you read:
  Serial.print(sensorValue);
  Serial.print(", VOLT : ");
  Serial.print(5/1024.0 * sensorValue);

  //Serial.println(millis());
  // set the brightness of pin 9:
  //brightness = (int)(sensorValue/4.0);
  //brightness = map(sensorValue, 700, 1000, 0, 255);
  brightness = constrain(sensorValue, 0, 100);
  

  analogWrite(led, brightness);
  Serial.print(", PWD : ");
  // print out the value you read:
  Serial.print(brightness);
  Serial.print(", VOLT : ");
  Serial.println(5/1024.0 * brightness);

  //analogWrite(led, brightness);



  /*
  Serial.print("PWM : ");
  Serial.print(brightness);
  Serial.print(", volt: ");
  Serial.println(5/256.0 * brightness);
  */

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  //delay(30);
  //Serial.println(millis());
}
