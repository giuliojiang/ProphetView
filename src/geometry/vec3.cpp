#include "geometry/vec3.hpp"

Vec3f::Vec3f()
:   x(0),
    y(0),
    z(0)
{}

Vec3f::Vec3f(double _a)
:   x(_a),
    y(_a),
    z(_a)
{}

Vec3f::Vec3f(double _x, double _y, double _z)
:   x(_x),
    y(_y),
    z(_z)
{}

void Vec3f::normalize()
{
    double len2 = length2();
    if (len2 > 0)
    {
        x /= sqrt(len2);
        y /= sqrt(len2);
        z /= sqrt(len2);
    }
}

Vec3f Vec3f::getNormalized()
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

double Vec3f::dot(Vec3f &v)
{
    return x*v.x + y*v.y + z*v.z;
}

Vec3f Vec3f::cross(Vec3f v)
{
    return Vec3f(
        y*v.z - z*v.y,
        z*v.x - x*v.z,
        x*v.y - y*v.x
                );
}

double Vec3f::length2()
{
    return x*x + y*y + z*z;
}

double Vec3f::length()
{
    return sqrt(length2());
}
