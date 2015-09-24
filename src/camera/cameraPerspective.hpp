#ifndef CAMERA_PERSPECTIVE_H
#define CAMERA_PERSPECTIVE_H

#include "geometry/vec3.hpp"

class CameraPerspective
{
private:
    // class members
    int framePixelsX;
    int framePixelsY;
    Vec3f originPoint;
    Vec3f viewDirection;
    Vec3f upDirection;
    double focalLength;
    double frameSize;
    // private methods
public:
    // public methods
    CameraPerspective(int _framePixelsX, int _framePixelsY, Vec3f _originPoint, Vec3f _viewDirection, Vec3f _upDirection, double _focalLength, double _frameSize);
    
    friend std::ostream& operator << (std::ostream &os, CameraPerspective* cp)
    {
        os << "[" << "framePixelsX=" << cp->framePixelsX << ",framePixelsY=" << cp->framePixelsY << ",originPoint=" << cp->originPoint << ",viewDirection=" << cp->viewDirection << ",upDirection=" << cp->upDirection << ",focalLength=" << cp->focalLength << ",frameSize=" << cp->frameSize << "]";
        return os;
    }
};

#endif