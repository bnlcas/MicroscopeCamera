//
//  SettingsGUI.hpp
//  MicroscopeView
//
//  Created by Ben Lucas on 1/23/20.
//

#ifndef SettingsGUI_hpp
#define SettingsGUI_hpp

#include <stdio.h>
#include "ofxGui.h"
#include "Camera.hpp"
#include "CameraSettings.hpp"

class SettingsGUI
{
public:
    SettingsGUI(){};

    void InitializeGUI(Camera camera);
    
    void Update();
    
    void Render();
    
    CameraSettings GetSettings();
    
private:
    ofxPanel _gui;
    
    ofParameter<float> _smoothing;
    ofParameter<float> _gain;
    ofParameter<float> _redBalance;
    ofParameter<float> _greenBalance;
    ofParameter<float> _blueBalance;
    
    ofParameter<std::string> _fileName;
    ofxButton _saveImage;
    ofParameterGroup _parameters;
    
    Camera * _camera;
    
    CameraSettings _settings;
};

#endif /* SettingsGUI_hpp */
