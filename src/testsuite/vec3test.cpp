#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

#include "geometry/vec3.hpp"
#include "testsuite/testutils.hpp"

int main()
{
    std::cout << "Vec3 tests..." << std::endl;
    Vec3f v = Vec3f(1,2,3);
    TESTPRINT(v << std::endl)
    assert(v.x == 1 && v.y == 2 && v.z == 3);

    Vec3f w = Vec3f();
    TESTPRINT(v + w << std::endl)
    assert(w.x == 0 && w.y == 0 && w.z == 0);

    v = Vec3f(-1);
    TESTPRINT(v << std::endl)
    assert(v.x == -1 && v.y == -1 && v.z == -1);

    Vec3f n = Vec3f(10,20,30);
    n.normalize();
    TESTPRINT(n << std::endl)
    TESTPRINT(n.getNormalized() << std::endl)
    TESTPRINT("length=" << n.length() << std::endl)
    assert(n.length() - 1 < 0.01 || n.length() - 1 > -0.01);

    TESTPRINT(n * 2.0 << std::endl)

    TESTPRINT((n * 2.0) * 10 << std::endl)

    TESTPRINT(n * v << std::endl)

    TESTPRINT(n * v * v << std::endl)

    v = Vec3f(1,2,3);
    v *= Vec3f(-1);
    TESTPRINT(v << std::endl)

    std::cout << "  OK" << std::endl << std::endl;

    return 0;
}
