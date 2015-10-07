#ifndef CAMERA_PERSPECTIVE_H
#define CAMERA_PERSPECTIVE_H

#include <cmath>
#include <iostream>
#include "geometry/vec3.hpp"

class CameraPerspective
{
private:
    // class members
    double framePixelsX;
    double framePixelsY;
    Vec3f originPoint;
    Vec3f viewDirection;
    Vec3f upDirection;
    Vec3f rightDirection;
    double focalLength;
    double frameSize;
    double frameSize_h;
    double frameSize_v;
    // private methods
    Vec3f getPlaneVectorX(int xcoord);
    Vec3f getPlaneVectorY(int ycoord);
    Vec3f getPlaneVector(int xcoord, int ycoord);

public:
    // public methods
    CameraPerspective(int _framePixelsX, int _framePixelsY, Vec3f _originPoint, Vec3f _viewDirection, Vec3f _upDirection, double _focalLength, double _frameSize);
    
    friend std::ostream& operator << (std::ostream &os, CameraPerspective* cp)
    {
        os << "[" << "framePixelsX=" << cp->framePixelsX << ",framePixelsY=" << cp->framePixelsY << ",originPoint=" << cp->originPoint << ",viewDirection=" << cp->viewDirection << ",upDirection=" << cp->upDirection << ",focalLength=" << cp->focalLength << ",frameSize=" << cp->frameSize << "]";
        return os;
    }
    
    Vec3f getRay(int xcoord, int ycoord);
};

#endif