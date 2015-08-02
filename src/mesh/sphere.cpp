#include <iostream>

#include "geometry/vec3.hpp"
#include "mesh/sphere.hpp"


Sphere::Sphere(Vec3f _center, double _radius, Vec3f _surfaceColor, double _reflection,
       double _transparency, Vec3f _emissionColor)
{
    center = _center;
    radius = _radius;
    radius2 = radius * radius;
    surfaceColor = _surfaceColor;
    reflection = _reflection;
    transparency = _transparency;
    emissionColor = _emissionColor;
}

Sphere::Sphere(Vec3f _center, double _radius, Vec3f _surfaceColor)
{
    center = _center;
    radius = _radius;
    radius2 = radius * radius;
    surfaceColor = _surfaceColor;
    reflection = 0;
    transparency = 0;
    emissionColor = Vec3f(0);
}

bool Sphere::intersect(Vec3f rayorig, Vec3f raydir, double &t0, double &t1)
{
    Vec3f l = center - rayorig;
    double tca = l.dot(raydir);
    if (tca < 0)
    {
        return false;
    }

    double d2 = l.dot(l) - tca * tca;
    if (d2 > radius2)
    {
        return false;
    }

    double thc = sqrt(radius2 - d2);
    t0 = tca - thc;
    t1 = tca + thc;

    return true;
}


