#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    oscSender_.setup(LOCALHOST, PORT);
    oscReceiver_.setup(PORT);
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
    
    std::stringstream countss;
    countss << "OSC count: " << count_;
    
    int ypos = 10;
    int gap = 15;
    ofDrawBitmapString(ss.str().c_str(), 10, ypos);
    
    ypos += gap;
    ofDrawBitmapString(mins.str().c_str(), 10, ypos);
    
    ypos += gap;
    ofDrawBitmapString(maxs.str().c_str(), 10, ypos);

    ypos += gap;
    ofDrawBitmapString(countss.str().c_str(), 10, ypos);
    
    ypos += gap;
    ofDrawBitmapString("press 'c' to clear min, max and count", 10, ypos);

    ypos += gap;
    ofDrawBitmapString("mouse click to send test OSC", 10, ypos);

    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, size_);
    ofPopMatrix();
    
    size_ = ofClamp(size_-0.5, 0, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'c':
            min_ = 60;
            max_ = 0;
            count_ = 0;
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
    ofxOscMessage m;
    m.setAddress("/hello");
    oscSender_.sendMessage(m);
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
        size_ += 5;
        ++count_;
    }
    
}
