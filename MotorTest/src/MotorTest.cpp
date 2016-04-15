
#include "GLOBAL_DEFINES.h"
#include "Encoder.h"
#include "Motor.h"
#include <iostream>

int main() {
	/* Setup your example here, code that should run once
	 */


	//Create left and right motors
	Motor motorLeft = *(new Motor(MOTOR_LEFT_1_PIN, MOTOR_LEFT_2_PIN, PULSEIN_PIN_L));
	std::cout << "motor 1 created \n";
	Motor motorRight = *(new Motor(MOTOR_RIGHT_1_PIN, MOTOR_RIGHT_2_PIN, PULSEIN_PIN_R));
	std::cout << "motor 2 created \n";

	float duty = 0.3;
	float RPM_L;
	float usec_L;
//	float RPM_R;
//	float usec_R;

	motorLeft.motor_direction(MOTOR_CW);
	motorLeft.motor_drive(0.5);
	motorRight.motor_direction(MOTOR_CW);
	motorRight.motor_drive(0.5);

	sleep(1);
	int i=0;

	while(1){
		usleep(20000);
		if(duty <0) duty =0;
		if(duty >0.95) duty =0.95;
		motorLeft.motor_drive(duty);
		motorRight.motor_drive(duty);

		if(++i ==1) {
			RPM_L = motorLeft.getRPM();
//			RPM_R = motorRight.getRPM();
//			fprintf(stdout, "RPM_L: %.1f   duty: %.3f \n",(float)RPM_L, duty);
//			fprintf(stdout, "RPM_R: %.1f   duty: %.3f   usec_R: %.1f\n",(float)RPM_R, duty, usec_R);
			i=0;
			sleep(1);
		}
	}

	while (1){
		float duty = 0.05;
	}

	return MRAA_SUCCESS;

	return 0;
}
