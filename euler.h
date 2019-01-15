#ifndef Euler_H
#define Euler_H
#include "quaternion.h"

//namespace Ui {
//class Euler;
//}
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


#endif // Euler_H
