#include "util.h"

#include <stdio.h>
#include <QtMath>

Quaternion::Quaternion()
{
    this->scalar = 1.0;
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Quaternion::Quaternion(double scalar, double x, double y, double z)
{
    this->scalar = scalar;
    this->x = x;
    this->y = y;
    this->z = z;
}

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

Euler Quaternion::toEuler(QString mode, bool radian) {
    Euler e;
    if (mode == "XYZ") {
        e.x = atan2(2 * (x * scalar - y * z),
                    (scalar * scalar - x * x - y * y + z * z));
        e.y = asin(2 * (x * z + y * scalar));
        e.z = atan2(2 * (z * scalar - x * y),
                    (scalar * scalar + x * x - y * y - z * z));
    } else if (mode == "ZXY") {
        e.x = atan2(2 * (z * scalar - x * y),
                    (scalar * scalar - x * x + y * y - z * z));
        e.y = asin(2 * (x * scalar + y * z));
        e.z = atan2(2 * (y * scalar - z * x),
                    (scalar * scalar - x * x - y * y + z * z));
    } else if (mode == "YZX") {
        e.x = atan2(2 * (y * scalar - x * z),
                    (scalar * scalar + x * x - y * y - z * z));
        e.y = asin(2 * (x * y + z * scalar));
        e.z = atan2(2 * (x * scalar - z * y),
                    (scalar * scalar - x * x + y * y - z * z));
    }
    if (!radian) {
        e.x = e.x * 180.0 / M_PI;
        e.y = e.y * 180.0 / M_PI;
        e.z = e.z * 180.0 / M_PI;
    }
    return e;
}

Quaternion Euler::toQuaternion(QString mode, bool radian) {
    if (!radian) {
        x = x * M_PI / 180.0;
        y = y * M_PI / 180.0;
        z = z * M_PI / 180.0;
    }
    Quaternion q;
    double c1 = cos(x/2);
    double c2 = cos(y/2);
    double c3 = cos(z/2);
    double s1 = sin(x/2);
    double s2 = sin(y/2);
    double s3 = sin(z/2);

    if (mode == "XYZ") {
        q.scalar = c1 * c2 * c3 - s1 * s2 * s3;
        q.x = s1 * c2 * c3 + c1 * s2 * s3;
        q.y = c1 * s2 * c3 - s1 * c2 * s3;
        q.z = c1 * c2 * s3 + s1 * s2 * c3;

    } else if (mode == "ZXY") {
        q.scalar = c1 * c2 * c3 - s1 * s2 * s3;
        q.x = s1 * c2 * c3 - c1 * s2 * s3;
        q.y = c1 * s2 * c3 + s1 * c2 * s3;
        q.z = c1 * c2 * s3 + s1 * s2 * c3;

    } else if (mode == "YZX") {
        q.scalar = c1 * c2 * c3 - s1 * s2 * s3;
        q.x = s1 * c2 * c3 + c1 * s2 * s3;
        q.y = c1 * s2 * c3 + s1 * c2 * s3;
        q.z = c1 * c2 * s3 - s1 * s2 * c3;

    }
    return q;
}
