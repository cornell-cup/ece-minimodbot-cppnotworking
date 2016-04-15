/*
 * Encoder.h
 *
 *  Created on: Feb 6, 2016
 *      Author: Claire
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include "mraa.hpp"
#include "GLOBAL_DEFINES.h"

class Encoder {
public:
	float usecPerCount = 0;
	float RPM = 0;
	int	  PULSEIN_PIN;

	Encoder();
	Encoder(int);
	virtual ~Encoder();

	int initEncoder();
	float getRPM();
	float getusecPerCount();
	long absoluteTime(void);
	static void ISR_PULSEIN(void* args);


};

//extern "C" {
//	long absoluteTime(void);
//	void ISR_PULSEIN(void* args);
//}
#endif /* ENCODER_H_ */
