#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    
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
    _VideoGrabber.initGrabber(_CamWidth, _CamHeight);
    
    _VideoInverted.allocate(_CamWidth, _CamHeight, OF_PIXELS_RGB);
    _VideoTexture.allocate(_VideoInverted);
    
    
    //_pixelsMat = cv2::Mat(_CamWidth, _CamHeight, CV_16U);
    _priorImage.allocate(_CamWidth, _CamHeight);
    _currentImage.allocate(_CamWidth, _CamHeight);
    
    //_parameters.setName("Settings");
    //_parameters.add();
    //_gui.setup(_parameters);
    _gui.setup();
    _gui.add(_smoothing.set("Smoothing", 0.5, 0.0, 1.0));
    _gui.add(_gain.set("Gain", 1.0, 0.1, 100.0));
    _gui.add(_saveImage.setup("Save Image"));
    _gui.add(_fileName.set("filename.png"));
    
    
    //ofColor color = color.set("color",ofColor(127),ofColor(0,0),ofColor(255));
    //position.get()
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100, 100, 100);
    _VideoGrabber.update();
    
    if(_VideoGrabber.isFrameNew()){
        ofPixels & pixels = _VideoGrabber.getPixels();
        
        //_pixelsMat = pixels.getData();
        //_pixelsMat = _currentImage.toCC
        //cv2::addWeighted(_currentImage, 1.0f - _smoothing.get(), _priorImage, _smoothing.get(),0.0, _priorImage);
        

        if(_smoothedPixels.size() == 0)
        {
            _smoothedPixels = _VideoGrabber.getPixels();
        }
        float alpha = (1.0f - _smoothing.get());
        float beta = _smoothing.get();
        float gain = _gain.get();
        float max = 0.0f;
        for(size_t i = 0; i < _smoothedPixels.size(); i++){
            float pixelval = alpha * gain * pixels[i] + beta * _smoothedPixels[i];
            _smoothedPixels[i] = std::min(pixelval, 255.0f);
            if(_smoothedPixels[i] > max)
            {
                max = _smoothedPixels[i];
            }
            //_currentImage[i] = alpha * _priorImage[i] + beta * _currentImage[i];
        }
        ofLogNotice() << "Max Pixel: " << max;
        
        //_priorImage.setFromPixels(_currentImage.getPixels());
        _VideoTexture.loadData(_smoothedPixels);
        _currentImage.setFromPixels(_smoothedPixels);
    }
    
    if(_saveImage)
    {
        ofLogNotice() << "Saving: " << _fileName.get();
        ofImage img;
        img.setFromPixels(_currentImage.getPixels());
        img.save(_fileName.get());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);
    //_VideoGrabber.draw(20, 20);
    _VideoTexture.draw(20 , 20, _CamWidth, _CamHeight);
    //_currentImage.draw(20,20, _CamWidth, _CamHeight);
    _gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
