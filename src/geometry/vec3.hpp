#ifndef VEC3_H
#define VEC3_H

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

class Vec3f
{
    public:
        
// ===================================================================
// constants
    static constexpr double PI = 3.14;

// ===================================================================
// members

    double x;
    double y;
    double z;

// ===================================================================
// Constructors

    Vec3f();
    Vec3f(double _a);
    Vec3f(double _x, double _y, double _z);

// ========================================================
// methods

    void normalize();

    Vec3f getNormalized();
    
    Vec3f operator * (Vec3f v)
    {
        return Vec3f(x*v.x, y*v.y, z*v.z);
    }

    Vec3f operator * (double f)
    {
        return Vec3f(x*f, y*f, z*f);
    }

    double dot(Vec3f &v);
    
    Vec3f cross(Vec3f v);

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

    double length2();

    double length();

    friend std::ostream& operator << (std::ostream &os, Vec3f v)
    {
        os << "[" << v.x << "," << v.y << "," << v.z << "]";
        return os;
    }

};

#endif
