#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"
#include "opencv.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    private:
        // Camera Feed
        ofVideoGrabber _VideoGrabber;
        ofPixels _VideoInverted;
        ofTexture _VideoTexture;
        const int _CamWidth = 640;
        const int _CamHeight = 480;
    
        ofxCvColorImage _priorImage;
        ofxCvColorImage _currentImage;
        ofPixels _smoothedPixels;
        //cv2::Mat _pixelsMat;
    //GUI:
        ofxPanel _gui;
        ofParameter<float> _smoothing;
        ofParameter<float> _gain;
        ofParameter<std::string> _fileName;
        ofxButton _saveImage;
        ofParameterGroup _parameters;
    
};
