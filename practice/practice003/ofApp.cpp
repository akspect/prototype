#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60.0f);
    radian0 = 0;
    radian1 = 195;
    ofSetWindowTitle("practice003");
    
}


//--------------------------------------------------------------
void ofApp::update()
{
    
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    
    ofBackground(30);
    
    if(ofGetFrameNum()% 10 == 0){
        
        radian0 += 30;
        lineControllerVector0.push_back(LineController(radian0));
        
        radian1 += 30;
        lineControllerVector1.push_back(LineController(radian1));
        
        timesVector.push_back(0);
    }
    
    for(int i = 0; i< lineControllerVector0.size(); i++){
        
        lineControllerVector0[i].draw();
        
        //データを削除
        if(lineControllerVector0[i].isDeleateflag){
            lineControllerVector0.erase(lineControllerVector0.begin() + i);
            timesVector[i] += 1;
        }
        
        
        
    }
    
    for(int i = 0; i< lineControllerVector1.size(); i++){
        
        lineControllerVector1[i].draw();
        
        //データを削除
        if(lineControllerVector1[i].isDeleateflag){
            lineControllerVector1.erase(lineControllerVector1.begin() + i);
        }
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
    
}
