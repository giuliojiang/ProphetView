#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

#include "geometry/vec3.h"

// ===================================================================
// Constructors

template <class T>
Vec3<T>::Vec3()
{
    x = 0;
    y = 0;
    z = 0;
}

template <class T>
Vec3<T>::Vec3(T _a)
{
    x = _a;
    y = _a;
    z = _a;
}

template <class T>
Vec3<T>::Vec3(T _x, T _y, T _z)
{
    x = _x;
    y = _y;
    z = _z;
}

// ===================================================================
// Operations

template <class T>
Vec3<T>& Vec3<T>::normalize()
{
    T len2 = length2();
    if (len2 > 0)
    {
        x /= len2;
        y /= len2;
        z /= len2;
    }
    return *this;
}


template <class T>
Vec3<T> Vec3<T>::operator * (T &f)
{
    return Vec3<T>(x*f, y*f, z*f);
}


template <class T>
Vec3<T> Vec3<T>::operator * (Vec3<T> &v)
{
    return Vec3<T>(x*v.x, y*v.y, z*v.z);
}


template <class T>
T Vec3<T>::dot(Vec3<T> &v)
{
    return x*v.x + y*v.y + z*v.z;
}


template <class T>
Vec3<T> Vec3<T>::operator + (Vec3<T> &v)
{
    return Vec3<T>(x+v.x, y+v.y, z+v.z);
}


template <class T>
Vec3<T> Vec3<T>::operator - (Vec3<T> &v)
{
    return Vec3<T>(x-v.x, y-v.y, z-v.z);
}


template <class T>
Vec3<T>& Vec3<T>::operator += (Vec3<T> &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}


template <class T>
Vec3<T>& Vec3<T>::operator -= (Vec3<T> &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}


template <class T>
Vec3<T>& Vec3<T>::operator *= (Vec3<T> &v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}


template <class T>
Vec3<T> Vec3<T>::operator - ()
{
    return Vec3<T>(-x, -y, -z);
}


template <class T>
T Vec3<T>::length2()
{
    return x*x + y*y + z*z;
}


template <class T>
T Vec3<T>::length()
{
    return sqrt(length2());
}


template <class T>
std::ostream& operator << (std::ostream &os, Vec3<T> &v)
{
    os << "[" << v.x << "," << v.y << "," << v.z << "]";
    return os;
}


