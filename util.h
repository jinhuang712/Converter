#ifndef UTIL_H
#define UTIL_H
#include <QString>
#include <QQuaternion>
#include <QVector3D>

class Quaternion;
class Euler;

class Quaternion
{

public:
    Quaternion();
    Quaternion(double scalar, double x, double y, double z);
    Euler toEuler(QString mode = "XYZ", bool radian = false);
    double scalar;
    double x;
    double y;
    double z;

};

class Euler
{

public:
    Euler();
    Euler(double roll, double pitch, double yaw);
    Quaternion toQuaternion(QString mode = "XYZ", bool radian = false);
    double x;
    double y;
    double z;

};

#endif // UTIL_H
