#ifndef DIRECT_SPHERES_INTEGRATOR_HPP
#define DIRECT_SPHERES_INTEGRATOR_HPP

#include "geometry/vec3.hpp"
#include "mesh/sphere.hpp"

namespace directspheres
{
    const int MAX_RAY_DEPTH = 10;

    double mix(double a, double b, double mix);

    Vec3f trace(Vec3f rayorig, Vec3f raydir, std::vector<Sphere> &spheres,
                int &depth);


    void render(std::vector<Sphere> &spheres);

}

#endif
