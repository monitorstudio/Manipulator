#ifndef _MOTOR_H_
#define _MOTOR_H_

struct Motor
{
public:
	Motor(void);
	Motor(long double);
	void set_angle(long double);
	long double get_angle(void);
private:
	long double _angle;
};

#endif /* _MOTOR_H_ */
