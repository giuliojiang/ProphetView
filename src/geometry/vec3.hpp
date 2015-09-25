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

// ===================================================================
// members

    T x;
    T y;
    T z;

// ===================================================================
// Constructors

    Vec3<T>()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vec3<T>(T _a)
    {
        x = _a;
        y = _a;
        z = _a;
    }

    Vec3<T>(T _x, T _y, T _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

// ========================================================
// methods

    void normalize()
    {
        T len2 = length2();
        if (len2 > 0)
        {
            x /= sqrt(len2);
            y /= sqrt(len2);
            z /= sqrt(len2);
        }
    }

    Vec3<T> getNormalized()
    {
        T len2 = length2();
        T newX = x;
        T newY = y;
        T newZ = z;
        if (len2 > 0)
        {
            newX = x / len2;
            newY = y / len2;
            newZ = z / len2;
            return Vec3<T>(newX, newY, newZ);
        }
        return Vec3<T>(x, y, z);
    }
    
    Vec3<T> operator * (Vec3<T> v)
    {
        return Vec3<T>(x*v.x, y*v.y, z*v.z);
    }

    Vec3<T> operator * (T f)
    {
        return Vec3<T>(x*f, y*f, z*f);
    }

    T dot(Vec3<T> &v)
    {
        return x*v.x + y*v.y + z*v.z;
    }
    
    Vec3<T> cross(Vec3<T> v)
    {
        return Vec3<T>(
            y*v.z - z*v.y,
            z*v.x - x*v.z,
            x*v.y - y*v.x
                    );
    }

    Vec3<T> operator + (Vec3<T> v)
    {
        return Vec3<T>(x+v.x, y+v.y, z+v.z);
    }

    Vec3<T> operator - (Vec3<T> v)
    {
        return Vec3<T>(x-v.x, y-v.y, z-v.z);
    }

    Vec3<T>& operator += (Vec3<T> v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3<T>& operator -= (Vec3<T> v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vec3<T>& operator *= (Vec3<T> v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    Vec3<T> operator - ()
    {
        return Vec3<T>(-x, -y, -z);
    }

    T length2()
    {
        return x*x + y*y + z*z;
    }

    T length()
    {
        return sqrt(length2());
    }

    friend std::ostream& operator << (std::ostream &os, Vec3<T> v)
    {
        os << "[" << v.x << "," << v.y << "," << v.z << "]";
        return os;
    }

};


typedef Vec3<double> Vec3f;



#endif
