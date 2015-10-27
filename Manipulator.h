#ifndef _MANIPULATOR_H_
#define _MANIPULATOR_H_

#include "Motor.h"

struct Manipulator
{
public:
	Manipulator(long double, long double);
	Manipulator(void);
	void set_lv1(long double);
	void set_lv2(long double);
	int go_stright(double, double);
private:
	long double _lv1;
	long double _lv2;
	Motor _m1;
	Motor _m2;
};

#endif /* _MANIPULATOR_H_ */
