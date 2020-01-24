#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    _camera.Setup();
    
    _gui.InitializeGUI(_camera);
    _camera.UpdateSettings(_gui.GetSettings());
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    _gui.Update();
    _camera.UpdateSettings(_gui.GetSettings());
    _camera.Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(100, 100, 100);
    ofSetHexColor(0xffffff);
    _camera.Render();
    _gui.Render();
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
