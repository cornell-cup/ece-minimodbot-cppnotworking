/*
 * Encoder.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: Claire
 */

#include "Encoder.h"
#include <stdio.h>
#include <stdlib.h>
#include "GLOBAL_DEFINES.h"
#include "mraa.hpp"
#include <time.h>
#include <unistd.h>

#include <iostream>

float CPR = 64.0;
float gear_ratio = 30.0;

mraa::Gpio* d_pin;

Encoder::Encoder(int pulsein_pin) {
	PULSEIN_PIN = pulsein_pin;

}

Encoder::~Encoder() {

}

int Encoder::initEncoder(){
	// Initialize GPIO pin for input pulse reading
	mraa::Gpio* PULSEIN = new mraa::Gpio(PULSEIN_PIN);
	if (PULSEIN == NULL){
		return 1; //return 1 if unable to initialize pulse input pin
	}

	// Set pin directions to be input
	PULSEIN->dir(mraa::DIR_IN);

	// Attach ISR to pin
	PULSEIN->isr(mraa::EDGE_FALLING, this->ISR_PULSEIN, NULL);

	d_pin = new mraa::Gpio(13);

	if (d_pin == NULL) {
		std::cerr << "Can't create mraa::Gpio object, exiting" << std::endl;
		return MRAA_ERROR_UNSPECIFIED;
	}

	// set the pin as output
	if (d_pin->dir(mraa::DIR_OUT) != MRAA_SUCCESS) {
		std::cerr << "Can't set digital pin as output, exiting" << std::endl;
		return MRAA_ERROR_UNSPECIFIED;
	}

	return 0;
}

/*
 * Return RPM
 */
float Encoder::getRPM(void){
	return RPM;
}

long Encoder::absoluteTime(void){
	struct timespec t;
	clock_gettime(CLOCK_MONOTONIC, &t);
	//	return (t.tv_nsec/1000);
	return ((long)t.tv_sec*1000+t.tv_nsec/1000);
}

static void Encoder::ISR_PULSEIN(void* args){
	d_pin->write(1);
	static long prevTime = 0;
	static long currTime = 0;
	prevTime = currTime;
	currTime = absoluteTime();
	RPM = 1000000.0 * 60.0 * (4/usecPerCount)/(CPR * gear_ratio);
}
