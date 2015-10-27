#include "Motor.h"

Motor::Motor(void)
{
	_angle = 0;
}

Motor::Motor(long double angle)
{
	_angle = angle;
}

void Motor::set_angle(long double angle)
{
	_angle = angle;
}

long double Motor::get_angle(void)
{
	return _angle;
}
