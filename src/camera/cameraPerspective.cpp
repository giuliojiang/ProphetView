#include "camera/cameraPerspective.hpp"

CameraPerspective::CameraPerspective(int _framePixelsX, int _framePixelsY, Vec3f _originPoint, Vec3f _viewDirection, Vec3f _upDirection, double _focalLength, double _frameSize)
{
    framePixelsX = _framePixelsX;
    framePixelsY = _framePixelsY;
    originPoint = _originPoint;
    viewDirection = _viewDirection;
    upDirection = _upDirection;
    focalLength = _focalLength;
    frameSize = _frameSize;
    
    // calculate the Right direction vector
    // Right = norm ( view X up )
    rightDirection = (viewDirection.cross(upDirection)).getNormalized();
    std::cout << "rightDirection calculated is: " << rightDirection << std::endl;

    // calculate actual frame size
    double alpha = atan(framePixelsY/framePixelsX);
    std::cout << "tan=" << framePixelsY/framePixelsX << std::endl;
    std::cout << "alpha=" << alpha << std::endl;
    frameSize_h = frameSize * cos(alpha);
    frameSize_v = frameSize * sin(alpha);
    
    std::cout << "framesize_h=" << frameSize_h << std::endl;
    std::cout << "framesize_v=" << frameSize_v << std::endl;
}

// GETX PLANE VECTOR
Vec3f CameraPerspective::getPlaneVectorX(int xcoord)
{
    double intensity = xcoord - (framePixelsX / 2);
    intensity *= frameSize_h / framePixelsX;
    return rightDirection * intensity;
}

// GETY PLANE VECTOR
Vec3f CameraPerspective::getPlaneVectorY(int ycoord)
{
    double intensity = (framePixelsY / 2) - ycoord;
    intensity *= frameSize_v / framePixelsY;
    return upDirection * intensity;
}

// GET PLANE VECTOR
Vec3f CameraPerspective::getPlaneVector(int xcoord, int ycoord)
{
    return getPlaneVectorX(xcoord) + getPlaneVectorY(ycoord);
}

// GET CAMERA RAY
Vec3f CameraPerspective::getRay(int xcoord, int ycoord)
{
    std::cout << "got xcoord " << xcoord << " and ycoord " << ycoord << std::endl;
    return ((viewDirection * focalLength) + getPlaneVector(xcoord, ycoord)).getNormalized();
}