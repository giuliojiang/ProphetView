#ifndef VEC3_H
#define VEC3_H

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

#define M_PI 3.14159265359

class Vec3f
{
    public:

// ===================================================================
// members

    double x;
    double y;
    double z;

// ===================================================================
// Constructors

    Vec3f()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vec3f(double _a)
    {
        x = _a;
        y = _a;
        z = _a;
    }

    Vec3f(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

// ========================================================
// methods

    void normalize()
    {
        double len2 = length2();
        if (len2 > 0)
        {
            x /= sqrt(len2);
            y /= sqrt(len2);
            z /= sqrt(len2);
        }
    }

    Vec3f getNormalized()
    {
        double len2 = length2();
        double newX = x;
        double newY = y;
        double newZ = z;
        if (len2 > 0)
        {
            newX = x / len2;
            newY = y / len2;
            newZ = z / len2;
            return Vec3f(newX, newY, newZ);
        }
        return Vec3f(x, y, z);
    }
    
    Vec3f operator * (Vec3f v)
    {
        return Vec3f(x*v.x, y*v.y, z*v.z);
    }

    Vec3f operator * (double f)
    {
        return Vec3f(x*f, y*f, z*f);
    }

    double dot(Vec3f &v)
    {
        return x*v.x + y*v.y + z*v.z;
    }
    
    Vec3f cross(Vec3f v)
    {
        return Vec3f(
            y*v.z - z*v.y,
            z*v.x - x*v.z,
            x*v.y - y*v.x
                    );
    }

    Vec3f operator + (Vec3f v)
    {
        return Vec3f(x+v.x, y+v.y, z+v.z);
    }

    Vec3f operator - (Vec3f v)
    {
        return Vec3f(x-v.x, y-v.y, z-v.z);
    }

    Vec3f& operator += (Vec3f v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3f& operator -= (Vec3f v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vec3f& operator *= (Vec3f v)
    {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    Vec3f operator - ()
    {
        return Vec3f(-x, -y, -z);
    }

    double length2()
    {
        return x*x + y*y + z*z;
    }

    double length()
    {
        return sqrt(length2());
    }

    friend std::ostream& operator << (std::ostream &os, Vec3f v)
    {
        os << "[" << v.x << "," << v.y << "," << v.z << "]";
        return os;
    }

};

#endif
