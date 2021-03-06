//
//  Camera.cpp
//  MicroscopeView
//
//  Created by Ben Lucas on 1/23/20.
//

#include "Camera.hpp"


void Camera::Setup()
{
    //get back a list of devices.
    vector<ofVideoDevice> devices = _VideoGrabber.listDevices();
    
    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    _VideoGrabber.setDeviceID(0);
    _VideoGrabber.setDesiredFrameRate(30);
    
    _VideoGrabber.initGrabber(CAM_WIDTH, CAM_HEIGHT);
    
    _VideoTexture.allocate(CAM_WIDTH, CAM_HEIGHT, OF_PIXELS_RGB);
    
    _currentImage.allocate(CAM_WIDTH, CAM_HEIGHT);
}

void Camera::Update()
{
    _VideoGrabber.update();
    
    if(_VideoGrabber.isFrameNew()){
        ofPixels & pixels = _VideoGrabber.getPixels();
        if(_smoothedPixels.size() == 0)
        {
            _smoothedPixels = _VideoGrabber.getPixels();
        }
        float alpha = (1.0f - _settings->smoothing);
        float beta = _settings->smoothing;
        float gain;// = _settings->gain;
        for(size_t i = 0; i < _smoothedPixels.size(); i++){
            gain = CalculateGain(i % 3);
            float pixelval = alpha * gain * pixels[i] + beta * _smoothedPixels[i];
            _smoothedPixels[i] = std::min(pixelval, 255.0f);
        }
        //_VideoTexture.loadData(_smoothedPixels);
        _currentImage.setFromPixels(_smoothedPixels);
    }
}

void Camera::Render()
{
    _currentImage.draw(20 , 20, CAM_WIDTH, CAM_HEIGHT);
    //_VideoTexture.draw(20 , 20, _CamWidth, _CamHeight);
}

void Camera::UpdateSettings(CameraSettings settings)
{
    _settings = & settings;
}

ofPixels Camera::GetPixels()
{
    return _smoothedPixels;
}

void Camera::SaveImage(std::string filename)
{
    ofImage img;
    img.setFromPixels(_currentImage.getPixels());
    img.save(filename);
}

float Camera::CalculateGain(int channel)
{
    float gain;
    if(channel == 0)
    {
        gain = _settings->gain * _settings->r;
    }
    else if (channel == 1)
    {
        gain = _settings->gain * _settings->g;
    }
    else
    {
        gain = _settings->gain * _settings->b;
    }
    return gain;
}
