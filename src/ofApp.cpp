#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    parseOSC();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofPushMatrix();
    ofTranslate(0,20);
    ofSetColor(255);
    float fps = ofGetFrameRate();
    
    min_ = std::min(min_, fps);
    max_ = std::max(max_, fps);
    
    std::stringstream ss;
    ss << "fps=" << fps;
    
    std::stringstream mins;
    mins << "min: " << min_;
    
    std::stringstream maxs;
    maxs << "max: " << max_;
    
    ofDrawBitmapString(ss.str().c_str(), 10, 10);
    ofDrawBitmapString(mins.str().c_str(), 10, 25);
    ofDrawBitmapString(maxs.str().c_str(), 10, 40);
    ofDrawBitmapString("press 'c' to clear min and max", 10, 55);
    

    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'c':
            min_ = 60;
            max_ = 0;
            break;
            
        default:
            break;
    }
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

void ofApp::parseOSC() {
    while (oscReceiver_.hasWaitingMessages()) {
        ofxOscMessage m;
        oscReceiver_.getNextMessage(m);
    }
    
}
