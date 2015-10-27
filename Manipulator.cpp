#include "Manipulator.h"

#include <iostream>
#include <cmath>

Manipulator::Manipulator(void)
{
	
}

Manipulator::Manipulator(long double lv1, long double lv2)
{
	_m1 = Motor::Motor(60 * 3.14159265359 / 180);
	_m2 = Motor::Motor(0);
	_lv1 = lv1;
	_lv2 = lv2;
	_lv1_x = _lv1 * sin(_m1.get_angle());
	_lv1_y = _lv1 * cos(_m1.get_angle());
	_lv2_x = _lv2 * sin(_m2.get_angle()) + _lv1_x;
	_lv2_y = _lv2 * cos(_m2.get_angle()) + _lv1_y;
}

void Manipulator::set_lv1(long double lv1)
{
	_lv1 = lv1;
}

void Manipulator::set_lv2(long double lv2)
{
	_lv2 = lv2;
}

int Manipulator::go_stright(double x, double y)
{
	long double A, B, C, h1, h2, k1, k2, m1_angle1, m1_angle2, m2_angle;

	/*  */
	A = (((x * x) / (y * y)) + 1);
	B = ((-2 * x * ((_lv1 * _lv1) + (x * x) + (y * y) - (_lv2 * _lv2)) / (2 * y)) / y);
	C = ((((_lv1 * _lv1) + (x * x) + (y * y) - (_lv2 * _lv2)) / (2 * y) * ((_lv1 * _lv1) + (x * x) + (y * y) - (_lv2 * _lv2)) / (2 * y)) - (_lv1 * _lv1));

	h1 = ((-B) + pow((B * B) - 4 * A * C, 0.5)) / (2 * A);
	h2 = ((-B) - pow((B * B) - 4 * A * C, 0.5)) / (2 * A);

	/*  */
	A = (((y * y) / (x * x)) + 1);
	B = ((-2 * y * ((_lv1 * _lv1) + (x * x) + (y * y) - (_lv2 * _lv2)) / (2 * x)) / x);
	C = ((((_lv1 * _lv1) + (x * x) + (y * y) - (_lv2 * _lv2)) / (2 * x) * ((_lv1 * _lv1) + (x * x) + (y * y) - (_lv2 * _lv2)) / (2 * x)) - (_lv1 * _lv1));

	k1 = ((-B) - powl(B * B - 4 * A * C, 0.5)) / (2 * A);
	k2 = ((-B) + powl(B * B - 4 * A * C, 0.5)) / (2 * A);

	m1_angle1 = acos((h1 * h1 + _lv1 * _lv1 - k1 * k1) / (2 * h1 * _lv1));
	m1_angle2 = acos((h2 * h2 + _lv1 * _lv1 - k2 * k2) / (2 * h2 * _lv1));
	m2_angle = acos((_lv1 * _lv1 + _lv2 * _lv2 - (x * x + y * y)) / (2 * _lv1 * _lv2));

	if((h1 != h1) || (h2 != h2) || (k1 != k1) || (k2 != k2) || (m1_angle1 != m1_angle1) || (m1_angle2 != m1_angle2) || (m2_angle != m2_angle))
		return -1;

	std::cout << ".DBGINFO	_m1.angle: " << _m1.get_angle() * 180 / 3.14159265359 << std::endl;
	std::cout << ".DBGINFO	_m2.angle: " << _m2.get_angle() * 180 / 3.14159265359 << std::endl;

	if(std::abs(m1_angle1 - _m1.get_angle()) >= std::abs(m1_angle2 - _m1.get_angle()))
	{
		if(m1_angle2 > _m1.get_angle())
		{
			std::cout << "Motor1 forward " << (m1_angle2 - _m1.get_angle()) * 180 / 3.14159265359 << " degrees" << std::endl;
		}
		else
		{
			std::cout << "Motor1 backward " << (_m1.get_angle() - m1_angle2) * 180 / 3.14159265359 << " degrees" << std::endl;
		}
		_m1.set_angle(m1_angle2);
	}
	else
	{
		if(m1_angle1 > _m1.get_angle())
		{
			std::cout << "Motor1 forward " << (m1_angle1 - _m1.get_angle()) * 180 / 3.14159265359 << " degrees" << std::endl;
		}
		else
		{
			std::cout << "Motor1 backeard " << (_m1.get_angle() - m1_angle1) * 180 / 3.14159265359 << " degrees" << std::endl;
		}
		_m1.set_angle(m1_angle1);
	}

	if(m2_angle > _m2.get_angle())
	{
		std::cout << "Motor2 forward " << (m2_angle - _m2.get_angle()) * 180 / 3.14159265359 << " degrees" << std::endl;
	}
	else
	{
		std::cout << "Motor2 backward " << (_m2.get_angle() - m2_angle) * 180 / 3.14159265359 << " degrees" << std::endl;
	}
	_m2.set_angle(m2_angle);

	std::cout << ".DBGINFO	_m1.angle: " << _m1.get_angle() * 180 / 3.14159265359 << std::endl;
	std::cout << ".DBGINFO	_m2.angle: " << _m2.get_angle() * 180 / 3.14159265359 << std::endl;

	return 0;
}
