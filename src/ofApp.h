#pragma once

#include "ofMain.h"
#include "ofxOSC.h"

#define LOCALHOST "localhost"
#define PORT 24080

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

    void parseOSC();
    ofxOscReceiver oscReceiver_;
    ofxOscSender oscSender_;
    float min_ = 60;
    float max_ = 0;
    uint64_t count_ = 0;
    
    float size_ = 0;
};
