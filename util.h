#ifndef UTIL_H
#define UTIL_H


class Quaternion;
class Euler;

class Quaternion
{

public:
    Quaternion();
    Quaternion(double scalar, double x, double y, double z);
    Euler toEuler();
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
    Quaternion toQuaternion();

    double x;
    double y;
    double z;

};

#endif // UTIL_H
