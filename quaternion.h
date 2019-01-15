#ifndef QUATERNION_H
#define QUATERNION_H
#include "euler.h"

//namespace Ui {
//class Quaternion;
//}
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

#endif // QUATERNION_H
