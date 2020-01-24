//
//  Camera.hpp
//  MicroscopeView
//
//  Created by Ben Lucas on 1/23/20.
//

#ifndef Camera_hpp
#define Camera_hpp
#define CAM_WIDTH 640
#define CAM_HEIGHT 480

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
    
    void SaveImage(std::string filename);
    
private:

    
    CameraSettings * _settings;
    
    ofVideoGrabber _VideoGrabber;

    ofPixels _smoothedPixels;

    ofTexture _VideoTexture;

    ofxCvColorImage _currentImage;
    
    float CalculateGain(int channel);
};


#endif /* Camera_hpp */
