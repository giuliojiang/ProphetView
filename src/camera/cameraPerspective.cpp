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
    Vec3f rightDirection = (viewDirection.cross(upDirection)).getNormalized();
    std::cout << "rightDirection calculated is: " << rightDirection << std::endl;
    
    
}
