#include "euler.h"
#include "quaternion.h"
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <QtMath>

Euler::Euler()
{
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Euler::Euler(double roll, double pitch, double yaw)
{
    this->x = roll;
    this->y = pitch;
    this->z = yaw;
}

Quaternion Euler::to_quaternion() {
    double cy = cos(z * 0.5);
    double sy = sin(z * 0.5);
    double cp = cos(y * 0.5);
    double sp = sin(y * 0.5);
    double cr = cos(x * 0.5);
    double sr = sin(x * 0.5);

    Quaternion q;
    q.scalar = cy * cp * cr + sy * sp * sr;
    q.x = cy * cp * sr - sy * sp * cr;
    q.y = sy * cp * sr + cy * sp * cr;
    q.z = sy * cp * cr - cy * sp * sr;
    return q;
}
