/*
 * Motor.h
 *
 *  Created on: Feb 6, 2016
 *      Author: Claire
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "mraa.hpp"
#include "GLOBAL_DEFINES.h"

#define MOTOR_CW	0
#define MOTOR_CCW	1

#define MAX_DUTY	0.95
#define MIN_DUTY	0.05

class Motor {
public:
	Motor();
	Motor(int pin1, int pin2, int enc_pin);
	virtual ~Motor();

	/*
	 * motor direction function must be called before using drive or brake functions
	 */
	int motor_drive(float duty);
	int motor_direction(int direction);
	int motor_brake(void);
	float motor_PID(void);
	float getRPM();
};

#endif /* MOTOR_H_ */
