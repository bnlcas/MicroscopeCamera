//
//  SettingsGUI.cpp
//  MicroscopeView
//
//  Created by Ben Lucas on 1/23/20.
//

#include "SettingsGUI.hpp"


void SettingsGUI::InitializeGUI(Camera camera)
{
    _camera = & camera;
    _gui.setup();
    _gui.add(_smoothing.set("Smoothing", 0.5, 0.0, 1.0));
    _gui.add(_gain.set("Gain", 1.0, 0.1, 10.0));
    _gui.add(_redBalance.set( "Red Intensity", 1.0, 0.5,2.0));
    _gui.add(_greenBalance.set( "Green Intensity", 1.0, 0.5,2.0));
    _gui.add(_blueBalance.set( "Blue Intensity", 1.0, 0.5,2.0));
    _gui.add(_saveImage.setup("Save Image"));
    _gui.add(_fileName.set("filename.png"));
    
    //_settings.gain = _gain.get();
    //_settings.r = _redBalance.get();
    //_settings.g =  _greenBalance.get();
    //_settings.b =  _blueBalance.get();
    //_settings.smoothing =  _smoothing.get();
    //_settings = { _gain.get(), _redBalance.get(), _greenBalance.get(), _blueBalance.get(), _smoothing.get()};
    UpdateSettings();
}

void SettingsGUI::Update()
{
    UpdateSettings();
    if(_saveImage)
    {
        ofLogNotice() << "Saving: " << _fileName.get();
        _camera->SaveImage(_fileName.get());
    }
}

void SettingsGUI::Render()
{
    _gui.draw();
}

CameraSettings SettingsGUI::GetSettings()
{
    return _settings;
}

void SettingsGUI::UpdateSettings()
{
    _settings.gain = _gain.get();
    _settings.r = _redBalance.get();
    _settings.g = _greenBalance.get();
    _settings.b = _blueBalance.get();
    _settings.smoothing = _smoothing.get();
}
