#ifndef VEC3_H
#define VEC3_H

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

template<class T>
class Vec3
{
    public:

    T x;
    T y;
    T z;

    Vec3();
    Vec3(T _a);
    Vec3(T _x, T _y, T _z);

    Vec3& normalize();
    Vec3<T> operator * (T &f);
    Vec3<T> operator * (Vec3<T> &v);
    T dot(Vec3<T> &v);
    Vec3<T> operator + (Vec3<T> &v);
    Vec3<T> operator - (Vec3<T> &v);
    Vec3<T>& operator += (Vec3<T> &v);
    Vec3<T>& operator -= (Vec3<T> &v);
    Vec3<T>& operator *= (Vec3<T> &v);
    Vec3<T> operator - ();
    T length2();
    T length();
};

typedef Vec3<double> Vec3f;


#endif
