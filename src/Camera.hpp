//
//  Camera.hpp
//  MicroscopeView
//
//  Created by Ben Lucas on 1/23/20.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "CameraSettings.hpp"
#include <stdio.h>
#include "ofxOpenCv.h"
#include "opencv.hpp"

class Camera
{
public:
    Camera(){}
    
    void Setup();
    
    void Update();
    
    void Render();
    
    void UpdateSettings(CameraSettings settings);
    
    ofPixels GetPixels();
    
private:
    const int _CamWidth = 640;
    const int _CamHeight = 480;
    
    CameraSettings _settings;
    
    ofVideoGrabber _VideoGrabber;

    ofPixels _smoothedPixels;

    ofTexture _VideoTexture;

    ofxCvColorImage _currentImage;
};


#endif /* Camera_hpp */
