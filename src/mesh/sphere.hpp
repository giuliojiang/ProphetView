#ifndef SPHERE_H
#define SPHERE_H

#include "geometry/vec3.hpp"

class Sphere
{
public:
    Vec3f center;
    double radius;
    double radius2;
    Vec3f surfaceColor;
    Vec3f emissionColor;
    double transparency;
    double reflection;

    Sphere(Vec3f _center, double _radius, Vec3f _surfaceColor, double _reflection,
           double _transparency, Vec3f _emissionColor);

    Sphere(Vec3f _center, double _radius, Vec3f _surfaceColor);

    bool intersect(Vec3f rayorig, Vec3f raydir, double &t0, double &t1);

    friend std::ostream& operator << (std::ostream &os, Sphere s)
    {
        os << "sphere[center=" << s.center << ",radius="
           << s.radius << ",surfacecolor=" << s.surfaceColor
           << ",emissionColor=" << s.emissionColor << "]";
        return os;
    }
};

#endif
