#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(1200, 720);
    ofBackground(0);
    
    
    radius = 300;
    int count = 1;
    
    cam.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    
    for(int i = 0; i < count; i++){
        spheres.push_back(Sphere());
        ofColor color = ofColor(ofRandom(100,255),ofRandom(100,255),ofRandom(100,255));
        spheres[i].setup(radius, i*30, radius, color);//半径、中心位置、meshの個数、色
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    for(int i =0; i< spheres.size(); i++){
        spheres[i].update();
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    glEnable(GL_POINT_SMOOTH);
    
    cam.begin();
    ofRotate(ofGetSystemTime()/10, 0, 1, 1);
    for(int i = 0; i< spheres.size(); i++){
        spheres[i].draw();
    }
    
    cam.end();
    
    
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
