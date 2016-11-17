// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "arduino.h"
#include <Adafruit_MotorShield.h>
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
    return RunArduinoSketch();
}

int led = 13;  // This is the pin the LED is attached to.

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_MotorShield AFMS2 = Adafruit_MotorShield(0x61);
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);
Adafruit_DCMotor *myMotor5 = AFMS2.getMotor(1);

void setup()
{
    pinMode(led, OUTPUT);       // Configure the pin for OUTPUT so you can turn on the LED.

	Log(L"Adafruit Motorshield v2 - DC Motor test!\n");

	Serial.begin(9600);           // set up Serial library at 9600 bps

	AFMS.begin();  // create with the default frequency 1.6KHz
				   //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
	AFMS2.begin();

	// Set the speed to start, from 0 (off) to 255 (max speed)
	myMotor1->setSpeed(150);
	myMotor2->setSpeed(150);
	myMotor3->setSpeed(150);
	myMotor4->setSpeed(150);
	myMotor5->setSpeed(150);
}

// the loop routine runs over and over again forever:
void loop()
{
	std::cout << "Ready." << std::endl;
	char command = getc(stdin);

	switch (command){
	// Motor 1
	case 'w':
		myMotor1->run(FORWARD);
		delay(100);
		myMotor1->run(BRAKE);
		myMotor1->run(RELEASE);
		break;
	case 's':
		myMotor1->run(BACKWARD);
		delay(100);
		myMotor1->run(BRAKE);
		myMotor1->run(RELEASE);
		break;
	
	// Motor 2
	case 'e':
		myMotor2->run(FORWARD);
		delay(100);
		myMotor2->run(BRAKE);
		myMotor2->run(RELEASE);
		break;
	case 'd':
		myMotor2->run(BACKWARD);
		delay(100);
		myMotor2->run(BRAKE);
		myMotor2->run(RELEASE);
		break;

	// Motor 3
	case 'r':
		myMotor3->run(FORWARD);
		delay(100);
		myMotor3->run(BRAKE);
		myMotor3->run(RELEASE);
		break;
	case 'f':
		myMotor3->run(BACKWARD);
		delay(100);
		myMotor3->run(BRAKE);
		myMotor3->run(RELEASE);
		break;

	// Motor 4
	case 't':
		myMotor4->run(FORWARD);
		delay(100);
		myMotor4->run(BRAKE);
		myMotor4->run(RELEASE);
		break;
	case 'g':
		myMotor4->run(BACKWARD);
		delay(100);
		myMotor4->run(BRAKE);
		myMotor4->run(RELEASE);
		break;

	// Motor 5
	case 'y':
		myMotor5->run(FORWARD);
		delay(100);
		myMotor5->run(BRAKE);
		myMotor5->run(RELEASE);
		break;
	case 'h':
		myMotor5->run(BACKWARD);
		delay(100);
		myMotor5->run(BRAKE);
		myMotor5->run(RELEASE);
		break;

	case 'j':
		digitalWrite(led, HIGH);
		break;

	case 'i':
		digitalWrite(led, LOW);
		break;
	}

	/*
	uint8_t i;
	Log(L"tick\n");
	Serial.print("tick");

	myMotor1->run(FORWARD);
	for (i = 0; i<255; i++) {
		myMotor1->setSpeed(i);
		delay(10);
	}
	for (i = 255; i != 0; i--) {
		myMotor1->setSpeed(i);
		delay(10);
	}

	Serial.print("tock");

	myMotor1->run(BACKWARD);
	for (i = 0; i<255; i++) {
		myMotor1->setSpeed(i);
		delay(10);
	}
	for (i = 255; i != 0; i--) {
		myMotor1->setSpeed(i);
		delay(10);
	}

	Serial.print("tech");
	myMotor1->run(RELEASE);
	delay(1000);
	*/
}