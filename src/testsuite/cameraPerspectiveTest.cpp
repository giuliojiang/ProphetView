#include <iostream>

#include "camera/cameraPerspective.hpp"

int main(void)
{
    Vec3f origin = Vec3f(0,0,0);
    Vec3f view = Vec3f(1,0,0);
    Vec3f up = Vec3f(0,1,0);
    CameraPerspective* cp = new CameraPerspective(1920, 1080, origin, view, up, 0.035, 0.035);
    
    std::cout << cp << std::endl;
    delete cp;
    
    return 0;
    
}