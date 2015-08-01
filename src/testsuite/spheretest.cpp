#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

#include "geometry/vec3.hpp"
#include "mesh/sphere.hpp"
#include "testsuite/testutils.hpp"

int main()
{
    Sphere s = Sphere(Vec3f(1,2,3), 10, Vec3f(255,255,255));
    std::cout << s << std::endl;
    return 0;
}
