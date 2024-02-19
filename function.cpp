#include "Header.h"

double Temp(double distanse, double time) {
	double temp = 0.0;
	temp = time / distanse;
	return temp;
}
double Speed(double distanse, double time) {
	double speed = 0.0;
	speed = (distanse / time) * 60;
	return speed;
}
double Time(double distanse, double temp) {
	double time = 0.0;
	time = distanse * temp;
	return time;
}
double Distans(double time, double temp) {
	double distanse = 0.0;
	distanse = time * temp * 60;
	return distanse;
}