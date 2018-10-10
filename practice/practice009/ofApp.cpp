#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::init(){
    
    num = 10;
    for(int i=0; i<=num; i++){
        Lines.push_back(LineManager());
    }
}


//--------------------------------------------------------------
void ofApp::setup(){
    

    ofBackground(150);
    ofSetFrameRate(60);
    ofSetWindowShape(1280, 720);
    

    init();


}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0; i<=num; i++){
        Lines[i].update();
    }
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,50);
    for(int i=0; i<=num; i++){
        Lines[i].draw();
    }

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'q'){
        ofSetColor(150);
        Lines.clear();
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        init();

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
